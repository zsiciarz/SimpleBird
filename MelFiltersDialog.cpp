/**
 * @file MelFiltersDialog.cpp
 *
 * Okno wyboru filtrów w skali Mel - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.5.0
 */

#include "MelFiltersDialog.h"

#include "ui_MelFiltersDialog.h"
#include "aquila/global.h"
#include <QCheckBox>
#include <QGridLayout>
#include "SimpleBirdSettings.h"


/**
 * Tworzy okno wyboru filtrów.
 *
 * Odczytuje z ustawień tablicę ustawionych filtrów, tworzy checkboxy i mapuje
 * ich sygnały do jednego slotu.
 *
 * @param parent obiekt rodzica
 */
MelFiltersDialog::MelFiltersDialog(QWidget *parent):
    QDialog(parent),
    enabledArray(Aquila::MELFILTERS, true),
    ui(new Ui::MelFiltersDialog)
{
    ui->setupUi(this);
    SimpleBirdSettings settings;
    enabledArray = settings.getEnabledFilters();

    QSignalMapper* mapper = new QSignalMapper(this);
    QGridLayout* layout = new QGridLayout();
    for (int i = 0; i < enabledArray.size(); ++i)
    {
        QCheckBox* cbx = new QCheckBox(this);
        cbx->setText(QString("#%1").arg(i + 1));
        cbx->setChecked(enabledArray.testBit(i));
        connect(cbx, SIGNAL(clicked()), mapper, SLOT(map()));
        mapper->setMapping(cbx, i);

        layout->addWidget(cbx, i / 12, i % 12);
    }
    ui->gbxCheckboxes->setLayout(layout);
    connect(mapper, SIGNAL(mapped(int)), SLOT(toggleFilter(int)));
}

/**
 * Usuwa obiekt interfejsu.
 */
MelFiltersDialog::~MelFiltersDialog()
{
    delete ui;
}

/**
 * Włącza/wyłącza filtr o podanym numerze.
 *
 * @param filterNum numer filtra w tablicy
 */
void MelFiltersDialog::toggleFilter(int filterNum)
{
    enabledArray.toggleBit(filterNum);
}
