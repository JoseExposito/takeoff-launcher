/**
 * @file /src/takeoff/takeoff_widget/search/SearchWidget.cpp
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
 * @class  TakeoffPrivate::SearchWidget
 */
#include "SearchWidget.h"
#include <QtCore/QTimer>
#include <QtGui/QGraphicsGridLayout>
#include <KDE/KIcon>
#include <KDE/Plasma/IconWidget>
#include <KDE/Plasma/LineEdit>
#include "../util/Panel.h"
#include "../Launcher.h"
#include "../../../model/krunner/KRunner.h"
using namespace TakeoffPrivate;

// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

SearchWidget::SearchWidget(QGraphicsWidget *parent)
    : QGraphicsWidget(parent),
      goBack(new Plasma::IconWidget(this)),
      searchBox(new Plasma::LineEdit(this)),
      resultsPanel(new Panel(this)),
      searchTimer(new QTimer(this))
{
    // Set widgets properties
    this->goBack->setIcon("arrow-left");
    this->goBack->setMaximumIconSize(QSizeF(24, 24));
    connect(this->goBack, SIGNAL(clicked()), this, SIGNAL(exitSearch()));

    this->searchBox->setMaximumWidth(300);
    this->searchBox->setClearButtonShown(true);
    this->searchBox->setFocusPolicy(Qt::NoFocus);
    connect(this->searchBox, SIGNAL(textChanged(QString)),
            this->searchTimer, SLOT(start()));

    this->searchTimer->setInterval(300);
    this->searchTimer->setSingleShot(true);
    connect(this->searchTimer, SIGNAL(timeout()), this, SLOT(search()));

    // Add the widgets
    QGraphicsGridLayout *l = new QGraphicsGridLayout(this);
    l->addItem(this->goBack, 0, 0);
    l->addItem(this->searchBox, 0, 1);
    l->addItem(resultsPanel, 1, 0, 1, 2);
    this->setLayout(l);

    // Connect the KRunner results to the function to show it
    KRunner *krunner = KRunner::getInstance();
    connect(krunner, SIGNAL(queryFinished(QList<Takeoff::Launcher>)),
            this, SLOT(showQuery(QList<Takeoff::Launcher>)));
}


// ************************************************************************** //
// **********                     PRIVATE SLOTS                    ********** //
// ************************************************************************** //

void SearchWidget::search()
{
    QString text = this->searchBox->text();
    this->resultsPanel->removeAllLaunchers();

    if (text.length() < 3 || text.trimmed().isEmpty())
        return;

    KRunner *krunner = KRunner::getInstance();
    krunner->executeQuery(text.trimmed());
}

void SearchWidget::showQuery(QList<Takeoff::Launcher> matches)
{
    foreach(Takeoff::Launcher launcher, matches) {
        Takeoff::Launcher *aux = new Takeoff::Launcher(launcher);
        this->resultsPanel->addLauncher(aux);
    }
}


// ************************************************************************** //
// **********                    PUBLIC METHODS                    ********** //
// ************************************************************************** //

void SearchWidget::addSearchText(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        Takeoff::Launcher *launcher = this->resultsPanel->getLauncher(0);
        if (launcher != NULL)
            launcher->runApplication();

    } else if (event->key() == Qt::Key_Backspace)
        this->searchBox->setText(this->searchBox->text().mid(
                0, this->searchBox->text().length()-1));
    else
        this->searchBox->setText(this->searchBox->text() + event->text());
}

void SearchWidget::clearSearchText()
{
    this->searchBox->setText("");
    this->resultsPanel->removeAllLaunchers();
}
