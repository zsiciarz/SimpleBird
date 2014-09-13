/********************************************************************************
** Form generated from reading UI file 'simplebird.ui'
**
** Created: Thu 25. Mar 11:24:40 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEBIRD_H
#define UI_SIMPLEBIRD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "widgets/ExtractorPropertiesWidget.h"
#include "widgets/WavePropertiesWidget.h"
#include "widgets/console/ConsoleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SimpleBirdClass
{
public:
    QAction *actionTest;
    QAction *actionSpectrogram;
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionCalculateMFCC;
    QAction *actionChangelog;
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionPreferences;
    QAction *actionCalculateEnergy;
    QAction *actionCalculatePower;
    QAction *actionToolbars;
    QAction *actionFeatureChart;
    QAction *actionChangeWorkspace;
    QAction *actionDictionary;
    QAction *actionRecognizeCurrentFile;
    QAction *actionCalculateHFCC;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tabWorkspace;
    QWidget *tabFiles;
    QWidget *tabCharts;
    QWidget *tabScripts;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_Visualisations;
    QMenu *menu_Calculate;
    QMenu *menuHelp;
    QMenu *menuTools;
    QStatusBar *statusbar;
    QDockWidget *dockConsole;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout;
    ConsoleWidget *consoleWidget;
    QToolBar *toolBar;
    QDockWidget *dockProperties;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout;
    WavePropertiesWidget *tblWaveProperties;
    ExtractorPropertiesWidget *tblExtractorProperties;

    void setupUi(QMainWindow *SimpleBirdClass)
    {
        if (SimpleBirdClass->objectName().isEmpty())
            SimpleBirdClass->setObjectName(QString::fromUtf8("SimpleBirdClass"));
        SimpleBirdClass->resize(698, 609);
        actionTest = new QAction(SimpleBirdClass);
        actionTest->setObjectName(QString::fromUtf8("actionTest"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/favorite.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTest->setIcon(icon);
        actionSpectrogram = new QAction(SimpleBirdClass);
        actionSpectrogram->setObjectName(QString::fromUtf8("actionSpectrogram"));
        actionSpectrogram->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/spectrogram.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSpectrogram->setIcon(icon1);
        actionOpen = new QAction(SimpleBirdClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionExit = new QAction(SimpleBirdClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon3);
        actionCalculateMFCC = new QAction(SimpleBirdClass);
        actionCalculateMFCC->setObjectName(QString::fromUtf8("actionCalculateMFCC"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/calculator.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCalculateMFCC->setIcon(icon4);
        actionChangelog = new QAction(SimpleBirdClass);
        actionChangelog->setObjectName(QString::fromUtf8("actionChangelog"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChangelog->setIcon(icon5);
        actionAbout = new QAction(SimpleBirdClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon6);
        actionAboutQt = new QAction(SimpleBirdClass);
        actionAboutQt->setObjectName(QString::fromUtf8("actionAboutQt"));
        actionPreferences = new QAction(SimpleBirdClass);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/process.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPreferences->setIcon(icon7);
        actionCalculateEnergy = new QAction(SimpleBirdClass);
        actionCalculateEnergy->setObjectName(QString::fromUtf8("actionCalculateEnergy"));
        actionCalculateEnergy->setIcon(icon4);
        actionCalculatePower = new QAction(SimpleBirdClass);
        actionCalculatePower->setObjectName(QString::fromUtf8("actionCalculatePower"));
        actionCalculatePower->setIcon(icon4);
        actionToolbars = new QAction(SimpleBirdClass);
        actionToolbars->setObjectName(QString::fromUtf8("actionToolbars"));
        actionFeatureChart = new QAction(SimpleBirdClass);
        actionFeatureChart->setObjectName(QString::fromUtf8("actionFeatureChart"));
        actionFeatureChart->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/feature_chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFeatureChart->setIcon(icon8);
        actionChangeWorkspace = new QAction(SimpleBirdClass);
        actionChangeWorkspace->setObjectName(QString::fromUtf8("actionChangeWorkspace"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/folder_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChangeWorkspace->setIcon(icon9);
        actionDictionary = new QAction(SimpleBirdClass);
        actionDictionary->setObjectName(QString::fromUtf8("actionDictionary"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/database.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDictionary->setIcon(icon10);
        actionRecognizeCurrentFile = new QAction(SimpleBirdClass);
        actionRecognizeCurrentFile->setObjectName(QString::fromUtf8("actionRecognizeCurrentFile"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRecognizeCurrentFile->setIcon(icon11);
        actionCalculateHFCC = new QAction(SimpleBirdClass);
        actionCalculateHFCC->setObjectName(QString::fromUtf8("actionCalculateHFCC"));
        actionCalculateHFCC->setIcon(icon4);
        centralwidget = new QWidget(SimpleBirdClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 401, 291));
        tabWidget->setTabsClosable(false);
        tabWorkspace = new QWidget();
        tabWorkspace->setObjectName(QString::fromUtf8("tabWorkspace"));
        tabWidget->addTab(tabWorkspace, icon2, QString());
        tabFiles = new QWidget();
        tabFiles->setObjectName(QString::fromUtf8("tabFiles"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/page.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabFiles, icon12, QString());
        tabCharts = new QWidget();
        tabCharts->setObjectName(QString::fromUtf8("tabCharts"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabCharts, icon13, QString());
        tabScripts = new QWidget();
        tabScripts->setObjectName(QString::fromUtf8("tabScripts"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/script.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabScripts, icon14, QString());
        SimpleBirdClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SimpleBirdClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 698, 21));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Visualisations = new QMenu(menubar);
        menu_Visualisations->setObjectName(QString::fromUtf8("menu_Visualisations"));
        menu_Visualisations->setEnabled(false);
        menu_Calculate = new QMenu(menubar);
        menu_Calculate->setObjectName(QString::fromUtf8("menu_Calculate"));
        menu_Calculate->setEnabled(false);
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        SimpleBirdClass->setMenuBar(menubar);
        statusbar = new QStatusBar(SimpleBirdClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SimpleBirdClass->setStatusBar(statusbar);
        dockConsole = new QDockWidget(SimpleBirdClass);
        dockConsole->setObjectName(QString::fromUtf8("dockConsole"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        consoleWidget = new ConsoleWidget(dockWidgetContents);
        consoleWidget->setObjectName(QString::fromUtf8("consoleWidget"));

        horizontalLayout->addWidget(consoleWidget);

        dockConsole->setWidget(dockWidgetContents);
        SimpleBirdClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockConsole);
        toolBar = new QToolBar(SimpleBirdClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        SimpleBirdClass->addToolBar(Qt::TopToolBarArea, toolBar);
        dockProperties = new QDockWidget(SimpleBirdClass);
        dockProperties->setObjectName(QString::fromUtf8("dockProperties"));
        dockProperties->setMinimumSize(QSize(250, 188));
        dockProperties->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        gridLayout = new QGridLayout(dockWidgetContents_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tblWaveProperties = new WavePropertiesWidget(dockWidgetContents_2);
        tblWaveProperties->setObjectName(QString::fromUtf8("tblWaveProperties"));

        gridLayout->addWidget(tblWaveProperties, 0, 0, 1, 1);

        tblExtractorProperties = new ExtractorPropertiesWidget(dockWidgetContents_2);
        tblExtractorProperties->setObjectName(QString::fromUtf8("tblExtractorProperties"));

        gridLayout->addWidget(tblExtractorProperties, 1, 0, 1, 1);

        dockProperties->setWidget(dockWidgetContents_2);
        SimpleBirdClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockProperties);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_Visualisations->menuAction());
        menubar->addAction(menu_Calculate->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menu_File->addAction(actionChangeWorkspace);
        menu_File->addSeparator();
        menu_File->addAction(actionOpen);
        menu_File->addAction(actionTest);
        menu_File->addSeparator();
        menu_File->addAction(actionExit);
        menu_Visualisations->addAction(actionSpectrogram);
        menu_Visualisations->addAction(actionFeatureChart);
        menu_Calculate->addAction(actionCalculateEnergy);
        menu_Calculate->addAction(actionCalculatePower);
        menu_Calculate->addAction(actionCalculateMFCC);
        menu_Calculate->addAction(actionCalculateHFCC);
        menuHelp->addAction(actionChangelog);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);
        menuTools->addAction(actionToolbars);
        menuTools->addSeparator();
        menuTools->addAction(actionDictionary);
        menuTools->addAction(actionPreferences);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionChangeWorkspace);
        toolBar->addAction(actionTest);
        toolBar->addAction(actionSpectrogram);
        toolBar->addAction(actionFeatureChart);
        toolBar->addSeparator();
        toolBar->addAction(actionRecognizeCurrentFile);
        toolBar->addAction(actionDictionary);
        toolBar->addAction(actionPreferences);
        toolBar->addSeparator();
        toolBar->addAction(actionExit);

        retranslateUi(SimpleBirdClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SimpleBirdClass);
    } // setupUi

    void retranslateUi(QMainWindow *SimpleBirdClass)
    {
        SimpleBirdClass->setWindowTitle(QApplication::translate("SimpleBirdClass", "SimpleBird", 0, QApplication::UnicodeUTF8));
        actionTest->setText(QApplication::translate("SimpleBirdClass", "Test", 0, QApplication::UnicodeUTF8));
        actionSpectrogram->setText(QApplication::translate("SimpleBirdClass", "Spectrogram", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("SimpleBirdClass", "&Open...", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("SimpleBirdClass", "&Exit", 0, QApplication::UnicodeUTF8));
        actionCalculateMFCC->setText(QApplication::translate("SimpleBirdClass", "MFCC", 0, QApplication::UnicodeUTF8));
        actionChangelog->setText(QApplication::translate("SimpleBirdClass", "Changelog", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("SimpleBirdClass", "About", 0, QApplication::UnicodeUTF8));
        actionAboutQt->setText(QApplication::translate("SimpleBirdClass", "About Qt", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAboutQt->setToolTip(QApplication::translate("SimpleBirdClass", "About Qt", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPreferences->setText(QApplication::translate("SimpleBirdClass", "Preferences", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPreferences->setToolTip(QApplication::translate("SimpleBirdClass", "Preferences", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCalculateEnergy->setText(QApplication::translate("SimpleBirdClass", "Energy", 0, QApplication::UnicodeUTF8));
        actionCalculatePower->setText(QApplication::translate("SimpleBirdClass", "Power", 0, QApplication::UnicodeUTF8));
        actionToolbars->setText(QApplication::translate("SimpleBirdClass", "Toolbars", 0, QApplication::UnicodeUTF8));
        actionFeatureChart->setText(QApplication::translate("SimpleBirdClass", "Feature chart", 0, QApplication::UnicodeUTF8));
        actionChangeWorkspace->setText(QApplication::translate("SimpleBirdClass", "Change workspace directory", 0, QApplication::UnicodeUTF8));
        actionDictionary->setText(QApplication::translate("SimpleBirdClass", "Dictionary...", 0, QApplication::UnicodeUTF8));
        actionRecognizeCurrentFile->setText(QApplication::translate("SimpleBirdClass", "Recognize current file", 0, QApplication::UnicodeUTF8));
        actionCalculateHFCC->setText(QApplication::translate("SimpleBirdClass", "HFCC", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCalculateHFCC->setToolTip(QApplication::translate("SimpleBirdClass", "HFCC", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tabWorkspace), QApplication::translate("SimpleBirdClass", "Workspace", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabFiles), QApplication::translate("SimpleBirdClass", "Files", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabCharts), QApplication::translate("SimpleBirdClass", "Charts", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabScripts), QApplication::translate("SimpleBirdClass", "Scripts", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("SimpleBirdClass", "&File", 0, QApplication::UnicodeUTF8));
        menu_Visualisations->setTitle(QApplication::translate("SimpleBirdClass", "&Visualisations", 0, QApplication::UnicodeUTF8));
        menu_Calculate->setTitle(QApplication::translate("SimpleBirdClass", "&Calculate", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("SimpleBirdClass", "Help", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("SimpleBirdClass", "Tools", 0, QApplication::UnicodeUTF8));
        dockConsole->setWindowTitle(QApplication::translate("SimpleBirdClass", "Console", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("SimpleBirdClass", "Main Toolbar", 0, QApplication::UnicodeUTF8));
        dockProperties->setWindowTitle(QApplication::translate("SimpleBirdClass", "Properties", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SimpleBirdClass: public Ui_SimpleBirdClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEBIRD_H
