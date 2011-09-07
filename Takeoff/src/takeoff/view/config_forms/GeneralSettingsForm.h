/**
 * @file /src/takeoff/view/config_forms/GeneralSettingsForm.h
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
 * @class  GeneralSettingsForm
 */
#ifndef VIEW_CONFIG_FORMS_GENERAL_SETTINGS_FORM_H
#define VIEW_CONFIG_FORMS_GENERAL_SETTINGS_FORM_H

#include <QWidget>
class Config;
namespace Ui { class GeneralSettingsForm; }

/**
 * Widget to configure Takeoff.
 */
class GeneralSettingsForm : public QWidget
{
    Q_OBJECT

public:

    /**
     * Default constructor.
     * @param parent The parent of the widget.
     */
    GeneralSettingsForm(QWidget *parent = 0);

    /// Destructor
    ~GeneralSettingsForm();

public slots:
    /**
     * Saves the configuration.
     */
    void saveConfiguration();

private slots:

    /// Changes the Takeoff icon
    void on_iconBtn_clicked();

    /// To select a background image for Takeoff
    void on_selectImageBtn_clicked();

private:

    /// To use the .ui form
    Ui::GeneralSettingsForm *ui;

    /// Pointer to the configuration singleton
    Config *cfg;

};

#endif // VIEW_CONFIG_FORMS_GENERAL_SETTINGS_FORM_H
