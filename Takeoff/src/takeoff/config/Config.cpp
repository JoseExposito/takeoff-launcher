/**
 * @file /src/takeoff/config/Config.h
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
 * @class  Config
 */
#include "Config.h"
#include <QtCore/QVariant>
#include <QtCore/QDir>
#include <QtCore/QSettings>
#include <KDE/KStandardDirs>

// ************************************************************************** //
// **********             STATIC METHODS AND VARIABLES             ********** //
// ************************************************************************** //

Config *Config::instance = NULL;

Config *Config::getInstance()
{
    if (Config::instance == NULL)
        Config::instance = new Config();

    return Config::instance;
}

void Config::loadConfig()
{
    if (instance != NULL) {
        delete instance;
        instance = NULL;
    }
    Config::getInstance();
}

const char *Config::SHOW_FAVORITES        = "Takeoff/ShowFavorites";
const char *Config::SHOW_ALL_APPLICATIONS = "Takeoff/ShowAllApplications";
const char *Config::SHOW_XDG_MENU         = "Takeoff/ShowXdgMenu";
const char *Config::LAUNCHER_SIZE         = "Takeoff/LauncherSize";
const char *Config::SEPARATION_BETWEEN_LAUNCHERS
        = "Takeoff/SeparationBetweenLaunchers";
const char *Config::NUM_ROWS              = "Takeoff/NumRows";
const char *Config::NUM_COLUMNS           = "Takeoff/NumColumns";
const char *Config::ICON                  = "Takeoff/Icon";


// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

#include <QDebug>
Config::Config()
{
    QFile configFile(this->getConfigFilePath());

    // If the configuration file doesn't exist create it
    if (!configFile.exists()) {
        configFile.open(QFile::WriteOnly);
        configFile.write(
                "[Takeoff]\n"
                "ShowFavorites=true\n"
                "ShowAllApplications=true\n"
                "ShowXdgMenu=true\n"
                "LauncherSize=60\n"
                "SeparationBetweenLaunchers=40\n"
                "NumRows=3\n"
                "NumColumns=6\n"
                "Icon=start-here-kde"
        );
        configFile.close();
    }

    // Load the configuration into the QHash
    this->settings = new QSettings(this->getConfigFilePath(),
            QSettings::IniFormat, this);

    this->hashSettings.insert(SHOW_FAVORITES,
            this->settings->value(SHOW_FAVORITES));
    this->hashSettings.insert(SHOW_ALL_APPLICATIONS,
            this->settings->value(SHOW_ALL_APPLICATIONS));
    this->hashSettings.insert(SHOW_XDG_MENU,
            this->settings->value(SHOW_XDG_MENU));
    this->hashSettings.insert(LAUNCHER_SIZE,
            this->settings->value(LAUNCHER_SIZE));
    this->hashSettings.insert(SEPARATION_BETWEEN_LAUNCHERS,
            this->settings->value(SEPARATION_BETWEEN_LAUNCHERS));
    this->hashSettings.insert(NUM_ROWS, this->settings->value(NUM_ROWS));
    this->hashSettings.insert(NUM_COLUMNS, this->settings->value(NUM_COLUMNS));
    this->hashSettings.insert(ICON, this->settings->value(ICON));
}


// ************************************************************************** //
// **********                      GET/SET/IS                      ********** //
// ************************************************************************** //

QVariant Config::getSettings(const char *propertyName) const
{
    return this->hashSettings.value(propertyName);
}

void Config::setSettings(const char *propertyName, const QVariant &value)
{
    this->settings->setValue(propertyName, value);
}

QString Config::getConfigFilePath() const
{
    return KStandardDirs::locateLocal("config", "takeoffrc", true);
}
