/********************************************************************************
** Form generated from reading UI file 'PreferencesDialog.ui'
**
** Created: Thu 25. Mar 11:24:41 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCESDIALOG_H
#define UI_PREFERENCESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "widgets/color/ColorWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PreferencesDialog
{
public:
    QGridLayout *gridLayout;
    QListWidget *listPages;
    QStackedWidget *stackedWidget;
    QWidget *pageGeneral;
    QVBoxLayout *verticalLayout;
    QGroupBox *gbxGeneral;
    QFormLayout *formLayout_6;
    QLabel *lblVerbosity;
    QComboBox *cbxVerbosity;
    QWidget *pageSound;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *gbxSound;
    QFormLayout *formLayout;
    QLabel *lblFrameLength;
    QSpinBox *editFrameLength;
    QLabel *lblWindowType;
    QComboBox *cbxWindowType;
    QLabel *lblPreemphasis;
    QDoubleSpinBox *editPreemphasis;
    QLabel *lblFrameOverlap;
    QDoubleSpinBox *editFrameOverlap;
    QPushButton *btnMelFilters;
    QLabel *lblMelFilters;
    QLabel *lblParamsPerFrame;
    QSpinBox *editParamsPerFrame;
    QWidget *pageDtw;
    QGridLayout *gridLayout_4;
    QGroupBox *gbxDtw;
    QFormLayout *formLayout_4;
    QLabel *lblDistanceType;
    QComboBox *cbxDistanceType;
    QLabel *lblNormalizationType;
    QComboBox *cbxNormalizationType;
    QLabel *lblPassType;
    QComboBox *cbxPassType;
    QWidget *pageRecognizing;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *gbxRecognizing;
    QFormLayout *formLayout_5;
    QLabel *lblMinPatternSize;
    QLabel *lblMaxPatternSize;
    QDoubleSpinBox *editMinPatternSize;
    QDoubleSpinBox *editMaxPatternSize;
    QWidget *pageCharts;
    QGridLayout *gridLayout_2;
    QGroupBox *gbxCharts;
    QFormLayout *formLayout_2;
    QCheckBox *cbxChartsOverlay;
    QLabel *lblDefaultImageType;
    QComboBox *cbxDefaultImageType;
    QCheckBox *cbxDrawDtwAccumulated;
    QWidget *pageAppearance;
    QGridLayout *gridLayout_3;
    QGroupBox *gbxAppearance;
    QFormLayout *formLayout_3;
    QCheckBox *cbxUseStylesheet;
    QLabel *lblStylesheet;
    QComboBox *cbxStylesheet;
    QLabel *lblWaveFormColor;
    ColorWidget *colorWaveform;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PreferencesDialog)
    {
        if (PreferencesDialog->objectName().isEmpty())
            PreferencesDialog->setObjectName(QString::fromUtf8("PreferencesDialog"));
        PreferencesDialog->resize(550, 342);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/process.png"), QSize(), QIcon::Normal, QIcon::Off);
        PreferencesDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(PreferencesDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listPages = new QListWidget(PreferencesDialog);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/computer.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listPages);
        __qlistwidgetitem->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listPages);
        __qlistwidgetitem1->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/dtw_chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listPages);
        __qlistwidgetitem2->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listPages);
        __qlistwidgetitem3->setIcon(icon4);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listPages);
        __qlistwidgetitem4->setIcon(icon5);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/application_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listPages);
        __qlistwidgetitem5->setIcon(icon6);
        listPages->setObjectName(QString::fromUtf8("listPages"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listPages->sizePolicy().hasHeightForWidth());
        listPages->setSizePolicy(sizePolicy);
        listPages->setMaximumSize(QSize(130, 16777215));
        listPages->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listPages->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listPages->setProperty("showDropIndicator", QVariant(false));
        listPages->setDragDropMode(QAbstractItemView::NoDragDrop);
        listPages->setAlternatingRowColors(false);
        listPages->setSelectionBehavior(QAbstractItemView::SelectRows);
        listPages->setIconSize(QSize(32, 32));
        listPages->setMovement(QListView::Static);
        listPages->setFlow(QListView::TopToBottom);
        listPages->setProperty("isWrapping", QVariant(false));
        listPages->setResizeMode(QListView::Adjust);
        listPages->setSpacing(5);
        listPages->setViewMode(QListView::ListMode);
        listPages->setUniformItemSizes(true);
        listPages->setWordWrap(true);
        listPages->setSelectionRectVisible(false);
        listPages->setSortingEnabled(false);

        gridLayout->addWidget(listPages, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(PreferencesDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(5);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        pageGeneral = new QWidget();
        pageGeneral->setObjectName(QString::fromUtf8("pageGeneral"));
        verticalLayout = new QVBoxLayout(pageGeneral);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gbxGeneral = new QGroupBox(pageGeneral);
        gbxGeneral->setObjectName(QString::fromUtf8("gbxGeneral"));
        formLayout_6 = new QFormLayout(gbxGeneral);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        lblVerbosity = new QLabel(gbxGeneral);
        lblVerbosity->setObjectName(QString::fromUtf8("lblVerbosity"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, lblVerbosity);

        cbxVerbosity = new QComboBox(gbxGeneral);
        cbxVerbosity->setObjectName(QString::fromUtf8("cbxVerbosity"));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, cbxVerbosity);


        verticalLayout->addWidget(gbxGeneral);

        stackedWidget->addWidget(pageGeneral);
        pageSound = new QWidget();
        pageSound->setObjectName(QString::fromUtf8("pageSound"));
        verticalLayout_2 = new QVBoxLayout(pageSound);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gbxSound = new QGroupBox(pageSound);
        gbxSound->setObjectName(QString::fromUtf8("gbxSound"));
        formLayout = new QFormLayout(gbxSound);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lblFrameLength = new QLabel(gbxSound);
        lblFrameLength->setObjectName(QString::fromUtf8("lblFrameLength"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblFrameLength);

        editFrameLength = new QSpinBox(gbxSound);
        editFrameLength->setObjectName(QString::fromUtf8("editFrameLength"));
        editFrameLength->setMinimum(5);
        editFrameLength->setMaximum(600);
        editFrameLength->setValue(20);

        formLayout->setWidget(0, QFormLayout::FieldRole, editFrameLength);

        lblWindowType = new QLabel(gbxSound);
        lblWindowType->setObjectName(QString::fromUtf8("lblWindowType"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblWindowType);

        cbxWindowType = new QComboBox(gbxSound);
        cbxWindowType->setObjectName(QString::fromUtf8("cbxWindowType"));

        formLayout->setWidget(2, QFormLayout::FieldRole, cbxWindowType);

        lblPreemphasis = new QLabel(gbxSound);
        lblPreemphasis->setObjectName(QString::fromUtf8("lblPreemphasis"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lblPreemphasis);

        editPreemphasis = new QDoubleSpinBox(gbxSound);
        editPreemphasis->setObjectName(QString::fromUtf8("editPreemphasis"));
        editPreemphasis->setDecimals(4);
        editPreemphasis->setMaximum(1);
        editPreemphasis->setSingleStep(0.001);
        editPreemphasis->setValue(0.9375);

        formLayout->setWidget(3, QFormLayout::FieldRole, editPreemphasis);

        lblFrameOverlap = new QLabel(gbxSound);
        lblFrameOverlap->setObjectName(QString::fromUtf8("lblFrameOverlap"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblFrameOverlap);

        editFrameOverlap = new QDoubleSpinBox(gbxSound);
        editFrameOverlap->setObjectName(QString::fromUtf8("editFrameOverlap"));
        editFrameOverlap->setMaximum(1);
        editFrameOverlap->setSingleStep(0.01);
        editFrameOverlap->setValue(0.66);

        formLayout->setWidget(1, QFormLayout::FieldRole, editFrameOverlap);

        btnMelFilters = new QPushButton(gbxSound);
        btnMelFilters->setObjectName(QString::fromUtf8("btnMelFilters"));

        formLayout->setWidget(4, QFormLayout::FieldRole, btnMelFilters);

        lblMelFilters = new QLabel(gbxSound);
        lblMelFilters->setObjectName(QString::fromUtf8("lblMelFilters"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lblMelFilters);

        lblParamsPerFrame = new QLabel(gbxSound);
        lblParamsPerFrame->setObjectName(QString::fromUtf8("lblParamsPerFrame"));

        formLayout->setWidget(5, QFormLayout::LabelRole, lblParamsPerFrame);

        editParamsPerFrame = new QSpinBox(gbxSound);
        editParamsPerFrame->setObjectName(QString::fromUtf8("editParamsPerFrame"));
        editParamsPerFrame->setMinimum(1);
        editParamsPerFrame->setMaximum(25);

        formLayout->setWidget(5, QFormLayout::FieldRole, editParamsPerFrame);


        verticalLayout_2->addWidget(gbxSound);

        stackedWidget->addWidget(pageSound);
        pageDtw = new QWidget();
        pageDtw->setObjectName(QString::fromUtf8("pageDtw"));
        gridLayout_4 = new QGridLayout(pageDtw);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gbxDtw = new QGroupBox(pageDtw);
        gbxDtw->setObjectName(QString::fromUtf8("gbxDtw"));
        formLayout_4 = new QFormLayout(gbxDtw);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        lblDistanceType = new QLabel(gbxDtw);
        lblDistanceType->setObjectName(QString::fromUtf8("lblDistanceType"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, lblDistanceType);

        cbxDistanceType = new QComboBox(gbxDtw);
        cbxDistanceType->setObjectName(QString::fromUtf8("cbxDistanceType"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, cbxDistanceType);

        lblNormalizationType = new QLabel(gbxDtw);
        lblNormalizationType->setObjectName(QString::fromUtf8("lblNormalizationType"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, lblNormalizationType);

        cbxNormalizationType = new QComboBox(gbxDtw);
        cbxNormalizationType->setObjectName(QString::fromUtf8("cbxNormalizationType"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, cbxNormalizationType);

        lblPassType = new QLabel(gbxDtw);
        lblPassType->setObjectName(QString::fromUtf8("lblPassType"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, lblPassType);

        cbxPassType = new QComboBox(gbxDtw);
        cbxPassType->setObjectName(QString::fromUtf8("cbxPassType"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, cbxPassType);


        gridLayout_4->addWidget(gbxDtw, 0, 0, 1, 1);

        stackedWidget->addWidget(pageDtw);
        pageRecognizing = new QWidget();
        pageRecognizing->setObjectName(QString::fromUtf8("pageRecognizing"));
        verticalLayout_3 = new QVBoxLayout(pageRecognizing);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gbxRecognizing = new QGroupBox(pageRecognizing);
        gbxRecognizing->setObjectName(QString::fromUtf8("gbxRecognizing"));
        formLayout_5 = new QFormLayout(gbxRecognizing);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        lblMinPatternSize = new QLabel(gbxRecognizing);
        lblMinPatternSize->setObjectName(QString::fromUtf8("lblMinPatternSize"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, lblMinPatternSize);

        lblMaxPatternSize = new QLabel(gbxRecognizing);
        lblMaxPatternSize->setObjectName(QString::fromUtf8("lblMaxPatternSize"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, lblMaxPatternSize);

        editMinPatternSize = new QDoubleSpinBox(gbxRecognizing);
        editMinPatternSize->setObjectName(QString::fromUtf8("editMinPatternSize"));
        editMinPatternSize->setDecimals(0);
        editMinPatternSize->setValue(60);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, editMinPatternSize);

        editMaxPatternSize = new QDoubleSpinBox(gbxRecognizing);
        editMaxPatternSize->setObjectName(QString::fromUtf8("editMaxPatternSize"));
        editMaxPatternSize->setDecimals(0);
        editMaxPatternSize->setMinimum(100);
        editMaxPatternSize->setMaximum(666);
        editMaxPatternSize->setValue(140);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, editMaxPatternSize);


        verticalLayout_3->addWidget(gbxRecognizing);

        stackedWidget->addWidget(pageRecognizing);
        pageCharts = new QWidget();
        pageCharts->setObjectName(QString::fromUtf8("pageCharts"));
        gridLayout_2 = new QGridLayout(pageCharts);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gbxCharts = new QGroupBox(pageCharts);
        gbxCharts->setObjectName(QString::fromUtf8("gbxCharts"));
        formLayout_2 = new QFormLayout(gbxCharts);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        cbxChartsOverlay = new QCheckBox(gbxCharts);
        cbxChartsOverlay->setObjectName(QString::fromUtf8("cbxChartsOverlay"));
        cbxChartsOverlay->setChecked(true);

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, cbxChartsOverlay);

        lblDefaultImageType = new QLabel(gbxCharts);
        lblDefaultImageType->setObjectName(QString::fromUtf8("lblDefaultImageType"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, lblDefaultImageType);

        cbxDefaultImageType = new QComboBox(gbxCharts);
        cbxDefaultImageType->setObjectName(QString::fromUtf8("cbxDefaultImageType"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, cbxDefaultImageType);

        cbxDrawDtwAccumulated = new QCheckBox(gbxCharts);
        cbxDrawDtwAccumulated->setObjectName(QString::fromUtf8("cbxDrawDtwAccumulated"));
        cbxDrawDtwAccumulated->setChecked(false);

        formLayout_2->setWidget(2, QFormLayout::SpanningRole, cbxDrawDtwAccumulated);


        gridLayout_2->addWidget(gbxCharts, 0, 0, 1, 1);

        stackedWidget->addWidget(pageCharts);
        pageAppearance = new QWidget();
        pageAppearance->setObjectName(QString::fromUtf8("pageAppearance"));
        gridLayout_3 = new QGridLayout(pageAppearance);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gbxAppearance = new QGroupBox(pageAppearance);
        gbxAppearance->setObjectName(QString::fromUtf8("gbxAppearance"));
        formLayout_3 = new QFormLayout(gbxAppearance);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        cbxUseStylesheet = new QCheckBox(gbxAppearance);
        cbxUseStylesheet->setObjectName(QString::fromUtf8("cbxUseStylesheet"));
        cbxUseStylesheet->setChecked(true);

        formLayout_3->setWidget(0, QFormLayout::SpanningRole, cbxUseStylesheet);

        lblStylesheet = new QLabel(gbxAppearance);
        lblStylesheet->setObjectName(QString::fromUtf8("lblStylesheet"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, lblStylesheet);

        cbxStylesheet = new QComboBox(gbxAppearance);
        cbxStylesheet->setObjectName(QString::fromUtf8("cbxStylesheet"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, cbxStylesheet);

        lblWaveFormColor = new QLabel(gbxAppearance);
        lblWaveFormColor->setObjectName(QString::fromUtf8("lblWaveFormColor"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, lblWaveFormColor);

        colorWaveform = new ColorWidget(gbxAppearance);
        colorWaveform->setObjectName(QString::fromUtf8("colorWaveform"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, colorWaveform);


        gridLayout_3->addWidget(gbxAppearance, 0, 0, 1, 1);

        stackedWidget->addWidget(pageAppearance);

        gridLayout->addWidget(stackedWidget, 0, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 2);

        buttonBox = new QDialogButtonBox(PreferencesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::RestoreDefaults);

        gridLayout->addWidget(buttonBox, 1, 2, 1, 1);


        retranslateUi(PreferencesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PreferencesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PreferencesDialog, SLOT(reject()));
        QObject::connect(listPages, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(cbxUseStylesheet, SIGNAL(toggled(bool)), cbxStylesheet, SLOT(setDisabled(bool)));

        listPages->setCurrentRow(-1);
        stackedWidget->setCurrentIndex(0);
        cbxVerbosity->setCurrentIndex(1);
        cbxWindowType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PreferencesDialog);
    } // setupUi

    void retranslateUi(QDialog *PreferencesDialog)
    {
        PreferencesDialog->setWindowTitle(QApplication::translate("PreferencesDialog", "Program preferences", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listPages->isSortingEnabled();
        listPages->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listPages->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("PreferencesDialog", "General", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listPages->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("PreferencesDialog", "Sound", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listPages->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("PreferencesDialog", "DTW", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listPages->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("PreferencesDialog", "Recognizing", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = listPages->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("PreferencesDialog", "Charts", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem5 = listPages->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("PreferencesDialog", "Appearance", 0, QApplication::UnicodeUTF8));
        listPages->setSortingEnabled(__sortingEnabled);

        gbxGeneral->setTitle(QApplication::translate("PreferencesDialog", "General configuration", 0, QApplication::UnicodeUTF8));
        lblVerbosity->setText(QApplication::translate("PreferencesDialog", "Message verbosity:", 0, QApplication::UnicodeUTF8));
        cbxVerbosity->clear();
        cbxVerbosity->insertItems(0, QStringList()
         << QApplication::translate("PreferencesDialog", "Low", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "Medium", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "High", 0, QApplication::UnicodeUTF8)
        );
        gbxSound->setTitle(QApplication::translate("PreferencesDialog", "Sound settings", 0, QApplication::UnicodeUTF8));
        lblFrameLength->setText(QApplication::translate("PreferencesDialog", "Frame length:", 0, QApplication::UnicodeUTF8));
        editFrameLength->setSuffix(QApplication::translate("PreferencesDialog", " ms", 0, QApplication::UnicodeUTF8));
        lblWindowType->setText(QApplication::translate("PreferencesDialog", "Window function type:", 0, QApplication::UnicodeUTF8));
        cbxWindowType->clear();
        cbxWindowType->insertItems(0, QStringList()
         << QApplication::translate("PreferencesDialog", "Rectangular", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "Hamming", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "Hann", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "Blackman", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "Barlett", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "Flat-top", 0, QApplication::UnicodeUTF8)
        );
        lblPreemphasis->setText(QApplication::translate("PreferencesDialog", "Preemphasis factor:", 0, QApplication::UnicodeUTF8));
        lblFrameOverlap->setText(QApplication::translate("PreferencesDialog", "Frame overlap:", 0, QApplication::UnicodeUTF8));
        btnMelFilters->setText(QApplication::translate("PreferencesDialog", "Choose enabled Mel filters...", 0, QApplication::UnicodeUTF8));
        lblMelFilters->setText(QApplication::translate("PreferencesDialog", "Mel filters:", 0, QApplication::UnicodeUTF8));
        lblParamsPerFrame->setText(QApplication::translate("PreferencesDialog", "Parameters per frame:", 0, QApplication::UnicodeUTF8));
        gbxDtw->setTitle(QApplication::translate("PreferencesDialog", "DTW settings", 0, QApplication::UnicodeUTF8));
        lblDistanceType->setText(QApplication::translate("PreferencesDialog", "Distance type:", 0, QApplication::UnicodeUTF8));
        cbxDistanceType->clear();
        cbxDistanceType->insertItems(0, QStringList()
         << QApplication::translate("PreferencesDialog", "Euclidean", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "Manhattan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "Chebyshev", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "Minkowski", 0, QApplication::UnicodeUTF8)
        );
        lblNormalizationType->setText(QApplication::translate("PreferencesDialog", "Normalization type:", 0, QApplication::UnicodeUTF8));
        cbxNormalizationType->clear();
        cbxNormalizationType->insertItems(0, QStringList()
         << QApplication::translate("PreferencesDialog", "No normalization", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "Diagonal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "Sum of sides", 0, QApplication::UnicodeUTF8)
        );
        lblPassType->setText(QApplication::translate("PreferencesDialog", "Pass type:", 0, QApplication::UnicodeUTF8));
        cbxPassType->clear();
        cbxPassType->insertItems(0, QStringList()
         << QApplication::translate("PreferencesDialog", "Neighbors", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "Diagonals", 0, QApplication::UnicodeUTF8)
        );
        gbxRecognizing->setTitle(QApplication::translate("PreferencesDialog", "Recognizing settings", 0, QApplication::UnicodeUTF8));
        lblMinPatternSize->setText(QApplication::translate("PreferencesDialog", "Minimal pattern size:", 0, QApplication::UnicodeUTF8));
        lblMaxPatternSize->setText(QApplication::translate("PreferencesDialog", "Maximal pattern size:", 0, QApplication::UnicodeUTF8));
        editMinPatternSize->setSuffix(QApplication::translate("PreferencesDialog", "%", 0, QApplication::UnicodeUTF8));
        editMaxPatternSize->setSuffix(QApplication::translate("PreferencesDialog", "%", 0, QApplication::UnicodeUTF8));
        gbxCharts->setTitle(QApplication::translate("PreferencesDialog", "Charts settings", 0, QApplication::UnicodeUTF8));
        cbxChartsOverlay->setText(QApplication::translate("PreferencesDialog", "Add text overlay with detailed information?", 0, QApplication::UnicodeUTF8));
        lblDefaultImageType->setText(QApplication::translate("PreferencesDialog", "Default image format for saving:", 0, QApplication::UnicodeUTF8));
        cbxDefaultImageType->clear();
        cbxDefaultImageType->insertItems(0, QStringList()
         << QApplication::translate("PreferencesDialog", ".png", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", ".jpg", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", ".bmp", 0, QApplication::UnicodeUTF8)
        );
        cbxDrawDtwAccumulated->setText(QApplication::translate("PreferencesDialog", "Draw DTW accumulated distances?", 0, QApplication::UnicodeUTF8));
        gbxAppearance->setTitle(QApplication::translate("PreferencesDialog", "Appearance", 0, QApplication::UnicodeUTF8));
        cbxUseStylesheet->setText(QApplication::translate("PreferencesDialog", "Use stylesheets?", 0, QApplication::UnicodeUTF8));
        lblStylesheet->setText(QApplication::translate("PreferencesDialog", "Stylesheet name:", 0, QApplication::UnicodeUTF8));
        cbxStylesheet->clear();
        cbxStylesheet->insertItems(0, QStringList()
         << QApplication::translate("PreferencesDialog", "default", 0, QApplication::UnicodeUTF8)
        );
        lblWaveFormColor->setText(QApplication::translate("PreferencesDialog", "Waveform chart color:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PreferencesDialog: public Ui_PreferencesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCESDIALOG_H
