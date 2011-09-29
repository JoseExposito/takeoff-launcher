#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'GeneralSettingsForm.ui'
**
** Created: Thu Sep 29 17:28:36 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALSETTINGSFORM_H
#define UI_GENERALSETTINGSFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneralSettingsForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label_5;
    QPushButton *iconBtn;
    QCheckBox *showFavorites;
    QCheckBox *showAllApplications;
    QCheckBox *showXdgMenu;
    QLabel *label_4;
    QSlider *launcherSize;
    QLabel *label_2;
    QSlider *separationSize;
    QLabel *label;
    QSpinBox *numRows;
    QLabel *label_3;
    QSpinBox *numColumns;
    QCheckBox *showIconText;
    QCheckBox *fullScreen;
    QCheckBox *rememberLastTab;
    QCheckBox *showBackgroundImage;
    QLineEdit *backgroundImageText;
    QPushButton *selectImageBtn;

    void setupUi(QWidget *GeneralSettingsForm)
    {
        if (GeneralSettingsForm->objectName().isEmpty())
            GeneralSettingsForm->setObjectName(QString::fromUtf8("GeneralSettingsForm"));
        GeneralSettingsForm->resize(425, 330);
        gridLayout = new QGridLayout(GeneralSettingsForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(GeneralSettingsForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        iconBtn = new QPushButton(GeneralSettingsForm);
        iconBtn->setObjectName(QString::fromUtf8("iconBtn"));
        iconBtn->setMinimumSize(QSize(50, 50));
        iconBtn->setMaximumSize(QSize(50, 50));
        iconBtn->setIconSize(QSize(48, 48));

        gridLayout->addWidget(iconBtn, 0, 1, 3, 1);

        showFavorites = new QCheckBox(GeneralSettingsForm);
        showFavorites->setObjectName(QString::fromUtf8("showFavorites"));

        gridLayout->addWidget(showFavorites, 1, 0, 1, 1);

        showAllApplications = new QCheckBox(GeneralSettingsForm);
        showAllApplications->setObjectName(QString::fromUtf8("showAllApplications"));

        gridLayout->addWidget(showAllApplications, 2, 0, 1, 1);

        showXdgMenu = new QCheckBox(GeneralSettingsForm);
        showXdgMenu->setObjectName(QString::fromUtf8("showXdgMenu"));

        gridLayout->addWidget(showXdgMenu, 3, 0, 1, 1);

        label_4 = new QLabel(GeneralSettingsForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        launcherSize = new QSlider(GeneralSettingsForm);
        launcherSize->setObjectName(QString::fromUtf8("launcherSize"));
        launcherSize->setMinimum(64);
        launcherSize->setMaximum(150);
        launcherSize->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(launcherSize, 4, 1, 1, 2);

        label_2 = new QLabel(GeneralSettingsForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        separationSize = new QSlider(GeneralSettingsForm);
        separationSize->setObjectName(QString::fromUtf8("separationSize"));
        separationSize->setMinimum(32);
        separationSize->setMaximum(150);
        separationSize->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(separationSize, 5, 1, 1, 2);

        label = new QLabel(GeneralSettingsForm);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 6, 0, 1, 1);

        numRows = new QSpinBox(GeneralSettingsForm);
        numRows->setObjectName(QString::fromUtf8("numRows"));
        numRows->setMinimum(2);
        numRows->setMaximum(10);

        gridLayout->addWidget(numRows, 6, 1, 1, 2);

        label_3 = new QLabel(GeneralSettingsForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 7, 0, 1, 1);

        numColumns = new QSpinBox(GeneralSettingsForm);
        numColumns->setObjectName(QString::fromUtf8("numColumns"));
        numColumns->setMinimum(3);
        numColumns->setMaximum(20);

        gridLayout->addWidget(numColumns, 7, 1, 1, 2);

        showIconText = new QCheckBox(GeneralSettingsForm);
        showIconText->setObjectName(QString::fromUtf8("showIconText"));

        gridLayout->addWidget(showIconText, 8, 0, 1, 1);

        fullScreen = new QCheckBox(GeneralSettingsForm);
        fullScreen->setObjectName(QString::fromUtf8("fullScreen"));

        gridLayout->addWidget(fullScreen, 9, 0, 1, 1);

        rememberLastTab = new QCheckBox(GeneralSettingsForm);
        rememberLastTab->setObjectName(QString::fromUtf8("rememberLastTab"));

        gridLayout->addWidget(rememberLastTab, 10, 0, 1, 1);

        showBackgroundImage = new QCheckBox(GeneralSettingsForm);
        showBackgroundImage->setObjectName(QString::fromUtf8("showBackgroundImage"));

        gridLayout->addWidget(showBackgroundImage, 11, 0, 1, 1);

        backgroundImageText = new QLineEdit(GeneralSettingsForm);
        backgroundImageText->setObjectName(QString::fromUtf8("backgroundImageText"));
        backgroundImageText->setReadOnly(true);

        gridLayout->addWidget(backgroundImageText, 12, 1, 1, 1);

        selectImageBtn = new QPushButton(GeneralSettingsForm);
        selectImageBtn->setObjectName(QString::fromUtf8("selectImageBtn"));

        gridLayout->addWidget(selectImageBtn, 12, 2, 1, 1);


        retranslateUi(GeneralSettingsForm);
        QObject::connect(showBackgroundImage, SIGNAL(clicked(bool)), backgroundImageText, SLOT(setEnabled(bool)));
        QObject::connect(showBackgroundImage, SIGNAL(clicked(bool)), selectImageBtn, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(GeneralSettingsForm);
    } // setupUi

    void retranslateUi(QWidget *GeneralSettingsForm)
    {
        label_5->setText(tr2i18n("Icon", 0));
        iconBtn->setText(QString());
        showFavorites->setText(tr2i18n("Show \"Favorites\" category", 0));
        showAllApplications->setText(tr2i18n("Show \"All Applications\" category", 0));
        showXdgMenu->setText(tr2i18n("Show standard menu", 0));
        label_4->setText(tr2i18n("Launcher size", 0));
        label_2->setText(tr2i18n("Separation between launchers", 0));
        label->setText(tr2i18n("Number of rows", 0));
        label_3->setText(tr2i18n("Number of columns", 0));
        showIconText->setText(tr2i18n("Show icon text", 0));
        fullScreen->setText(tr2i18n("Show Takeoff in full screen mode", 0));
        rememberLastTab->setText(tr2i18n("Remember last tab", 0));
        showBackgroundImage->setText(tr2i18n("Show background image", 0));
        selectImageBtn->setText(QString());
        Q_UNUSED(GeneralSettingsForm);
    } // retranslateUi

};

namespace Ui {
    class GeneralSettingsForm: public Ui_GeneralSettingsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // GENERALSETTINGSFORM_H

