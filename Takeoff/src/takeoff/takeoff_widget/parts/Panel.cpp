/**
 * @file /src/takeoff/takeoff_widget/parts/Panel.cpp
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
 * @class  TakeoffPrivate::Panel
 */
#include "Panel.h"
#include <QtCore/QList>
#include <QtGui/QGraphicsGridLayout>
#include <KDE/Plasma/Label>
#include "../Launcher.h"
#include "../../config/Config.h"
using namespace TakeoffPrivate;

// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

Panel::Panel(QGraphicsWidget *parent)
        : QGraphicsWidget(parent),
          panelLayout(new QGraphicsGridLayout(this))
{
    // To maintain the plasmoid at fullscreen mode, is necessary to make a hack.
    // This is the structure of the layout:
    //             0 1 . . . . . . . NUM_COLUMNS+1
    //             -------------------
    //          0 |___________________|
    //          1 | |o|o|o|o|o|o|o|o| |
    //          . | |o|o|o|o|o|o|o|o| |
    //          . | |o|o|o|o|o|o|o|o| |
    //          . | |o|o|o|o|o|o|o|o| |
    // NUM_ROWS+1 | |               | |
    //             ------------------
    // The first and the last columns and the last row are separators
    // (Plasma::Label). The first row is another margin.

    Config *cfg = Config::getInstance();

    // Set the separators and the top margin
    int numRows    = cfg->getSettings(Config::NUM_ROWS).toInt();
    int numColumns = cfg->getSettings(Config::NUM_COLUMNS).toInt();

    Plasma::Label *s1 = new Plasma::Label(this);
    Plasma::Label *s2 = new Plasma::Label(this);
    Plasma::Label *s3 = new Plasma::Label(this);

    this->panelLayout->addItem(s1, 1, 0, numRows+1, 1);            // Left
    this->panelLayout->addItem(s2, 1, numColumns+1, numRows+1, 1); // Right
    this->panelLayout->addItem(s3, numRows+1, 1, 1, numColumns);   // Bottom
    this->panelLayout->setRowMinimumHeight(0, 0);                  // Top margin
    this->panelLayout->setRowMaximumHeight(0, 0);

    // Set the maximum grid size
    int itemSize = cfg->getSettings(Config::LAUNCHER_SIZE).toInt();

    for (int n=1; n<=numColumns; n++) {
        this->panelLayout->setColumnMaximumWidth(n, itemSize);
        this->panelLayout->setColumnMinimumWidth(n, itemSize);
    }

    for (int n=1; n<=numRows; n++) {
        this->panelLayout->setRowMaximumHeight(n, itemSize);
        this->panelLayout->setRowMinimumHeight(n, itemSize);
    }


    this->panelLayout->setSpacing(
            cfg->getSettings(Config::SEPARATION_BETWEEN_LAUNCHERS).toInt());
    this->setLayout(this->panelLayout);
}


// ************************************************************************** //
// **********                    PUBLIC METHODS                    ********** //
// ************************************************************************** //

void Panel::addLauncher(Takeoff::Launcher *launcher)
{
    Config *cfg = Config::getInstance();
    int numColumns = cfg->getSettings(Config::NUM_COLUMNS).toInt();

    if (this->isFull())
        return;

    int row    = ((this->panelLayout->count()-3) / numColumns) + 1;
    int column = ((this->panelLayout->count()-3) % numColumns) + 1;
    this->panelLayout->addItem(launcher, row, column, Qt::AlignCenter);
}


// ************************************************************************** //
// **********                      GET/SET/IS                      ********** //
// ************************************************************************** //

bool Panel::isFull() const
{
    Config *cfg = Config::getInstance();
    int numRows    = cfg->getSettings(Config::NUM_ROWS).toInt();
    int numColumns = cfg->getSettings(Config::NUM_COLUMNS).toInt();

    // -3 by the separators
    return this->panelLayout->count()-3 >= numRows*numColumns;
}