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
#include <KDE/KRun>
#include <KDE/Plasma/IconWidget>
#include <KDE/Plasma/ToolTipContent>
#include <KDE/Plasma/ToolTipManager>
using namespace Takeoff;

// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

Launcher::Launcher(const QIcon &icon, const QString &name,
        const QString &desktopFile)
        : icon(icon),
          name(name),
          desktopFile(desktopFile)
{
    this->init();
}

Launcher::Launcher(const Launcher &launcher)
        : QGraphicsWidget(),
          icon(launcher.icon),
          name(launcher.name),
          desktopFile(launcher.desktopFile)
{
    this->init();
}


// ************************************************************************** //
// **********                    PRIVATE SLOTS                     ********** //
// ************************************************************************** //

void Launcher::runApplication() const
{
    new KRun(KUrl(this->desktopFile), NULL);
}


// ************************************************************************** //
// **********                   PRIVATE METHODS                    ********** //
// ************************************************************************** //

void Launcher::init()
{
    // Set the icon
    // TODO Allow to show only the icon
    Plasma::IconWidget *iconWidget = new Plasma::IconWidget(
            this->icon, this->name, this);
    connect(iconWidget, SIGNAL(clicked()), this, SLOT(runApplication()));
    connect(iconWidget, SIGNAL(clicked()), this, SIGNAL(clicked()));

    // Set the tooltip
    Plasma::ToolTipContent data;
    data.setMainText(this->name);
    data.setImage(this->icon.pixmap(32, 32));
    Plasma::ToolTipManager::self()->setContent(iconWidget, data);

    // Add the icon to the layout
    QGraphicsLinearLayout *l = new QGraphicsLinearLayout(this);
    l->addItem(iconWidget);
    this->setLayout(l);
}

// ************************************************************************** //
// **********                      GET/SET/IS                      ********** //
// ************************************************************************** //

QString Launcher::getName()
{
    return this->name;
}
