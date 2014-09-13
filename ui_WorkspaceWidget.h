/********************************************************************************
** Form generated from reading UI file 'WorkspaceWidget.ui'
**
** Created: Thu 25. Mar 11:24:41 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKSPACEWIDGET_H
#define UI_WORKSPACEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "widgets/workspace/WorkspaceTreeView.h"

QT_BEGIN_NAMESPACE

class Ui_WorkspaceWidget
{
public:
    QGridLayout *gridLayout;
    WorkspaceTreeView *workspaceTreeView;
    QVBoxLayout *verticalLayout;
    QToolButton *btnAddDirectory;
    QToolButton *btnLoadFile;
    QToolButton *btnRemoveFile;
    QToolButton *btnRefresh;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *WorkspaceWidget)
    {
        if (WorkspaceWidget->objectName().isEmpty())
            WorkspaceWidget->setObjectName(QString::fromUtf8("WorkspaceWidget"));
        WorkspaceWidget->resize(345, 292);
        gridLayout = new QGridLayout(WorkspaceWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        workspaceTreeView = new WorkspaceTreeView(WorkspaceWidget);
        workspaceTreeView->setObjectName(QString::fromUtf8("workspaceTreeView"));
        workspaceTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        workspaceTreeView->setIndentation(15);
        workspaceTreeView->setUniformRowHeights(true);
        workspaceTreeView->setAnimated(false);
        workspaceTreeView->setHeaderHidden(true);
        workspaceTreeView->setExpandsOnDoubleClick(false);

        gridLayout->addWidget(workspaceTreeView, 0, 0, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnAddDirectory = new QToolButton(WorkspaceWidget);
        btnAddDirectory->setObjectName(QString::fromUtf8("btnAddDirectory"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/folder_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddDirectory->setIcon(icon);
        btnAddDirectory->setIconSize(QSize(32, 32));
        btnAddDirectory->setToolButtonStyle(Qt::ToolButtonIconOnly);
        btnAddDirectory->setAutoRaise(true);
        btnAddDirectory->setArrowType(Qt::NoArrow);

        verticalLayout->addWidget(btnAddDirectory);

        btnLoadFile = new QToolButton(WorkspaceWidget);
        btnLoadFile->setObjectName(QString::fromUtf8("btnLoadFile"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/page_next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLoadFile->setIcon(icon1);
        btnLoadFile->setIconSize(QSize(32, 32));
        btnLoadFile->setAutoRaise(true);

        verticalLayout->addWidget(btnLoadFile);

        btnRemoveFile = new QToolButton(WorkspaceWidget);
        btnRemoveFile->setObjectName(QString::fromUtf8("btnRemoveFile"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/page_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemoveFile->setIcon(icon2);
        btnRemoveFile->setIconSize(QSize(32, 32));
        btnRemoveFile->setToolButtonStyle(Qt::ToolButtonIconOnly);
        btnRemoveFile->setAutoRaise(true);
        btnRemoveFile->setArrowType(Qt::NoArrow);

        verticalLayout->addWidget(btnRemoveFile);

        btnRefresh = new QToolButton(WorkspaceWidget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/repeat.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon3);
        btnRefresh->setIconSize(QSize(32, 32));
        btnRefresh->setToolButtonStyle(Qt::ToolButtonIconOnly);
        btnRefresh->setAutoRaise(true);
        btnRefresh->setArrowType(Qt::NoArrow);

        verticalLayout->addWidget(btnRefresh);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 185, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);


        retranslateUi(WorkspaceWidget);

        QMetaObject::connectSlotsByName(WorkspaceWidget);
    } // setupUi

    void retranslateUi(QWidget *WorkspaceWidget)
    {
        WorkspaceWidget->setWindowTitle(QApplication::translate("WorkspaceWidget", "WorkspaceWidget", 0, QApplication::UnicodeUTF8));
        btnAddDirectory->setText(QApplication::translate("WorkspaceWidget", "Add folder", 0, QApplication::UnicodeUTF8));
        btnLoadFile->setText(QApplication::translate("WorkspaceWidget", "Load selected file", 0, QApplication::UnicodeUTF8));
        btnRemoveFile->setText(QApplication::translate("WorkspaceWidget", "Remove selected", 0, QApplication::UnicodeUTF8));
        btnRefresh->setText(QApplication::translate("WorkspaceWidget", "Refresh view", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WorkspaceWidget: public Ui_WorkspaceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKSPACEWIDGET_H
