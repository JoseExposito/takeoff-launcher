/**
 * @file /src/takeoff/takeoff_widget/Launcher.cpp
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
 * @class  Takeoff::Launcher
 */
#include "Launcher.h"
#include <QtGui/QGraphicsLinearLayout>
#include <QtGui/QGraphicsSceneMouseEvent>
#include <QtGui/QMenu>
#include <KDE/KRun>
#include <KDE/Plasma/IconWidget>
#include <KDE/Plasma/ToolTipContent>
#include <KDE/Plasma/ToolTipManager>
#include <KDE/KIcon>
#include "../../model/config/Config.h"
#include "../../model/favorites/Favorites.h"
#include "../../model/krunner/KRunner.h"
using namespace Takeoff;

// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

Launcher::Launcher(const QIcon &icon, const QString &name,
        const QString &description, const QString &desktopFile)
        : icon(icon),
          name(name),
          description(description),
          desktopFile(desktopFile)
{
    this->init();
}

Launcher::Launcher(const Launcher &launcher)
        : QGraphicsWidget(),
          icon(launcher.icon),
          name(launcher.name),
          description(launcher.description),
          desktopFile(launcher.desktopFile)
{
    this->init();
}


// ************************************************************************** //
// **********                  OVERLOAD OPERATORS                  ********** //
// ************************************************************************** //

Launcher &Launcher::operator = (const Launcher& launcher)
{
    this->icon        = launcher.icon;
    this->name        = launcher.name;
    this->description = launcher.description;
    this->desktopFile = launcher.description;
    return *this;
}

bool Launcher::operator == (const Launcher& launcher)
{
    return this->desktopFile == launcher.desktopFile;
}


// ************************************************************************** //
// **********                   PRIVATE METHODS                    ********** //
// ************************************************************************** //

void Launcher::init()
{
    // Set the icon
    Plasma::IconWidget *icon = new Plasma::IconWidget(this->icon, "", this);

    Config *cfg = Config::getInstance();
    if (cfg->getSettings(Config::SHOW_ICON_TEXT).toBool())
        icon->setText(this->name);

    icon->setMinimumSize(cfg->getSettings(Config::LAUNCHER_SIZE).toInt(),
            cfg->getSettings(Config::LAUNCHER_SIZE).toInt());
    icon->setMaximumSize(cfg->getSettings(Config::LAUNCHER_SIZE).toInt(),
            cfg->getSettings(Config::LAUNCHER_SIZE).toInt());
    connect(icon, SIGNAL(clicked()), this, SLOT(runApplication()));

    // Set the tooltip
    Plasma::ToolTipContent data;
    data.setMainText(this->name);
    data.setSubText(this->description);
    data.setImage(this->icon.pixmap(32, 32));
    Plasma::ToolTipManager::self()->setContent(icon, data);

    // Add the icon to the layout
    QGraphicsLinearLayout *l = new QGraphicsLinearLayout(this);
    l->addItem(icon);
    this->setLayout(l);
}


// ************************************************************************** //
// **********                    PUBLIC SLOTS                      ********** //
// ************************************************************************** //

void Launcher::runApplication() const
{
    KRunner *krunner = KRunner::getInstance();
    krunner->runLauncher(*this);
}


// ************************************************************************** //
// **********                    PRIVATE SLOTS                     ********** //
// ************************************************************************** //

void Launcher::addToFavorites() const
{
    Favorites *favorites = Favorites::getInstance();
    favorites->addToFavorites(*this);
}

void Launcher::removeFromFavorites() const
{
    Favorites *favorites = Favorites::getInstance();
    favorites->removeFromFavorites(*this);
}


// ************************************************************************** //
// **********                    PUBLIC METHODS                    ********** //
// ************************************************************************** //

void Launcher::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        QMenu menu;

        Favorites *favorites = Favorites::getInstance();
        if (favorites->isFavorite(*this)) {
            menu.addAction(KIcon("list-remove"), i18n("Remove from favorites"),
                    this, SLOT(removeFromFavorites()));
        } else {
            menu.addAction(KIcon("favorites"), i18n("Add to favorites"),
                    this, SLOT(addToFavorites()));
        }

        menu.exec(QCursor::pos());
    }
}


// ************************************************************************** //
// **********                      GET/SET/IS                      ********** //
// ************************************************************************** //

QIcon Launcher::getIcon() const
{
    return this->icon;
}

QString Launcher::getName() const
{
    return this->name;
}

QString Launcher::getDescription() const
{
    return this->description;
}

QString Launcher::getDesktopFile() const
{
    return this->desktopFile;
}
