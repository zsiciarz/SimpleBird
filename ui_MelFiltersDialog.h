/********************************************************************************
** Form generated from reading UI file 'MelFiltersDialog.ui'
**
** Created: Thu 25. Mar 11:24:41 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MELFILTERSDIALOG_H
#define UI_MELFILTERSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MelFiltersDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gbxCheckboxes;
    QGroupBox *gbxFiltersLinear;
    QGroupBox *gbxFiltersMel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MelFiltersDialog)
    {
        if (MelFiltersDialog->objectName().isEmpty())
            MelFiltersDialog->setObjectName(QString::fromUtf8("MelFiltersDialog"));
        MelFiltersDialog->resize(476, 480);
        verticalLayout = new QVBoxLayout(MelFiltersDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gbxCheckboxes = new QGroupBox(MelFiltersDialog);
        gbxCheckboxes->setObjectName(QString::fromUtf8("gbxCheckboxes"));

        verticalLayout->addWidget(gbxCheckboxes);

        gbxFiltersLinear = new QGroupBox(MelFiltersDialog);
        gbxFiltersLinear->setObjectName(QString::fromUtf8("gbxFiltersLinear"));

        verticalLayout->addWidget(gbxFiltersLinear);

        gbxFiltersMel = new QGroupBox(MelFiltersDialog);
        gbxFiltersMel->setObjectName(QString::fromUtf8("gbxFiltersMel"));

        verticalLayout->addWidget(gbxFiltersMel);

        buttonBox = new QDialogButtonBox(MelFiltersDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MelFiltersDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MelFiltersDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MelFiltersDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MelFiltersDialog);
    } // setupUi

    void retranslateUi(QDialog *MelFiltersDialog)
    {
        MelFiltersDialog->setWindowTitle(QApplication::translate("MelFiltersDialog", "Choose Mel filters", 0, QApplication::UnicodeUTF8));
        gbxCheckboxes->setTitle(QApplication::translate("MelFiltersDialog", "Filters", 0, QApplication::UnicodeUTF8));
        gbxFiltersLinear->setTitle(QApplication::translate("MelFiltersDialog", "Filters (linear frequency scale)", 0, QApplication::UnicodeUTF8));
        gbxFiltersMel->setTitle(QApplication::translate("MelFiltersDialog", "Filters (Mel frequency scale)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MelFiltersDialog: public Ui_MelFiltersDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MELFILTERSDIALOG_H
