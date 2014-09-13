/********************************************************************************
** Form generated from reading UI file 'ScriptsWidget.ui'
**
** Created: Thu 25. Mar 11:24:41 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTSWIDGET_H
#define UI_SCRIPTSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "widgets/console/ConsoleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ScriptsWidget
{
public:
    QAction *actionSave;
    QAction *actionRun;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QGroupBox *gbxListScripts;
    QGridLayout *gridLayout;
    QListView *listScripts;
    QSplitter *splitter;
    QGroupBox *gbxCode;
    QGridLayout *gridLayout_2;
    QTextEdit *editCode;
    QGroupBox *gbxConsole;
    QGridLayout *gridLayout_3;
    ConsoleWidget *console;
    QVBoxLayout *verticalLayout;
    QToolButton *btnSave;
    QToolButton *btnRun;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ScriptsWidget)
    {
        if (ScriptsWidget->objectName().isEmpty())
            ScriptsWidget->setObjectName(QString::fromUtf8("ScriptsWidget"));
        ScriptsWidget->resize(529, 440);
        actionSave = new QAction(ScriptsWidget);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        actionRun = new QAction(ScriptsWidget);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon1);
        gridLayout_4 = new QGridLayout(ScriptsWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gbxListScripts = new QGroupBox(ScriptsWidget);
        gbxListScripts->setObjectName(QString::fromUtf8("gbxListScripts"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gbxListScripts->sizePolicy().hasHeightForWidth());
        gbxListScripts->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(gbxListScripts);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listScripts = new QListView(gbxListScripts);
        listScripts->setObjectName(QString::fromUtf8("listScripts"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listScripts->sizePolicy().hasHeightForWidth());
        listScripts->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(listScripts, 0, 0, 1, 1);


        horizontalLayout->addWidget(gbxListScripts);

        splitter = new QSplitter(ScriptsWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy2);
        splitter->setOrientation(Qt::Vertical);
        gbxCode = new QGroupBox(splitter);
        gbxCode->setObjectName(QString::fromUtf8("gbxCode"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(2);
        sizePolicy3.setHeightForWidth(gbxCode->sizePolicy().hasHeightForWidth());
        gbxCode->setSizePolicy(sizePolicy3);
        gridLayout_2 = new QGridLayout(gbxCode);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        editCode = new QTextEdit(gbxCode);
        editCode->setObjectName(QString::fromUtf8("editCode"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(2);
        sizePolicy4.setHeightForWidth(editCode->sizePolicy().hasHeightForWidth());
        editCode->setSizePolicy(sizePolicy4);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(9);
        editCode->setFont(font);

        gridLayout_2->addWidget(editCode, 0, 0, 1, 1);

        splitter->addWidget(gbxCode);
        gbxConsole = new QGroupBox(splitter);
        gbxConsole->setObjectName(QString::fromUtf8("gbxConsole"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(1);
        sizePolicy5.setHeightForWidth(gbxConsole->sizePolicy().hasHeightForWidth());
        gbxConsole->setSizePolicy(sizePolicy5);
        gbxConsole->setMinimumSize(QSize(0, 150));
        gridLayout_3 = new QGridLayout(gbxConsole);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        console = new ConsoleWidget(gbxConsole);
        console->setObjectName(QString::fromUtf8("console"));

        gridLayout_3->addWidget(console, 0, 0, 1, 1);

        splitter->addWidget(gbxConsole);

        horizontalLayout->addWidget(splitter);


        gridLayout_4->addLayout(horizontalLayout, 1, 0, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnSave = new QToolButton(ScriptsWidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setIconSize(QSize(32, 32));
        btnSave->setToolButtonStyle(Qt::ToolButtonIconOnly);
        btnSave->setAutoRaise(true);
        btnSave->setArrowType(Qt::NoArrow);

        verticalLayout->addWidget(btnSave);

        btnRun = new QToolButton(ScriptsWidget);
        btnRun->setObjectName(QString::fromUtf8("btnRun"));
        btnRun->setIconSize(QSize(32, 32));
        btnRun->setToolButtonStyle(Qt::ToolButtonIconOnly);
        btnRun->setAutoRaise(true);
        btnRun->setArrowType(Qt::NoArrow);

        verticalLayout->addWidget(btnRun);


        gridLayout_4->addLayout(verticalLayout, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 373, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 2, 1, 1, 1);


        retranslateUi(ScriptsWidget);

        QMetaObject::connectSlotsByName(ScriptsWidget);
    } // setupUi

    void retranslateUi(QWidget *ScriptsWidget)
    {
        ScriptsWidget->setWindowTitle(QApplication::translate("ScriptsWidget", "Form", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("ScriptsWidget", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("ScriptsWidget", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionRun->setText(QApplication::translate("ScriptsWidget", "Run", 0, QApplication::UnicodeUTF8));
        actionRun->setShortcut(QApplication::translate("ScriptsWidget", "F5", 0, QApplication::UnicodeUTF8));
        gbxListScripts->setTitle(QApplication::translate("ScriptsWidget", "Available scripts", 0, QApplication::UnicodeUTF8));
        gbxCode->setTitle(QApplication::translate("ScriptsWidget", "Source code", 0, QApplication::UnicodeUTF8));
        gbxConsole->setTitle(QApplication::translate("ScriptsWidget", "Script console", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("ScriptsWidget", "Save changes", 0, QApplication::UnicodeUTF8));
        btnRun->setText(QApplication::translate("ScriptsWidget", "Run script", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScriptsWidget: public Ui_ScriptsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTSWIDGET_H
