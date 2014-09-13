/********************************************************************************
** Form generated from reading UI file 'ConsoleWidget.ui'
**
** Created: Thu 25. Mar 11:24:41 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLEWIDGET_H
#define UI_CONSOLEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConsoleWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QTextEdit *txtConsole;
    QVBoxLayout *verticalLayout;
    QToolButton *btnClearConsole;
    QToolButton *btnSaveConsole;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ConsoleWidget)
    {
        if (ConsoleWidget->objectName().isEmpty())
            ConsoleWidget->setObjectName(QString::fromUtf8("ConsoleWidget"));
        ConsoleWidget->resize(537, 137);
        horizontalLayout = new QHBoxLayout(ConsoleWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        txtConsole = new QTextEdit(ConsoleWidget);
        txtConsole->setObjectName(QString::fromUtf8("txtConsole"));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(9);
        txtConsole->setFont(font);
        txtConsole->setReadOnly(true);

        horizontalLayout->addWidget(txtConsole);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnClearConsole = new QToolButton(ConsoleWidget);
        btnClearConsole->setObjectName(QString::fromUtf8("btnClearConsole"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/note_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearConsole->setIcon(icon);
        btnClearConsole->setIconSize(QSize(32, 32));
        btnClearConsole->setAutoRaise(true);

        verticalLayout->addWidget(btnClearConsole);

        btnSaveConsole = new QToolButton(ConsoleWidget);
        btnSaveConsole->setObjectName(QString::fromUtf8("btnSaveConsole"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSaveConsole->setIcon(icon1);
        btnSaveConsole->setIconSize(QSize(32, 32));
        btnSaveConsole->setAutoRaise(true);

        verticalLayout->addWidget(btnSaveConsole);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(ConsoleWidget);

        QMetaObject::connectSlotsByName(ConsoleWidget);
    } // setupUi

    void retranslateUi(QWidget *ConsoleWidget)
    {
        ConsoleWidget->setWindowTitle(QApplication::translate("ConsoleWidget", "Form", 0, QApplication::UnicodeUTF8));
        btnClearConsole->setText(QApplication::translate("ConsoleWidget", "Clear", 0, QApplication::UnicodeUTF8));
        btnSaveConsole->setText(QApplication::translate("ConsoleWidget", "Save log...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConsoleWidget: public Ui_ConsoleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLEWIDGET_H
