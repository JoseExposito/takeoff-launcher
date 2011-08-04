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
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QSettings>
#include <QtCore/QLocale>
#include <KDE/KIcon>
#include <KDE/KStandardDirs>

// ************************************************************************** //
// **********             STATIC METHODS AND VARIABLES             ********** //
// ************************************************************************** //

QList<Takeoff::Launcher*> Favorites::favorites()
{
    QString favoritesFile = KStandardDirs::locate("config", "kickoffrc");
    QSettings settings(favoritesFile, QSettings::IniFormat);
    QStringList desktopFiles =
            settings.value("Favorites/FavoriteURLs").toStringList();

    QList<Takeoff::Launcher*> ret;
    foreach (const QString &file, desktopFiles) {
        QSettings desktop(file, QSettings::IniFormat);

        // Name of the application (with internatilatization)
        QString completeLocale = QLocale::system().name(); // For example es_ES
        QString simpleLocale   = completeLocale.split("_").at(0); // and es

        QString appName = desktop.value(
                "Desktop Entry/Name[" + completeLocale + "]", "").toString();
        if (appName.isEmpty())
            appName = desktop.value(
                    "Desktop Entry/Name[" + simpleLocale + "]", "").toString();
        if (appName.isEmpty())
            appName = desktop.value("Desktop Entry/Name").toString();

        // Create the launcher and it to the list
        Takeoff::Launcher *launcher = new Takeoff::Launcher(KIcon(
                desktop.value("Desktop Entry/Icon").toString()), appName, file);
        ret.append(launcher);
    }

    return ret;
}
