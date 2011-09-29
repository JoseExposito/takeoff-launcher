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
#include <QtCore/QByteArray>
#include <Plasma/RunnerManager>
#include "../../model/krunner/KRunner.h"

// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

KRunnerForm::KRunnerForm(QWidget *parent)
    : KPluginSelector(parent)
{
    connect(this, SIGNAL(configCommitted(const QByteArray&)),
            this, SLOT(updateRunner(const QByteArray&)));

    this->addPlugins(Plasma::RunnerManager::listRunnerInfo(),
            KPluginSelector::ReadConfigFile, i18n("Available plugins"), "",
            KSharedConfig::openConfig("takeoffrc"));
}


// ************************************************************************** //
// **********                     PUBLIC SLOTS                     ********** //
// ************************************************************************** //

void KRunnerForm::saveConfiguration()
{
    this->save();
}

#include <QDebug>
void KRunnerForm::updateRunner(const QByteArray &name)
{
    qDebug() << "#####################################################";

    // TODO Se debería llamar cuando se actualizase la configuración... no lo hace :S

    /*KRunner *runner = KRunner::getInstance();
    runner->updateAllowedRunners();*/
}
