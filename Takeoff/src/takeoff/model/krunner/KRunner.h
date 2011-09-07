/**
 * @file /src/takeoff/krunner/KRunner.h
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
#ifndef MODEL_KRUNNER_H
#define MODEL_KRUNNER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <Plasma/QueryMatch>
#include "../../view/takeoff_widget/Launcher.h"
namespace Plasma { class RunnerManager; }

/**
 * Class to access to the KRunner features. Is a singleton, the only way to get
 * an instance of the class is call to the getInstance() method:
 *
 * KRunner *krunner = KRunner::getInstance();
 *
 * Provides two funcionalities: execute queries and run launchers.
 *
 * To execute a query is neccessary call to  the executeQuery() method with the
 * text to search. Before call to this function, ensure to connect your slot
 * with the queryFinished() signal.
 *
 * To run a launcher, only is necessary call to the runLauncher() method with
 * the launcher to run. The launcherExecuted() signal will be emited after run
 * it.
 */
class KRunner : public QObject
{
    Q_OBJECT

public:

    /**
     * Only method to get an instance of the class.
     * @return The single instance of the class.
     */
    static KRunner* getInstance();

    /**
     * Returns the used RunnerManager. Useful to change used runners in the
     * configuration.
     * @return The RunnerManager.
     */
    Plasma::RunnerManager *getRunnerManager();

public slots:

    /**
     * Executes a query. The result of the query will be returned in the
     * queryFinished() signal.
     * @param query The query to execute.
     */
    void executeQuery(const QString &query);

    /**
     * Executes the indicated launcher.
     * @param launcher The launcher to run.
     */
    void runLauncher(const Takeoff::Launcher &launcher);

signals:

    /**
     * Signal emitted whenever a query executed with the executeQuery() slot is
     * finished.
     * @param result The result of the query.
     */
    void queryFinished(QList<Takeoff::Launcher> result);

    /**
     * Emitted whenever a launcher is executed. Very useful to hide the popup.
     */
    void launcherExecuted();

private slots:

    /**
     * Auxiliar function to parse from Plasma::QueryMatch to Takeoff::Launcher.
     * @param matches The matches of a query executed with executeQuery().
     */
    void parseQuery(QList<Plasma::QueryMatch> matches);

private:

    /// Proxy used to run querys.
    Plasma::RunnerManager *runnerManager;

    //--------------------------------------------------------------------------

    /// Single instance of the class.
    static KRunner* instance;

    // Hide constructors
    KRunner();
    KRunner(const KRunner&);
    const KRunner &operator = (const KRunner&);

};

#endif // MODEL_KRUNNER_H
