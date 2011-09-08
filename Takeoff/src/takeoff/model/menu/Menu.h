/**
 * @file /src/takeoff/model/Menu.h
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
 * @class  Menu
 */
#ifndef MODEL_MENU_H
#define MODEL_MENU_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QPair>
#include <KDE/KIcon>
#include "../../view/takeoff_widget/Launcher.h"

/**
 * Class to access to the xdg-menu standard. Is a singleton, the only way to get
 * an instance of the class is call to the getInstance() method:
 *
 * Menu *menu = Menu::getInstance();
 *
 * Provides methods to access to the menu launchers: getAllApplications(),
 * getCategories() and getCategoriesApplications() and emit the changed() signal
 * when the menu changes, for example an application is added, the user
 * modifieds the menu with KMenuEdit...
 */
class Menu : public QObject
{
    Q_OBJECT

public:

    /**
     * Only method to get an instance of the class.
     * @return The single instance of the class.
     */
    static Menu* getInstance();

    //--------------------------------------------------------------------------

    /**
     * Returns the a list with all the available applications.
     * @return The list.
     */
    const QList<Takeoff::Launcher> &getAllApplications() const;

    /**
     * Returns a list with all the categories, identified by the pair name and
     * icon.
     * @return The list.
     */
    const QList< QPair<QString, KIcon> > &getCategories() const;

    /**
     * Returns a list with all applications belonging to the specified category.
     * @param  categoryIndex The position of the category in the getCategories()
     *         list.
     * @return The list.
     */
    const QList<Takeoff::Launcher> &getCategoriesApplications(int categoryIndex)
            const;

signals:

    /**
     * Emitted whenever the model changes.
     */
    void changed();

private slots:

    /**
     * Checks if is necessary reload the menu when KSycoca changes.
     * @param changes The chages in the KSycoca.
     */
    void checkReloadMenu(const QStringList &changes);

private:

    /**
     * Loads the menu in the lists.
     */
    void loadMenu();

    /**
     * Auxiliary function to save the launchers in the allApplications and
     * categoriesApplications lists used from loadMenu().
     * @param path          The path of the category to save.
     * @param categoryIndex The index of the category where save the launcher.
     */
    void saveApplications(const QString &path, int categoryIndex);

    /**
     * Creates a category, the entries shown in the top tab bar.
     * @param name The name to display.
     * @param icon The icon to display.
     */
    void createCategory(const QString &name, const QString &icon);

    //--------------------------------------------------------------------------

    /// List with all applications.
    QList<Takeoff::Launcher> allApplications;

    /// List with all categories (name and icon).
    QList< QPair<QString, KIcon> > categories;

    /// List with all applications belonging to one category.
    QList< QList<Takeoff::Launcher> > categoriesApplications;

    //--------------------------------------------------------------------------

    /// Single instance of the class.
    static Menu* instance;

    // Hide constructors
    Menu();
    Menu(const Menu&);
    const Menu &operator = (const Menu&);

};

#endif // MODEL_MENU_H
