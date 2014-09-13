/********************************************************************************
** Form generated from reading UI file 'ChangelogDialog.ui'
**
** Created: Thu 25. Mar 11:24:41 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGELOGDIALOG_H
#define UI_CHANGELOGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangelogDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabSimpleBird;
    QGridLayout *gridLayout_2;
    QTextEdit *txtSimpleBird;
    QWidget *tabAquila;
    QGridLayout *gridLayout;
    QTextEdit *txtAquila;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ChangelogDialog)
    {
        if (ChangelogDialog->objectName().isEmpty())
            ChangelogDialog->setObjectName(QString::fromUtf8("ChangelogDialog"));
        ChangelogDialog->resize(587, 452);
        verticalLayout = new QVBoxLayout(ChangelogDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(ChangelogDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabSimpleBird = new QWidget();
        tabSimpleBird->setObjectName(QString::fromUtf8("tabSimpleBird"));
        gridLayout_2 = new QGridLayout(tabSimpleBird);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        txtSimpleBird = new QTextEdit(tabSimpleBird);
        txtSimpleBird->setObjectName(QString::fromUtf8("txtSimpleBird"));
        txtSimpleBird->setReadOnly(true);

        gridLayout_2->addWidget(txtSimpleBird, 0, 0, 1, 1);

        tabWidget->addTab(tabSimpleBird, QString());
        tabAquila = new QWidget();
        tabAquila->setObjectName(QString::fromUtf8("tabAquila"));
        gridLayout = new QGridLayout(tabAquila);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        txtAquila = new QTextEdit(tabAquila);
        txtAquila->setObjectName(QString::fromUtf8("txtAquila"));
        txtAquila->setReadOnly(true);

        gridLayout->addWidget(txtAquila, 0, 0, 1, 1);

        tabWidget->addTab(tabAquila, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(ChangelogDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ChangelogDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChangelogDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChangelogDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ChangelogDialog);
    } // setupUi

    void retranslateUi(QDialog *ChangelogDialog)
    {
        ChangelogDialog->setWindowTitle(QApplication::translate("ChangelogDialog", "Version changelog", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabSimpleBird), QApplication::translate("ChangelogDialog", "SimpleBird", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabAquila), QApplication::translate("ChangelogDialog", "Aquila", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChangelogDialog: public Ui_ChangelogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGELOGDIALOG_H
