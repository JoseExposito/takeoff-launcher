/**
 * @file /src/takeoff/takeoff_widget/Launcher.h
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
#ifndef TAKEOFFWIDGET_LAUNCHER_H
#define TAKEOFFWIDGET_LAUNCHER_H

#include <KDE/Plasma/IconWidget>
namespace Takeoff  {

/**
 * Launcher, contains the information about name, icon, and the command to
 * launch.
 */
class Launcher : public Plasma::IconWidget
{

public:

    /**
     * Default constructor.
     * @param icon    The icon of the launcher. If a null-icon is passed Takeoff
     *        will put a default icon.
     * @param name    Name to show under the icon.
     * @param command Command to execute when the user click on the launcher.
     * @param parent  Parent of the widget.
     */
    Launcher(const QIcon &icon, const QString &name, const QString &command);

    //--------------------------------------------------------------------------

    /// Inherit from Plasma::IconWidget
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:

    /// Command to execute when the user click on the launcher.
    QString command;

};

}      // End namespace
#endif // TAKEOFFWIDGET_LAUNCHER_H
