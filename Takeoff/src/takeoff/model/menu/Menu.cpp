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
#include <KDE/KSycoca>
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


// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

Menu::Menu()
{
    // Subscribe to the changes in the menu (new application instaled, etc)
    connect(KSycoca::self(), SIGNAL(databaseChanged(QStringList)),
            this, SLOT(checkReloadMenu(QStringList)));

    // Load the menu
    this->loadMenu();
}


// ************************************************************************** //
// **********                    PRIVATE SLOTS                     ********** //
// ************************************************************************** //

void Menu::checkReloadMenu(const QStringList &changes)
{
    // Check http://api.kde.org/4.7-api/kdelibs-apidocs/kdecore/html/
    //       classKStandardDirs.html#_details
    if (changes.contains("apps")) {
        // Reset the model
        this->categoriesApplications.clear();
        this->allApplications.clear();
        this->categories.clear();

        // Reload the model and send the corresponding signal
        this->loadMenu();
        emit this->changed();
    }
}


// ************************************************************************** //
// **********                   PRIVATE METHODS                    ********** //
// ************************************************************************** //

void Menu::loadMenu()
{
    KServiceGroup::Ptr root = KServiceGroup::group(QString());

    if (!root || !root->isValid())
        qFatal("Error loading xdg-menu");

    const KServiceGroup::List list = root->entries(
            true,   // Sorted
            true,   // Exclude no display entries
            false,  // Don't allow separators
            true ); // Sort by generic name

    // List with the launcher to add to the "Other Applications" category
    QList<Takeoff::Launcher> otherApplications;

    for (KServiceGroup::List::ConstIterator it=list.constBegin();
            it != list.constEnd(); it++) {
        const KSycocaEntry::Ptr p = (*it);

        // Category
        if (p->isType(KST_KServiceGroup)) {
            const KServiceGroup::Ptr group = KServiceGroup::Ptr::staticCast(p);

            if (group->noDisplay() || group->childCount() == 0)
                continue;

            // Create the category and save  the applications
            this->createCategory(group->caption(), group->icon());
            this->saveApplications(group->relPath(),
                    this->categories.length()-1);

        // If a launcher is detected here is because is a launcher without
        // category. Is necesary add it to the "Other Aplications" category
        } else if (p->isType(KST_KService)) {
            const KService::Ptr service = KService::Ptr::staticCast(p);

            if (service->noDisplay())
                continue;

            Takeoff::Launcher launcher(
                    KIcon(service->icon()),
                    service->name(),
                    service->genericName(),
                    service->entryPath());

            if (!otherApplications.contains(launcher)) {
                otherApplications.append(launcher);
            }
        }
    }

    // If is necesary add the "Other Applications" category
    if (!otherApplications.isEmpty()) {
        // Create the Other Applications category
        this->createCategory(i18n("Other Applications"), "applications-other");

        // Add the launchers
        foreach (Takeoff::Launcher launcher, otherApplications) {

            if (!allApplications.contains(launcher)) {
                this->allApplications.append(launcher);
            }

            int categoryIndex = this->categories.length()-1;
            QList<Takeoff::Launcher> aux =
                    this->categoriesApplications.at(categoryIndex);
            aux.append(launcher);
            this->categoriesApplications.replace(categoryIndex, aux);
        }
    }
}

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
                    service->genericName(),
                    service->entryPath());

            if (!this->allApplications.contains(launcher)) {
                this->allApplications.append(launcher);
            }

            QList<Takeoff::Launcher> aux =
                    this->categoriesApplications.at(categoryIndex);
            if (!aux.contains(launcher)) {
                aux.append(launcher);
                this->categoriesApplications.replace(categoryIndex, aux);
            }
        }
    }
}

void Menu::createCategory(const QString &name, const QString &icon)
{
    // Save the category
    QPair<QString, KIcon> category;
    category.first  = name;
    category.second = KIcon(icon);
    this->categories.append(category);

    // Add the category to the categoriesApplications list
    QList<Takeoff::Launcher> l;
    this->categoriesApplications.append(l);
}


// ************************************************************************** //
// **********                      GET/SET/IS                      ********** //
// ************************************************************************** //

const QList<Takeoff::Launcher> &Menu::getAllApplications() const
{
    return this->allApplications;
}

const QList< QPair<QString, KIcon> > &Menu::getCategories() const
{
    return this->categories;
}

const QList<Takeoff::Launcher> &Menu::getCategoriesApplications(
        int categoryIndex) const
{
    return this->categoriesApplications.at(categoryIndex);
}
