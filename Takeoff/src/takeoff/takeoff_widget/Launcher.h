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

#include <QGraphicsWidget>
namespace Takeoff  {

/**
 * Launcher, contains the information about name, icon, and the command to
 * launch.
 */
class Launcher : public QGraphicsWidget //Plasma::IconWidget
{
    Q_OBJECT

public:

    /**
     * Default constructor.
     * @param icon The icon of the launcher. If a null-icon is passed Takeoff
     *        will put a default icon.
     * @param name Name to show under the icon.
     * @param desktopFile Desktop file to execute when the user click on the
     *        launcher.
     */
    Launcher(const QIcon &icon, const QString &name,
            const QString &desktopFile);

signals:

    /**
     * Signal that is emitted whenever the user click on the launcher.
     */
    void clicked() const;

private slots:

    /**
     * Runs the application when the icon is clicked.
     */
    void runApplication() const;

private:

    /// The desktop file to execute when the user click on the launcher.
    QString desktopFile;

};

}      // End namespace
#endif // TAKEOFFWIDGET_LAUNCHER_H
