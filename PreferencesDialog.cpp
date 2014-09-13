/**
 * @file PreferencesDialog.cpp
 *
 * Okno ustawień programu - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#include "PreferencesDialog.h"

#include "ui_PreferencesDialog.h"
#include "MelFiltersDialog.h"
#include "SimpleBirdSettings.h"
#include <QMessageBox>


/**
 * Tworzy okno ustawień, wywołuje funkcję odczytującą ustawienia.
 *
 * @param parent obiekt rodzica
 */
PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);
    connect(ui->btnMelFilters, SIGNAL(clicked()), SLOT(selectMelFilters()));
    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(restoreDefaults(QAbstractButton*)));
    ui->buttonBox->button(QDialogButtonBox::RestoreDefaults)->setText(
            tr("Restore default settings"));

    readSettings();
}

/**
 * Przed zniszczeniem okna zapisuje numer ostatnio otwartej karty ustawień.
 */
PreferencesDialog::~PreferencesDialog()
{
    SimpleBirdSettings settings;
    settings.setValue("general/lastPrefsPage", ui->listPages->currentRow());

    delete ui;
}

/**
 * Odczytuje ustawienia programu i ustawia wartości pól edycyjnych.
 */
void PreferencesDialog::readSettings()
{
    SimpleBirdSettings settings;

    settings.beginGroup("general");
    ui->listPages->setCurrentRow(settings.value("lastPrefsPage").toInt());
    ui->cbxVerbosity->setCurrentIndex(settings.value("verbosity").toInt());
    settings.endGroup();

    settings.beginGroup("sound");
    ui->editFrameLength->setValue(settings.value("frameLength").toInt());
    ui->editFrameOverlap->setValue(settings.value("frameOverlap").toDouble());
    ui->cbxWindowType->setCurrentIndex(settings.value("windowTypeIndex").toInt());
    ui->editPreemphasis->setValue(settings.value("preemphasis").toDouble());
    ui->editParamsPerFrame->setValue(settings.value("paramsPerFrame").toInt());
    settings.endGroup();

    settings.beginGroup("dtw");
    ui->cbxDistanceType->setCurrentIndex(settings.value("distanceType").toInt());
    ui->cbxNormalizationType->setCurrentIndex(settings.value("normalizationType").toInt());
    ui->cbxPassType->setCurrentIndex(settings.value("passType").toInt());
    settings.endGroup();

    settings.beginGroup("recognizing");
    ui->editMinPatternSize->setValue(100 * settings.value("minPatternSize").toDouble());
    ui->editMaxPatternSize->setValue(100 * settings.value("maxPatternSize").toDouble());
    settings.endGroup();

    settings.beginGroup("charts");
    ui->cbxChartsOverlay->setChecked(settings.value("addOverlay").toBool());
    int index = ui->cbxDefaultImageType->findText(settings.value("defaultImageFormat").toString());
    ui->cbxDefaultImageType->setCurrentIndex(index);
    ui->cbxDrawDtwAccumulated->setChecked(settings.value("drawDtwAccumulated").toBool());
    settings.endGroup();

    settings.beginGroup("appearance");
    ui->cbxUseStylesheet->setChecked(settings.value("useStylesheet").toBool());
    index = ui->cbxStylesheet->findText(settings.value("stylesheet").toString());
    ui->cbxStylesheet->setCurrentIndex(index);
    ui->colorWaveform->setColor(settings.value("waveformColor").value<QColor>());
    settings.endGroup();
}

/**
 * Zapisuje wartości pól edycyjnych do ustawień programu.
 */
void PreferencesDialog::saveSettings()
{
    SimpleBirdSettings settings;

    settings.beginGroup("general");
    settings.setValue("verbosity", ui->cbxVerbosity->currentIndex());
    settings.endGroup();

    settings.beginGroup("sound");
    settings.setValue("frameLength", ui->editFrameLength->value());
    settings.setValue("frameOverlap", ui->editFrameOverlap->value());
    settings.setValue("windowType", ui->cbxWindowType->currentText());
    settings.setValue("windowTypeIndex", ui->cbxWindowType->currentIndex());
    settings.setValue("preemphasis", ui->editPreemphasis->value());
    settings.setValue("paramsPerFrame", ui->editParamsPerFrame->value());
    settings.endGroup();

    settings.beginGroup("dtw");
    settings.setValue("distanceType", ui->cbxDistanceType->currentIndex());
    settings.setValue("normalizationType", ui->cbxNormalizationType->currentIndex());
    settings.setValue("passType", ui->cbxPassType->currentIndex());
    settings.endGroup();

    settings.beginGroup("recognizing");
    settings.setValue("minPatternSize", ui->editMinPatternSize->value() / 100.0);
    settings.setValue("maxPatternSize", ui->editMaxPatternSize->value() / 100.0);
    settings.endGroup();

    settings.beginGroup("charts");
    settings.setValue("addOverlay", ui->cbxChartsOverlay->isChecked());
    settings.setValue("defaultImageFormat", ui->cbxDefaultImageType->currentText());
    settings.setValue("drawDtwAccumulated", ui->cbxDrawDtwAccumulated->isChecked());
    settings.endGroup();

    settings.beginGroup("appearance");
    settings.setValue("useStylesheet", ui->cbxUseStylesheet->isChecked());
    settings.setValue("stylesheet", ui->cbxStylesheet->currentText());
    settings.setValue("waveformColor", ui->colorWaveform->getColor());
    settings.endGroup();
}

/**
 * Otwiera okno wyboru filtrów Mel.
 */
void PreferencesDialog::selectMelFilters()
{
    MelFiltersDialog dlg(this);
    if (dlg.exec())
    {
        SimpleBirdSettings settings;
        settings.setValue("sound/enabledFilters", dlg.getEnabledFilters());
    }
}

/**
 * Przywraca domyślne ustawienia, pytając o potwierdzenie.
 */
void PreferencesDialog::restoreDefaults(QAbstractButton* btn)
{
    if (btn == ui->buttonBox->button(QDialogButtonBox::RestoreDefaults))
    {
        if (QMessageBox::question(this, tr("Restore default settings?"),
              tr("Are you sure you want to restore all settings to their default values?"),
              QMessageBox::Yes | QMessageBox::No,
              QMessageBox::No) == QMessageBox::Yes)
        {
            SimpleBirdSettings settings;
            settings.restoreDefaults();
            readSettings();
        }
    }
}
