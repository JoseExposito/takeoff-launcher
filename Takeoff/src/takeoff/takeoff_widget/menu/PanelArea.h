/**
 * @file /src/takeoff/takeoff_widget/menu/PanelArea.h
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
 * @class  TakeoffPrivate::PanelArea
 */
#ifndef TAKEOFFWIDGET_PARTS_PANELAREA_H
#define TAKEOFFWIDGET_PARTS_PANELAREA_H

#include <QtGui/QGraphicsWidget>
namespace Takeoff { class Launcher; }
namespace TakeoffPrivate { class PanelSelector; }
namespace Plasma  { class TabBar; }
namespace TakeoffPrivate {

/**
 * Widget that contains one or more panels. The panels are responsible of show
 * the launchers, if a panel is complete (not allow to show more launchers) the
 * panel area will add to itself other panel to show more launchers and provide
 * a method and animations to change between panels.
 */
class PanelArea : public QGraphicsWidget
{

public:

    /**
     * Default constructor.
     * @param parent Parent of the widget.
     */
    PanelArea(QGraphicsWidget *parent = 0);

    //--------------------------------------------------------------------------

    /**
     * Adds a new launcher to the end of the current Panel. If the current Panel
     * is full, adds a new Panel to add the Launcher.
     * @param launcher The launcher to add.
     */
    void addLauncher(Takeoff::Launcher *launcher);

private:

    /// TabBar with all the Panels managed by the PanelArea.
    Plasma::TabBar *panelTabBar;

    /// TabBar to HACK the problem with the place of Plasma::TabBar
    Plasma::TabBar *panelSelector;

};

}      // End namespace
#endif // TAKEOFFWIDGET_PARTS_PANELAREA_H
