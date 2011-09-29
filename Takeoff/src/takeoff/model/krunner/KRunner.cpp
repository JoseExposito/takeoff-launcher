/**
 * @file /src/takeoff/krunner/KRunner.cpp
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
 * @class  KRunner
 */
#include "KRunner.h"
#include <QtCore/QSettings>
#include <KDE/KRun>
#include <Plasma/RunnerManager>
#include <Plasma/AbstractRunner>
#include "../config/Config.h"

// ************************************************************************** //
// **********             STATIC METHODS AND VARIABLES             ********** //
// ************************************************************************** //

KRunner *KRunner::instance = NULL;

KRunner *KRunner::getInstance()
{
    if (KRunner::instance == NULL)
        KRunner::instance = new KRunner();

    return KRunner::instance;
}


// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

KRunner::KRunner()
    : runnerManager(new Plasma::RunnerManager(this))
{
    connect(this->runnerManager, SIGNAL(matchesChanged(
            QList<Plasma::QueryMatch>)),
            this, SLOT(parseQuery(QList<Plasma::QueryMatch>)));

    this->updateAllowedRunners();
}


// ************************************************************************** //
// **********                    PUBLIC METHODS                    ********** //
// ************************************************************************** //

void KRunner::updateAllowedRunners()
{
    Config *cfg = Config::getInstance();
    this->runnerManager->setAllowedRunners(cfg->getAllowedRunners());
    this->runnerManager->reloadConfiguration();
}


// ************************************************************************** //
// **********                    PUBLIC SLOTS                      ********** //
// ************************************************************************** //

void KRunner::executeQuery(const QString &query)
{
    this->runnerManager->launchQuery(query);
}

void KRunner::runLauncher(const Takeoff::Launcher &launcher)
{
    QString url = launcher.getDesktopFile();

    if (url.startsWith("krunner|")) {
        QStringList urlParts = url.split("|");

        QString  runnerId = urlParts.at(1);
        QString  query    = urlParts.at(2);
        QVariant data     = urlParts.at(3);
        QString  matchId  = urlParts.at(4);

        Plasma::AbstractRunner *runner =  this->runnerManager->runner(runnerId);

        Plasma::QueryMatch match(runner);
        match.setData(data);
        match.setId(matchId);

        Plasma::RunnerContext context;
        context.addMatch(query, match);

        runner->run(context, match);
    } else {
        new KRun(KUrl(url), NULL);
    }

    emit this->launcherExecuted();
}


// ************************************************************************** //
// **********                    PRIVATE SLOTS                     ********** //
// ************************************************************************** //

void KRunner::parseQuery(QList<Plasma::QueryMatch> matches)
{
    QList<Takeoff::Launcher> ret;

    foreach(Plasma::QueryMatch match, matches) {
        QString url;

        // If is a URL to open a file, treat it as a normal launcher
        if (match.runner()->id() == "locations") {
            url = match.data().toString();

        // If is a more complex URL needs more work
        } else {
            url = "krunner|" + match.runner()->id() + "|"
                  + this->runnerManager->query() +  "|"
                  + match.data().toString() + "|" + match.id();
        }

        Takeoff::Launcher l(match.icon(), match.text(), match.subtext(), url);
        ret.append(l);
    }

    emit this->queryFinished(ret);
}
