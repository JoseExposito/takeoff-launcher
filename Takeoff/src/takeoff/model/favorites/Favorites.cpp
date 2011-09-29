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
#include <KDE/KIcon>

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
    QStringList launcherDescriptions =
        settings.value("Favorites/FavoriteURLs").toStringList();

    // Get the list of all application
    foreach(const QString &launcherDescription, launcherDescriptions) {
        QStringList parts = launcherDescription.split("#");
        if (parts.length() != 4)
            continue;

        QString icon = parts.at(0);
        QString name = parts.at(1);
        QString description = parts.at(2);
        QString url = parts.at(3);

        Takeoff::Launcher launcher(KIcon(icon), name, description, url);
        this->favoritesList.append(launcher);
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
        QString launcherInfo = l.getIcon().name() + "#" + l.getName() + "#"
                + l.getDescription() + "#" + l.getDesktopFile();
        aux.append(launcherInfo);
    }

    settings.setValue("Favorites/FavoriteURLs", aux);
}
