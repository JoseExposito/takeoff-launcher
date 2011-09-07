/**
 * @file /src/takeoff/view/config_forms/KRunnerForm.h
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
#ifndef VIEW_CONFIG_FORMS_KRUNNER_FORM_H
#define VIEW_CONFIG_FORMS_KRUNNER_FORM_H

#include <QtGui/QWidget>
#include <KDE/KPluginSelector>

/**
 * Widget to configure the plugins availables in the search.
 */
class KRunnerForm : public KPluginSelector
{
    Q_OBJECT

public:

    /**
     * Default constructor.
     * @param parent The parent of the widget.
     */
    KRunnerForm(QWidget *parent = 0);

public slots:

    /**
     * Saves the configuration.
     */
    void saveConfiguration();

private slots:

    /**
     * Called after save the configuration with this->save();
     */
    void updateRunner(const QByteArray& runnerName);

};

#endif // VIEW_CONFIG_FORMS_KRUNNER_FORM_H
