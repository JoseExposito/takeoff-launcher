/**
 * @file /src/takeoff/takeoff_widget/TakeoffWidget.h
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
 * @class  Takeoff::TakeoffWidget
 */
#ifndef TAKEOFFWIDGET_TAKEOFFWIDGET_H
#define TAKEOFFWIDGET_TAKEOFFWIDGET_H

#include <QtGui/QGraphicsWidget>
class QGraphicsLinearLayout;
namespace Plasma  { class TabBar; }
namespace Takeoff { class Launcher; }
namespace Takeoff {

/**
 * A widget with the public interface of Takeoff. Is composed for many sub
 * widgets located in /parts.
 */
class TakeoffWidget : public QGraphicsWidget
{

public:

    /**
     * Default constructor.
     * @param parent Parent of the widget.
     */
    TakeoffWidget(QGraphicsWidget *parent = 0);

    //--------------------------------------------------------------------------

    /**
     * Adds a new tab with the specified icon and title.
     * @param icon  The icon that will appear at the left of the title. Pass a
     *        null-icon to not display icon.
     * @param title The text to display next to the icon.
     */
    void addTab(const QIcon &icon, const QString &title);

    /**
     * Adds a new launcher to the specified tab. If the index is incorrect or
     * the launcher is NULL it won't effect.
     * @param tabIndex The index of the tab where the launcher will be added.
     * @param launcher The launcher to add.
     */
    void addLauncher(int tabIndex, Launcher *launcher);

    //--------------------------------------------------------------------------

    /**
     * Returns the count of tabs.
     * @return The count.
     */
    int getNumTabs() const;

    /**
     * Returns the current displayed tab.
     * @return The current displayed tab.
     */
    int getCurrentIndex() const;

    /**
     * Sets the current index.
     * @param index The index.
     */
    void setCurrentIndex(int index);

    /**
     * Removes all the panels and launchers.
     */
    void reset();

private:

    /// Bar with the different categories.
    Plasma::TabBar *tabBar;

    /// Layout to add the different items.
    QGraphicsLinearLayout *tLayout;

};

}      // End namespace
#endif // TAKEOFFWIDGET_TAKEOFFWIDGET_H
