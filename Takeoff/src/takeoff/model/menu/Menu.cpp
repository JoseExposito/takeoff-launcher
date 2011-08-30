/**
 * @file /src/takeoff/model/Menu.cpp
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
#include "Menu.h"
#include <KDE/KServiceGroup>
#include <KDE/KIcon>

// ************************************************************************** //
// **********             STATIC METHODS AND VARIABLES             ********** //
// ************************************************************************** //

Menu* Menu::instance = NULL;

Menu* Menu::getInstance()
{
    if (Menu::instance == NULL)
        Menu::instance = new Menu();

    return Menu::instance;
}

void Menu::loadMenu()
{
    if (instance != NULL) {
        delete instance;
        instance = NULL;
    }
    Menu::getInstance();
}



// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

Menu::Menu()
        : allApplications(new QList<Takeoff::Launcher>),
          categories(new QList< QPair<QString, KIcon>* >),
          categoriesApplications(new QList< QList<Takeoff::Launcher>* >)
{
    KServiceGroup::Ptr root = KServiceGroup::group(QString());

    if (!root || !root->isValid())
        qFatal("Error loading xdg-menu");

    const KServiceGroup::List list = root->entries(
            true,   // Sorted
            true,   // Exclude no display entries
            false,  // Don't allow separators
            true ); // Sort by generic name

    for (KServiceGroup::List::ConstIterator it=list.constBegin();
            it != list.constEnd(); it++) {
        const KSycocaEntry::Ptr p = (*it);

        // Category
        if (p->isType(KST_KServiceGroup)) {
            const KServiceGroup::Ptr group = KServiceGroup::Ptr::staticCast(p);

            if (group->noDisplay() || group->childCount() == 0)
                continue;

            // Save the category
            QPair<QString, KIcon> *category = new QPair<QString, KIcon>;
            category->first  = group->caption();
            category->second = KIcon(group->icon());
            this->categories->append(category);

            // Add the category to the categoriesApplications list
            QList<Takeoff::Launcher>* l = new QList<Takeoff::Launcher>;
            this->categoriesApplications->append(l);

            // Save the category applications
            this->saveApplications(group->relPath(),
                    this->categories->length()-1);

        // Launcher
        } else if (p->isType(KST_KService)) {

            // TODO Aquí hay que ver si hay aplicaciones sueltas y añadirlas a
            //      una categoría "Otras aplicaciones"

            /*
            const KService::Ptr service = KService::Ptr::staticCast(p);
            if (service->noDisplay())
                continue;
            qDebug() << service->name() << service->genericName()
                    << service->entryPath() << service->icon();
            */
        }
    }
}

Menu::~Menu()
{
    qDeleteAll(this->categories->begin(), this->categories->end());
    delete this->allApplications;
    delete this->categories;
    delete this->categoriesApplications;
}


// ************************************************************************** //
// **********                   PRIVATE METHODS                    ********** //
// ************************************************************************** //

void Menu::saveApplications(const QString &path, int categoryIndex)
{
    KServiceGroup::Ptr root = KServiceGroup::group(path);

    if (!root || !root->isValid())
        qFatal("Error loading xdg-menu");

    const KServiceGroup::List list = root->entries(
            true,   // Sorted
            true,   // Exclude no display entries
            false,  // Don't allow separators
            true ); // Sort by generic name

    for (KServiceGroup::List::ConstIterator it=list.constBegin();
            it != list.constEnd(); it++) {
        const KSycocaEntry::Ptr p = (*it);

        // Category
        if (p->isType(KST_KServiceGroup)) {
            const KServiceGroup::Ptr group = KServiceGroup::Ptr::staticCast(p);

            if (group->noDisplay() || group->childCount() == 0)
                continue;

            this->saveApplications(group->relPath(), categoryIndex);

        // Launcher
        } else if (p->isType(KST_KService)) {
            const KService::Ptr service = KService::Ptr::staticCast(p);

            if (service->noDisplay())
                continue;

            Takeoff::Launcher launcher(
                    KIcon(service->icon()),
                    service->name(),
                    service->entryPath());
            // service->genericName()

            this->allApplications->append(launcher);
            this->categoriesApplications->at(categoryIndex)->append(launcher);
        }
    }
}


// ************************************************************************** //
// **********                      GET/SET/IS                      ********** //
// ************************************************************************** //

QList<Takeoff::Launcher> *Menu::getAllApplications() const
{
    return this->allApplications;
}

QList< QPair<QString, KIcon>* > *Menu::getCategories() const
{
    return this->categories;
}

QList<Takeoff::Launcher> *Menu::getCategoriesApplications(int categoryIndex)
        const
{
    return this->categoriesApplications->at(categoryIndex);
}
