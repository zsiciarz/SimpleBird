/********************************************************************************
** Form generated from reading UI file 'FilesWidget.ui'
**
** Created: Thu 25. Mar 11:24:41 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESWIDGET_H
#define UI_FILESWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilesWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *listFiles;
    QVBoxLayout *verticalLayout;
    QToolButton *btnWaveform;
    QToolButton *btnCalculateFeatures;
    QToolButton *btnDrawSpectrogram;
    QToolButton *btnDrawFeatureChart;
    QToolButton *btnDrawDtwChart;
    QToolButton *btnCloseFile;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FilesWidget)
    {
        if (FilesWidget->objectName().isEmpty())
            FilesWidget->setObjectName(QString::fromUtf8("FilesWidget"));
        FilesWidget->resize(400, 329);
        horizontalLayout = new QHBoxLayout(FilesWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listFiles = new QListWidget(FilesWidget);
        listFiles->setObjectName(QString::fromUtf8("listFiles"));
        listFiles->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listFiles->setIconSize(QSize(32, 32));
        listFiles->setMovement(QListView::Static);
        listFiles->setGridSize(QSize(64, 64));
        listFiles->setViewMode(QListView::IconMode);

        horizontalLayout->addWidget(listFiles);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnWaveform = new QToolButton(FilesWidget);
        btnWaveform->setObjectName(QString::fromUtf8("btnWaveform"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/waveform.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWaveform->setIcon(icon);
        btnWaveform->setIconSize(QSize(32, 32));
        btnWaveform->setAutoRaise(true);

        verticalLayout->addWidget(btnWaveform);

        btnCalculateFeatures = new QToolButton(FilesWidget);
        btnCalculateFeatures->setObjectName(QString::fromUtf8("btnCalculateFeatures"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/calculator.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCalculateFeatures->setIcon(icon1);
        btnCalculateFeatures->setIconSize(QSize(32, 32));
        btnCalculateFeatures->setAutoRaise(true);

        verticalLayout->addWidget(btnCalculateFeatures);

        btnDrawSpectrogram = new QToolButton(FilesWidget);
        btnDrawSpectrogram->setObjectName(QString::fromUtf8("btnDrawSpectrogram"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/spectrogram.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDrawSpectrogram->setIcon(icon2);
        btnDrawSpectrogram->setIconSize(QSize(32, 32));
        btnDrawSpectrogram->setAutoRaise(true);

        verticalLayout->addWidget(btnDrawSpectrogram);

        btnDrawFeatureChart = new QToolButton(FilesWidget);
        btnDrawFeatureChart->setObjectName(QString::fromUtf8("btnDrawFeatureChart"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/feature_chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDrawFeatureChart->setIcon(icon3);
        btnDrawFeatureChart->setIconSize(QSize(32, 32));
        btnDrawFeatureChart->setAutoRaise(true);

        verticalLayout->addWidget(btnDrawFeatureChart);

        btnDrawDtwChart = new QToolButton(FilesWidget);
        btnDrawDtwChart->setObjectName(QString::fromUtf8("btnDrawDtwChart"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/dtw_chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDrawDtwChart->setIcon(icon4);
        btnDrawDtwChart->setIconSize(QSize(32, 32));
        btnDrawDtwChart->setAutoRaise(true);

        verticalLayout->addWidget(btnDrawDtwChart);

        btnCloseFile = new QToolButton(FilesWidget);
        btnCloseFile->setObjectName(QString::fromUtf8("btnCloseFile"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCloseFile->setIcon(icon5);
        btnCloseFile->setIconSize(QSize(32, 32));
        btnCloseFile->setAutoRaise(true);

        verticalLayout->addWidget(btnCloseFile);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(FilesWidget);

        QMetaObject::connectSlotsByName(FilesWidget);
    } // setupUi

    void retranslateUi(QWidget *FilesWidget)
    {
        FilesWidget->setWindowTitle(QApplication::translate("FilesWidget", "Form", 0, QApplication::UnicodeUTF8));
        btnWaveform->setText(QApplication::translate("FilesWidget", "Waveform", 0, QApplication::UnicodeUTF8));
        btnCalculateFeatures->setText(QApplication::translate("FilesWidget", "Waveform", 0, QApplication::UnicodeUTF8));
        btnDrawSpectrogram->setText(QApplication::translate("FilesWidget", "Spectrogram", 0, QApplication::UnicodeUTF8));
        btnDrawFeatureChart->setText(QApplication::translate("FilesWidget", "Feature chart", 0, QApplication::UnicodeUTF8));
        btnDrawDtwChart->setText(QApplication::translate("FilesWidget", "DTW chart", 0, QApplication::UnicodeUTF8));
        btnCloseFile->setText(QApplication::translate("FilesWidget", "Feature chart", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FilesWidget: public Ui_FilesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESWIDGET_H
