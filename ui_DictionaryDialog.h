/********************************************************************************
** Form generated from reading UI file 'DictionaryDialog.ui'
**
** Created: Thu 25. Mar 11:24:41 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICTIONARYDIALOG_H
#define UI_DICTIONARYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DictionaryDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QTableView *tblDictionary;
    QCheckBox *cbxMultithreading;
    QProgressBar *progressBarFile;
    QProgressBar *progressBarTotal;
    QVBoxLayout *verticalLayout;
    QToolButton *btnAddDirectory;
    QToolButton *btnAddFile;
    QToolButton *btnClear;
    QToolButton *btnProcess;
    QSpacerItem *verticalSpacer;
    QToolButton *btnClose;

    void setupUi(QDialog *DictionaryDialog)
    {
        if (DictionaryDialog->objectName().isEmpty())
            DictionaryDialog->setObjectName(QString::fromUtf8("DictionaryDialog"));
        DictionaryDialog->resize(459, 503);
        horizontalLayout = new QHBoxLayout(DictionaryDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tblDictionary = new QTableView(DictionaryDialog);
        tblDictionary->setObjectName(QString::fromUtf8("tblDictionary"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(3);
        sizePolicy.setHeightForWidth(tblDictionary->sizePolicy().hasHeightForWidth());
        tblDictionary->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(tblDictionary);

        cbxMultithreading = new QCheckBox(DictionaryDialog);
        cbxMultithreading->setObjectName(QString::fromUtf8("cbxMultithreading"));

        verticalLayout_2->addWidget(cbxMultithreading);

        progressBarFile = new QProgressBar(DictionaryDialog);
        progressBarFile->setObjectName(QString::fromUtf8("progressBarFile"));
        progressBarFile->setValue(0);

        verticalLayout_2->addWidget(progressBarFile);

        progressBarTotal = new QProgressBar(DictionaryDialog);
        progressBarTotal->setObjectName(QString::fromUtf8("progressBarTotal"));
        progressBarTotal->setValue(0);

        verticalLayout_2->addWidget(progressBarTotal);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnAddDirectory = new QToolButton(DictionaryDialog);
        btnAddDirectory->setObjectName(QString::fromUtf8("btnAddDirectory"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/folder_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddDirectory->setIcon(icon);
        btnAddDirectory->setIconSize(QSize(32, 32));
        btnAddDirectory->setAutoRaise(true);

        verticalLayout->addWidget(btnAddDirectory);

        btnAddFile = new QToolButton(DictionaryDialog);
        btnAddFile->setObjectName(QString::fromUtf8("btnAddFile"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/page_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddFile->setIcon(icon1);
        btnAddFile->setIconSize(QSize(32, 32));
        btnAddFile->setAutoRaise(true);

        verticalLayout->addWidget(btnAddFile);

        btnClear = new QToolButton(DictionaryDialog);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/note_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClear->setIcon(icon2);
        btnClear->setIconSize(QSize(32, 32));
        btnClear->setAutoRaise(true);

        verticalLayout->addWidget(btnClear);

        btnProcess = new QToolButton(DictionaryDialog);
        btnProcess->setObjectName(QString::fromUtf8("btnProcess"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/database_process.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnProcess->setIcon(icon3);
        btnProcess->setIconSize(QSize(32, 32));
        btnProcess->setAutoRaise(true);

        verticalLayout->addWidget(btnProcess);

        verticalSpacer = new QSpacerItem(20, 128, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnClose = new QToolButton(DictionaryDialog);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon4);
        btnClose->setIconSize(QSize(32, 32));
        btnClose->setAutoRaise(true);

        verticalLayout->addWidget(btnClose);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(DictionaryDialog);
        QObject::connect(btnClose, SIGNAL(clicked()), DictionaryDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(DictionaryDialog);
    } // setupUi

    void retranslateUi(QDialog *DictionaryDialog)
    {
        DictionaryDialog->setWindowTitle(QApplication::translate("DictionaryDialog", "Dictionary view", 0, QApplication::UnicodeUTF8));
        cbxMultithreading->setText(QApplication::translate("DictionaryDialog", "Use multithreading when processing?", 0, QApplication::UnicodeUTF8));
        btnAddDirectory->setText(QApplication::translate("DictionaryDialog", "Add directory", 0, QApplication::UnicodeUTF8));
        btnAddFile->setText(QApplication::translate("DictionaryDialog", "Add file", 0, QApplication::UnicodeUTF8));
        btnClear->setText(QApplication::translate("DictionaryDialog", "Clear", 0, QApplication::UnicodeUTF8));
        btnProcess->setText(QApplication::translate("DictionaryDialog", "Rebuild dictionary", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("DictionaryDialog", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DictionaryDialog: public Ui_DictionaryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTIONARYDIALOG_H
