/**
 * @file /src/takeoff/takeoff_widget/TakeoffWidget.cpp
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
#include "TakeoffWidget.h"
#include <QtGui/QGraphicsLinearLayout>
#include <KDE/Plasma/TabBar>
#include "Launcher.h"
#include "parts/PanelArea.h"
using namespace Takeoff;
using namespace TakeoffPrivate;
using namespace Plasma;

// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

TakeoffWidget::TakeoffWidget(QGraphicsWidget *parent)
        : QGraphicsWidget(parent),
          tabBar(NULL),
          tLayout(new QGraphicsLinearLayout(this))
{
    this->setLayout(this->tLayout);
    this->reset();
}


// ************************************************************************** //
// **********                    PUBLIC METHODS                    ********** //
// ************************************************************************** //

void TakeoffWidget::addTab(const QIcon &icon, const QString &title)
{
    PanelArea *panelArea = new PanelArea(this->tabBar);
    this->tabBar->addTab(icon, title, panelArea);

    // Only show categories if more than one is available
    if (this->tabBar->count() > 1)
        this->tabBar->setTabBarShown(true);
}

void TakeoffWidget::addLauncher(int tabIndex, Launcher *launcher)
{
    // Connect the launcher clicked signal with the TakeoffWidget clicked signal
    connect(launcher, SIGNAL(clicked()), this, SIGNAL(clicked()));

    // Reparent for free memory using reset()
    launcher->setParent(this->tabBar);

    // Add the launcher
    PanelArea *panelArea = (PanelArea*)this->tabBar->tabAt(tabIndex);

    if (panelArea == NULL || launcher == NULL)
        return;

    panelArea->addLauncher(launcher);
}

void TakeoffWidget::reset()
{
    delete this->tabBar;
    this->tabBar = new TabBar(this);
    this->tLayout->addItem(this->tabBar);

    // Only show categories if more than one is available
    this->tabBar->setTabBarShown(false);
}


// ************************************************************************** //
// **********                      GET/SET/IS                      ********** //
// ************************************************************************** //

int TakeoffWidget::getNumTabs() const
{
    return this->tabBar->count();
}

int TakeoffWidget::getCurrentIndex() const
{
    return this->tabBar->currentIndex();
}

void TakeoffWidget::setCurrentIndex(int index)
{
    this->tabBar->setCurrentIndex(index);
}
