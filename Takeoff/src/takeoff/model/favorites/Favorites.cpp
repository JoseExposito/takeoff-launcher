/**
 * @file /src/takeoff/model/Favorites.cpp
 *
 * This file is part of Takeoff.
 *
 * Takeoff is free software:  you can redistribute it and/or modify it under the
 * terms of the GNU General Public License  as  published by  the  Free Software
 * Foundation,  either version 3 of the License,  or (at your option)  any later
 * version.
 *
 * Takeoff is distributed in  the hope that it will be useful,  but  WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the  GNU General Public License  for more details.
 *
 * You should have received a copy of the  GNU General Public License along with
 * Takeoff. If not, see <http://www.gnu.org/licenses/>.
 *
 * @author José Expósito <jose.exposito89@gmail.com> (C) 2011
 * @class  Favorites
 */
#include "Favorites.h"
#include <QtCore/QSettings>
#include <KDE/KStandardDirs>
#include "../menu/Menu.h"

// ************************************************************************** //
// **********             STATIC METHODS AND VARIABLES             ********** //
// ************************************************************************** //

Favorites *Favorites::instance = NULL;

Favorites *Favorites::getInstance()
{
    if (Favorites::instance == NULL)
        Favorites::instance = new Favorites();

    return Favorites::instance;
}


// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

Favorites::Favorites()
{
    // Get the favorites URLs
    QString favoritesFile = KStandardDirs::locate("config", "takeoffrc");
    QSettings settings(favoritesFile, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    QStringList desktopFiles =
            settings.value("Favorites/FavoriteURLs").toStringList();

    // Get the list of all application
    Menu *menu = Menu::getInstance();
    const QList<Takeoff::Launcher> allApps = menu->getAllApplications();

    // Search in the applications list the favorites
    foreach (const QString &desktopFile, desktopFiles) {
        foreach (Takeoff::Launcher launcher, allApps) {
            if (launcher.getDesktopFile() == desktopFile) {
                this->favoritesList.append(launcher);
                break;
            }
        }
    }

}


// ************************************************************************** //
// **********                    PUBLIC METHODS                    ********** //
// ************************************************************************** //

const QList<Takeoff::Launcher> &Favorites::getFavorites() const
{
    return this->favoritesList;
}

void Favorites::addToFavorites(const Takeoff::Launcher launcher)
{
    this->favoritesList.append(launcher);
    this->saveFavorites();
    emit this->changed();
}

void Favorites::removeFromFavorites(const Takeoff::Launcher launcher)
{
    this->favoritesList.removeAll(launcher);
    this->saveFavorites();
    emit this->changed();
}

bool Favorites::isFavorite(const Takeoff::Launcher launcher) const
{
    return this->favoritesList.contains(launcher);
}


// ************************************************************************** //
// **********                   PRIVATE METHODS                    ********** //
// ************************************************************************** //

void Favorites::saveFavorites() const
{
    QString favoritesFile = KStandardDirs::locate("config", "takeoffrc");
    QSettings settings(favoritesFile, QSettings::IniFormat);

    QStringList aux;
    for (int n=0; n<this->favoritesList.length(); n++) {
        Takeoff::Launcher l = this->favoritesList.at(n);
        aux.append(l.getDesktopFile());
    }

    settings.setValue("Favorites/FavoriteURLs", aux);
}
