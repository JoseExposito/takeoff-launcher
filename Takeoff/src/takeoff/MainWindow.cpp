/**
 * @file /src/takeoff/MainWindow.cpp
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
 * @class  MainWindow
 */
#include "MainWindow.h"
#include <QtCore/QList>
#include <QtCore/QTranslator>
#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>
#include <KDE/KIcon>
#include <KDE/KConfigDialog>
#include "takeoff_widget/TakeoffWidget.h"
#include "takeoff_widget/Launcher.h"
#include "model/qtxdg/xdgmenu.h"
#include "model/favorites/Favorites.h"
#include "config/Config.h"
#include "config/ConfigForm.h"
using namespace Plasma;
using namespace Takeoff;

// ************************************************************************** //
// **********                        OTHERS                        ********** //
// ************************************************************************** //

// Links the applet name (X-KDE-PluginInfo-Name in the desktop file) with this
// class
K_EXPORT_PLASMA_APPLET(takeoff, MainWindow)


// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

#include "model/qtxdg/xdgmenuwidget.h"
MainWindow::MainWindow(QObject *parent, const QVariantList &args)
        : Plasma::PopupApplet(parent, args),
          takeoff(new TakeoffWidget(this))
{
    // Plasmoid aspect
    this->setBackgroundHints(DefaultBackground);
    this->setAspectRatioMode(Plasma::IgnoreAspectRatio);

    this->takeoff->setMinimumWidth(QApplication::desktop()->width());
    this->takeoff->setMinimumHeight(QApplication::desktop()->height());

    // Load the configuration
    this->loadConfig();
}


// ************************************************************************** //
// **********                    PUBLIC METHODS                    ********** //
// ************************************************************************** //

QGraphicsWidget *MainWindow::graphicsWidget()
{
    this->takeoff->setCurrentIndex(0);
    return this->takeoff;
}

void MainWindow::createConfigurationInterface(KConfigDialog *parent)
{
    parent->addPage(new ConfigForm, i18n("General settings"), "start-here-kde");

    connect(parent, SIGNAL(applyClicked()), this, SLOT(loadConfig()));
    connect(parent, SIGNAL(okClicked()), this, SLOT(loadConfig()));
}


// ************************************************************************** //
// **********                    PRIVATE SLOTS                     ********** //
// ************************************************************************** //

void MainWindow::loadConfig()
{
    this->takeoff->reset();

    Config::loadConfig();
    Config *cfg = Config::getInstance();

    this->setPopupIcon(KIcon(cfg->getSettings(Config::ICON).toString()));

    if (cfg->getSettings(Config::SHOW_FAVORITES).toBool())
        this->loadFavorites();

    if (cfg->getSettings(Config::SHOW_ALL_APPLICATIONS).toBool())
        this->loadAllApplications();

    if (cfg->getSettings(Config::SHOW_XDG_MENU).toBool())
        this->loadXdgMenu();
}


// ************************************************************************** //
// **********                   PRIVATE METHODS                    ********** //
// ************************************************************************** //

void MainWindow::loadFavorites()
{
    this->takeoff->addTab(KIcon("favorites"), i18n("Favorites"));
    QList<Launcher*> favoritesList = Favorites::favorites();

    foreach (Launcher *launcher, favoritesList) {
        this->takeoff->addLauncher(this->takeoff->getNumTabs()-1, launcher);
        connect(launcher, SIGNAL(pressed(bool)), this, SLOT(hidePopup()));
    }
}

void MainWindow::loadAllApplications()
{
    QString menuFile = XdgMenu::getMenuFileName();
    XdgMenu xdgMenu;
    xdgMenu.environments() << "KDE";

    bool res = xdgMenu.read(menuFile);
    if (!res) {
        qFatal("Error loading all applications");
    }

    QDomNode rootNode = xdgMenu.xml().firstChild();
    QDomNode categorieNode = rootNode.firstChild();

    this->takeoff->addTab(KIcon("applications-other"), tr("All Applications"));

    for(categorieNode.firstChild(); !categorieNode.isNull();
            categorieNode=categorieNode.nextSibling()) {
        QDomElement categorieElem = categorieNode.toElement();
        if(categorieElem.isNull())
            continue;

        if(!categorieElem.attribute("title").isEmpty()
                && !categorieElem.attribute("title").startsWith(".")) {
            this->loadLaunchers(categorieNode.firstChild(),
                    this->takeoff->getNumTabs()-1);
        }
    }
}

void MainWindow::loadXdgMenu()
{
    QString menuFile = XdgMenu::getMenuFileName();
    XdgMenu xdgMenu;
    xdgMenu.environments() << "KDE";

    bool res = xdgMenu.read(menuFile);
    if (!res) {
        qFatal("Error loading xdg-menu");
    }

    QDomNode rootNode = xdgMenu.xml().firstChild();
    QDomNode categorieNode = rootNode.firstChild();

    for(categorieNode.firstChild(); !categorieNode.isNull();
            categorieNode=categorieNode.nextSibling()) {
        QDomElement categorieElem = categorieNode.toElement();
        if(categorieElem.isNull())
            continue;

        if(categorieElem.tagName() == "Menu"
                && !categorieElem.attribute("title").startsWith(".")) {
            // Load the categories
            this->takeoff->addTab(KIcon(categorieElem.attribute("icon")),
            categorieElem.attribute("title"));

            // Load the launchers
            this->loadLaunchers(categorieNode.firstChild(),
                    this->takeoff->getNumTabs()-1);
        }
    }
}

void MainWindow::loadLaunchers(QDomNode node, int tabIndex)
{
    for(node.firstChild(); !node.isNull(); node=node.nextSibling()) {
        QDomElement elem = node.toElement();
        if(elem.isNull())
            continue;

        // Launcher
        if(elem.tagName() == "AppLink") {
            Launcher *launcher = new Launcher(KIcon(elem.attribute("icon")),
                    elem.attribute("title"), elem.attribute("desktopFile"));
            this->takeoff->addLauncher(tabIndex, launcher);

            connect(launcher, SIGNAL(clicked()),
                    this, SLOT(hidePopup()));

        // Submenu
        } else {
            this->loadLaunchers(node.firstChild(), tabIndex);
        }
    }
}
