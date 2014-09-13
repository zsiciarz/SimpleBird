/********************************************************************************
** Form generated from reading UI file 'BenchmarkDialog.ui'
**
** Created: Thu 25. Mar 11:24:41 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BENCHMARKDIALOG_H
#define UI_BENCHMARKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BenchmarkDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *gbxBenchmarkSettings;
    QVBoxLayout *verticalLayout;
    QCheckBox *cbxFft;
    QCheckBox *cbxDct;
    QCheckBox *cbxWave;
    QCheckBox *cbxEnergy;
    QCheckBox *cbxMfcc;
    QCheckBox *cbxDtw;
    QHBoxLayout *horizontalLayout;
    QLabel *lblIterations;
    QSpinBox *editIterations;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BenchmarkDialog)
    {
        if (BenchmarkDialog->objectName().isEmpty())
            BenchmarkDialog->setObjectName(QString::fromUtf8("BenchmarkDialog"));
        BenchmarkDialog->resize(330, 214);
        verticalLayout_2 = new QVBoxLayout(BenchmarkDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gbxBenchmarkSettings = new QGroupBox(BenchmarkDialog);
        gbxBenchmarkSettings->setObjectName(QString::fromUtf8("gbxBenchmarkSettings"));
        verticalLayout = new QVBoxLayout(gbxBenchmarkSettings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cbxFft = new QCheckBox(gbxBenchmarkSettings);
        cbxFft->setObjectName(QString::fromUtf8("cbxFft"));
        cbxFft->setChecked(true);

        verticalLayout->addWidget(cbxFft);

        cbxDct = new QCheckBox(gbxBenchmarkSettings);
        cbxDct->setObjectName(QString::fromUtf8("cbxDct"));
        cbxDct->setChecked(true);

        verticalLayout->addWidget(cbxDct);

        cbxWave = new QCheckBox(gbxBenchmarkSettings);
        cbxWave->setObjectName(QString::fromUtf8("cbxWave"));
        cbxWave->setChecked(true);

        verticalLayout->addWidget(cbxWave);

        cbxEnergy = new QCheckBox(gbxBenchmarkSettings);
        cbxEnergy->setObjectName(QString::fromUtf8("cbxEnergy"));
        cbxEnergy->setChecked(true);

        verticalLayout->addWidget(cbxEnergy);

        cbxMfcc = new QCheckBox(gbxBenchmarkSettings);
        cbxMfcc->setObjectName(QString::fromUtf8("cbxMfcc"));
        cbxMfcc->setChecked(true);

        verticalLayout->addWidget(cbxMfcc);

        cbxDtw = new QCheckBox(gbxBenchmarkSettings);
        cbxDtw->setObjectName(QString::fromUtf8("cbxDtw"));
        cbxDtw->setChecked(true);

        verticalLayout->addWidget(cbxDtw);


        verticalLayout_2->addWidget(gbxBenchmarkSettings);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblIterations = new QLabel(BenchmarkDialog);
        lblIterations->setObjectName(QString::fromUtf8("lblIterations"));

        horizontalLayout->addWidget(lblIterations);

        editIterations = new QSpinBox(BenchmarkDialog);
        editIterations->setObjectName(QString::fromUtf8("editIterations"));
        editIterations->setMinimum(1);
        editIterations->setMaximum(1000);
        editIterations->setValue(100);

        horizontalLayout->addWidget(editIterations);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(BenchmarkDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(BenchmarkDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BenchmarkDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BenchmarkDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BenchmarkDialog);
    } // setupUi

    void retranslateUi(QDialog *BenchmarkDialog)
    {
        BenchmarkDialog->setWindowTitle(QApplication::translate("BenchmarkDialog", "Benchmark", 0, QApplication::UnicodeUTF8));
        gbxBenchmarkSettings->setTitle(QApplication::translate("BenchmarkDialog", "What to benchmark?", 0, QApplication::UnicodeUTF8));
        cbxFft->setText(QApplication::translate("BenchmarkDialog", "FFT", 0, QApplication::UnicodeUTF8));
        cbxDct->setText(QApplication::translate("BenchmarkDialog", "DCT", 0, QApplication::UnicodeUTF8));
        cbxWave->setText(QApplication::translate("BenchmarkDialog", "Wave file reading", 0, QApplication::UnicodeUTF8));
        cbxEnergy->setText(QApplication::translate("BenchmarkDialog", "Energy calculation", 0, QApplication::UnicodeUTF8));
        cbxMfcc->setText(QApplication::translate("BenchmarkDialog", "MFCC calculation", 0, QApplication::UnicodeUTF8));
        cbxDtw->setText(QApplication::translate("BenchmarkDialog", "DTW distance", 0, QApplication::UnicodeUTF8));
        lblIterations->setText(QApplication::translate("BenchmarkDialog", "Iterations:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BenchmarkDialog: public Ui_BenchmarkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BENCHMARKDIALOG_H
