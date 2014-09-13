/********************************************************************************
** Form generated from reading ui file 'SpectrogramDialog.ui'
**
** Created: Thu 19. Nov 10:31:13 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SPECTROGRAMDIALOG_H
#define UI_SPECTROGRAMDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "plots/SpectrogramPlot.h"

QT_BEGIN_NAMESPACE

class Ui_SpectrogramDialogClass
{
public:
    QGridLayout *gridLayout;
    SpectrogramPlot *plot;
    QLabel *label;
    QPushButton *btnClose;
    QVBoxLayout *verticalLayout;
    QPushButton *btnSave;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *SpectrogramDialogClass)
    {
        if (SpectrogramDialogClass->objectName().isEmpty())
            SpectrogramDialogClass->setObjectName(QString::fromUtf8("SpectrogramDialogClass"));
        SpectrogramDialogClass->resize(998, 604);
        SpectrogramDialogClass->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(SpectrogramDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plot = new SpectrogramPlot(SpectrogramDialogClass);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setFrameShape(QFrame::StyledPanel);
        plot->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(plot, 0, 0, 1, 1);

        label = new QLabel(SpectrogramDialogClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        btnClose = new QPushButton(SpectrogramDialogClass);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon);
        btnClose->setIconSize(QSize(24, 24));

        gridLayout->addWidget(btnClose, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnSave = new QPushButton(SpectrogramDialogClass);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon1);
        btnSave->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(btnSave);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        retranslateUi(SpectrogramDialogClass);
        QObject::connect(btnClose, SIGNAL(clicked()), SpectrogramDialogClass, SLOT(accept()));

        QMetaObject::connectSlotsByName(SpectrogramDialogClass);
    } // setupUi

    void retranslateUi(QDialog *SpectrogramDialogClass)
    {
        SpectrogramDialogClass->setWindowTitle(QApplication::translate("SpectrogramDialogClass", "Spectrogram", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SpectrogramDialogClass", "<em>Left click+drag to create new zoom rectangle, release to zoom in.\n"
"\"\n"
"            \"Right click to zoom out to previous zoom rectangle.\n"
"\"\n"
"            \"Middle click+drag to pan around the graph.</em>", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("SpectrogramDialogClass", "Close", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("SpectrogramDialogClass", "Save image...", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(SpectrogramDialogClass);
    } // retranslateUi

};

namespace Ui {
    class SpectrogramDialogClass: public Ui_SpectrogramDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECTROGRAMDIALOG_H
