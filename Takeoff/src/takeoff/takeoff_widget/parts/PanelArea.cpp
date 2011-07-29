/**
 * @file /src/takeoff/takeoff_widget/parts/PanelArea.cpp
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
#include "PanelArea.h"

//#include <QtGui/QGraphicsLinearLayout>
//{ HACK
#include <QtGui/QGraphicsGridLayout>
#include <KDE/Plasma/Label>
//}

#include <KDE/Plasma/TabBar>
#include "../Launcher.h"
#include "Panel.h"
using namespace Takeoff;
using namespace TakeoffPrivate;

// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

PanelArea::PanelArea(QGraphicsWidget *parent)
        : QGraphicsWidget(parent),
          panelTabBar(new Plasma::TabBar(this)),
          panelSelector(new Plasma::TabBar(this))
{
    // Add the first panel to the panel area
    Panel *defaultPanel = new Panel(this);
    this->panelTabBar->addTab(QString::number(this->panelTabBar->count()+1),
            defaultPanel);

    // TODO For the moment Plasma::TabBar don't allow RoundedSouth (line 183 in
    //      http://api.kde.org/4.x-api/kdelibs-apidocs/plasma/html/tabbar_8cpp_source.html)
    //      Change this in the future and remove the panelSelector

    //this->panelTabBar->setTabBarShown(false);
    //KTabBar *ktab = this->panelTabBar->nativeWidget();
    //ktab->setShape(QTabBar::RoundedSouth);

    // Set the layout
    //QGraphicsLinearLayout *l = new QGraphicsLinearLayout(this);
    //l->addItem(this->panelTabBar);
    //this->setLayout(l);

    //{
    this->panelTabBar->setTabBarShown(false);
    this->panelSelector->setTabBarShown(false);
    this->panelSelector->addTab(QString::number(this->panelTabBar->count()));
    connect(this->panelSelector, SIGNAL(currentChanged(int)),
            this->panelTabBar, SLOT(setCurrentIndex(int)));

    QGraphicsGridLayout *l = new QGraphicsGridLayout(this);
    Plasma::Label *separator1 = new Plasma::Label;
    Plasma::Label *separator2 = new Plasma::Label;

    l->setRowMaximumHeight(1, 10);
    l->addItem(this->panelTabBar, 0, 0, 1, 3);
    l->addItem(separator1, 1, 0);
    l->addItem(this->panelSelector, 1, 1);
    l->addItem(separator2, 1, 2);
    this->setLayout(l);
    //}
}


// ************************************************************************** //
// **********                    PUBLIC METHODS                    ********** //
// ************************************************************************** //

void PanelArea::addLauncher(Launcher *launcher)
{
    Panel *lastPanel = (Panel*)this->panelTabBar->tabAt(
            this->panelTabBar->count()-1);

    if (!lastPanel->isFull()) {
        lastPanel->addLauncher(launcher);

    } else {
        Panel *newPanel = new Panel(this);
        newPanel->addLauncher(launcher);
        this->panelTabBar->addTab(QString::number(this->panelTabBar->count()+1),
                newPanel);

        //this->panelTabBar->setTabBarShown(true);
        //{ HACK
        this->panelSelector->addTab(QString::number(
                this->panelTabBar->count()));

        this->panelSelector->setTabBarShown(true);
        ((QGraphicsGridLayout*)this->layout())->setColumnMaximumWidth(1,
                this->panelTabBar->count()*50);
        //}
    }
}
