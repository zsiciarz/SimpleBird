/********************************************************************************
** Form generated from reading UI file 'ChartsWidget.ui'
**
** Created: Thu 25. Mar 11:24:41 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTSWIDGET_H
#define UI_CHARTSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartsWidget
{
public:
    QAction *actionSave;
    QAction *actionRefresh;
    QAction *actionPrint;
    QAction *actionCloseAll;
    QGridLayout *gridLayout;
    QTabWidget *tabCharts;
    QWidget *tabInitial;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *lblInitial;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnGoToWorkspace;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QToolButton *btnSave;
    QToolButton *btnRefresh;
    QToolButton *btnPrint;
    QFrame *line;
    QToolButton *btnCloseAll;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ChartsWidget)
    {
        if (ChartsWidget->objectName().isEmpty())
            ChartsWidget->setObjectName(QString::fromUtf8("ChartsWidget"));
        ChartsWidget->resize(477, 415);
        actionSave = new QAction(ChartsWidget);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        actionRefresh = new QAction(ChartsWidget);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/repeat.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon1);
        actionPrint = new QAction(ChartsWidget);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon2);
        actionCloseAll = new QAction(ChartsWidget);
        actionCloseAll->setObjectName(QString::fromUtf8("actionCloseAll"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/chart_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCloseAll->setIcon(icon3);
        gridLayout = new QGridLayout(ChartsWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabCharts = new QTabWidget(ChartsWidget);
        tabCharts->setObjectName(QString::fromUtf8("tabCharts"));
        tabCharts->setTabsClosable(true);
        tabInitial = new QWidget();
        tabInitial->setObjectName(QString::fromUtf8("tabInitial"));
        verticalLayout_2 = new QVBoxLayout(tabInitial);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 128, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        lblInitial = new QLabel(tabInitial);
        lblInitial->setObjectName(QString::fromUtf8("lblInitial"));
        lblInitial->setAlignment(Qt::AlignCenter);
        lblInitial->setWordWrap(true);

        verticalLayout_2->addWidget(lblInitial);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnGoToWorkspace = new QPushButton(tabInitial);
        btnGoToWorkspace->setObjectName(QString::fromUtf8("btnGoToWorkspace"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnGoToWorkspace->sizePolicy().hasHeightForWidth());
        btnGoToWorkspace->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGoToWorkspace->setIcon(icon4);
        btnGoToWorkspace->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(btnGoToWorkspace);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 128, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        tabCharts->addTab(tabInitial, QString());

        gridLayout->addWidget(tabCharts, 0, 0, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnSave = new QToolButton(ChartsWidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setIcon(icon);
        btnSave->setIconSize(QSize(32, 32));
        btnSave->setAutoRaise(true);

        verticalLayout->addWidget(btnSave);

        btnRefresh = new QToolButton(ChartsWidget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        btnRefresh->setIcon(icon1);
        btnRefresh->setIconSize(QSize(32, 32));
        btnRefresh->setAutoRaise(true);

        verticalLayout->addWidget(btnRefresh);

        btnPrint = new QToolButton(ChartsWidget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        btnPrint->setIcon(icon2);
        btnPrint->setIconSize(QSize(32, 32));
        btnPrint->setAutoRaise(true);

        verticalLayout->addWidget(btnPrint);

        line = new QFrame(ChartsWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        btnCloseAll = new QToolButton(ChartsWidget);
        btnCloseAll->setObjectName(QString::fromUtf8("btnCloseAll"));
        btnCloseAll->setIcon(icon3);
        btnCloseAll->setIconSize(QSize(32, 32));
        btnCloseAll->setAutoRaise(true);

        verticalLayout->addWidget(btnCloseAll);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 260, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);


        retranslateUi(ChartsWidget);

        tabCharts->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ChartsWidget);
    } // setupUi

    void retranslateUi(QWidget *ChartsWidget)
    {
        ChartsWidget->setWindowTitle(QApplication::translate("ChartsWidget", "Form", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("ChartsWidget", "Save image...", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("ChartsWidget", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        actionRefresh->setText(QApplication::translate("ChartsWidget", "Refresh", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("ChartsWidget", "Print image...", 0, QApplication::UnicodeUTF8));
        actionPrint->setShortcut(QApplication::translate("ChartsWidget", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionCloseAll->setText(QApplication::translate("ChartsWidget", "Close all charts", 0, QApplication::UnicodeUTF8));
        lblInitial->setText(QApplication::translate("ChartsWidget", "There are no charts to display. You can now go to workspace and open a wave file to draw waveform chart.", 0, QApplication::UnicodeUTF8));
        btnGoToWorkspace->setText(QApplication::translate("ChartsWidget", "Go to workspace", 0, QApplication::UnicodeUTF8));
        tabCharts->setTabText(tabCharts->indexOf(tabInitial), QApplication::translate("ChartsWidget", "No charts", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("ChartsWidget", "Save image...", 0, QApplication::UnicodeUTF8));
        btnRefresh->setText(QApplication::translate("ChartsWidget", "Refresh", 0, QApplication::UnicodeUTF8));
        btnPrint->setText(QApplication::translate("ChartsWidget", "Print image...", 0, QApplication::UnicodeUTF8));
        btnCloseAll->setText(QApplication::translate("ChartsWidget", "Close all charts", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChartsWidget: public Ui_ChartsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTSWIDGET_H
