/**
 * @file /src/takeoff/view/config_forms/KRunnerForm.cpp
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
 * @class  KRunnerForm
 */
#include "KRunnerForm.h"
#include <KDE/KService>
#include <KDE/KServiceTypeTrader>
#include <KDE/KPluginInfo>
#include <Plasma/RunnerManager>
#include <Plasma/AbstractRunner>
#include "../../model/krunner/KRunner.h"

// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

KRunnerForm::KRunnerForm(QWidget *parent)
        : KPluginSelector(parent)
{
    KService::List offers = KServiceTypeTrader::self()->query("Plasma/Runner");
    QList<KPluginInfo> runnerInfo = KPluginInfo::fromServices(offers);
    this->addPlugins(runnerInfo, KPluginSelector::ReadConfigFile,
            i18n("Available plugins"), "", KGlobal::config());

    connect(this, SIGNAL(configCommitted(const QByteArray&)),
            this, SLOT(updateRunner(const QByteArray&)));
}


// ************************************************************************** //
// **********                     PUBLIC SLOTS                     ********** //
// ************************************************************************** //

void KRunnerForm::saveConfiguration()
{
    this->save();

    KRunner *runner = KRunner::getInstance();
    Plasma::RunnerManager *runnerManager = runner->getRunnerManager();
    runnerManager->reloadConfiguration();

    this->close();
}


// ************************************************************************** //
// **********                    PRIVATE SLOTS                     ********** //
// ************************************************************************** //

void KRunnerForm::updateRunner(const QByteArray &name)
{
    KRunner *runner = KRunner::getInstance();
    Plasma::RunnerManager *runnerManager = runner->getRunnerManager();

    Plasma::AbstractRunner *absRunner = runnerManager->runner(name);

    if (absRunner) {
        absRunner->reloadConfiguration();
    }
}
