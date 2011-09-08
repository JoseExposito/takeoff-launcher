/**
 * @file /src/takeoff/view/config_forms/GeneralSettingsForm.cpp
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
#include "GeneralSettingsForm.h"
#include "../../model/config/Config.h"
#include "ui_GeneralSettingsForm.h"
#include <KDE/KFileDialog>
#include <KDE/KIconDialog>

// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

GeneralSettingsForm::GeneralSettingsForm(QWidget *parent)
        : QWidget(parent),
          ui(new Ui::GeneralSettingsForm),
          cfg(Config::getInstance())
{
    ui->setupUi(this);

    // Load configuration
    this->ui->showFavorites->setChecked(
            this->cfg->getSettings(Config::SHOW_FAVORITES).toBool());
    this->ui->showAllApplications->setChecked(
            this->cfg->getSettings(Config::SHOW_ALL_APPLICATIONS).toBool());
    this->ui->showXdgMenu->setChecked(
            this->cfg->getSettings(Config::SHOW_XDG_MENU).toBool());
    this->ui->launcherSize->setValue(
            this->cfg->getSettings(Config::LAUNCHER_SIZE).toInt());
    this->ui->separationSize->setValue(this->cfg->getSettings(
            Config::SEPARATION_BETWEEN_LAUNCHERS).toInt());
    this->ui->numRows->setValue(
            this->cfg->getSettings(Config::NUM_ROWS).toInt());
    this->ui->numColumns->setValue(
            this->cfg->getSettings(Config::NUM_COLUMNS).toInt());
    this->ui->iconBtn->setIcon(
            KIcon(this->cfg->getSettings(Config::ICON).toString()));
    this->ui->rememberLastTab->setChecked(
            this->cfg->getSettings(Config::REMEMBER_LAST_TAB).toBool());
    this->ui->showIconText->setChecked(
            this->cfg->getSettings(Config::SHOW_ICON_TEXT).toBool());
    this->ui->fullScreen->setChecked(
            this->cfg->getSettings(Config::FULL_SCREEN).toBool());
    this->ui->showBackgroundImage->setChecked(
            this->cfg->getSettings(Config::SHOW_BACKGROUND_IMAGE).toBool());
    this->ui->backgroundImageText->setText(
            this->cfg->getSettings(Config::BACKGROUND_IMAGE).toString());
    this->ui->backgroundImageText->setEnabled(
            this->cfg->getSettings(Config::SHOW_BACKGROUND_IMAGE).toBool());
    this->ui->selectImageBtn->setIcon(QIcon::fromTheme("document-open"));
    this->ui->selectImageBtn->setEnabled(
            this->cfg->getSettings(Config::SHOW_BACKGROUND_IMAGE).toBool());
}

GeneralSettingsForm::~GeneralSettingsForm()
{
    delete ui;
}


// ************************************************************************** //
// **********                     PUBLIC SLOTS                     ********** //
// ************************************************************************** //

void GeneralSettingsForm::saveConfiguration()
{
    this->cfg->setSettings(Config::SHOW_FAVORITES,
            this->ui->showFavorites->isChecked());
    this->cfg->setSettings(Config::SHOW_ALL_APPLICATIONS,
            this->ui->showAllApplications->isChecked());
    this->cfg->setSettings(Config::SHOW_XDG_MENU,
            this->ui->showXdgMenu->isChecked());
    this->cfg->setSettings(Config::LAUNCHER_SIZE,
            this->ui->launcherSize->value());
    this->cfg->setSettings(Config::SEPARATION_BETWEEN_LAUNCHERS,
            this->ui->separationSize->value());
    this->cfg->setSettings(Config::NUM_ROWS, this->ui->numRows->value());
    this->cfg->setSettings(Config::NUM_COLUMNS, this->ui->numColumns->value());
    this->cfg->setSettings(Config::ICON, this->ui->iconBtn->icon().name());
    this->cfg->setSettings(Config::REMEMBER_LAST_TAB,
            this->ui->rememberLastTab->isChecked());
    this->cfg->setSettings(Config::SHOW_ICON_TEXT,
            this->ui->showIconText->isChecked());
    this->cfg->setSettings(Config::FULL_SCREEN,
            this->ui->fullScreen->isChecked());
    this->cfg->setSettings(Config::SHOW_BACKGROUND_IMAGE,
            this->ui->showBackgroundImage->isChecked());
    this->cfg->setSettings(Config::BACKGROUND_IMAGE,
            this->ui->backgroundImageText->text());
}


// ************************************************************************** //
// **********                    PRIVATE SLOTS                     ********** //
// ************************************************************************** //

void GeneralSettingsForm::on_iconBtn_clicked()
{
    KIconDialog dlg;
    KIcon icon = KIcon(dlg.getIcon());
    if (!icon.name().isEmpty()) {
        this->ui->iconBtn->setIcon(icon);
    }
}

void GeneralSettingsForm::on_selectImageBtn_clicked()
{
    QString fileName = KFileDialog::getOpenFileName();
    if (!fileName.isEmpty()) {
        this->ui->backgroundImageText->setText(fileName);
    }
}
