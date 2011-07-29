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
#include <QtCore/QProcess>
#include <QtGui/QGraphicsLinearLayout>
using namespace Takeoff;

// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

Launcher::Launcher(const QIcon &icon, const QString &name,
        const QString &command)
        : Plasma::IconWidget(icon, name)
{
    // TODO Problems with some commands, for example
    //      $ chromium localhost/phpmyadmin
    this->command = command.split(" ").at(0);
}


// ************************************************************************** //
// **********                    PUBLIC METHODS                    ********** //
// ************************************************************************** //

void Launcher::mousePressEvent(QGraphicsSceneMouseEvent */*event*/)
{
    emit this->pressed(true);
    QProcess myProcess;
    myProcess.startDetached(this->command);
}
