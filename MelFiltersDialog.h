/**
 * @file MelFiltersDialog.h
 *
 * Okno wyboru filtrów w skali Mel - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.5.0
 */

#ifndef MELFILTERSDIALOG_H
#define MELFILTERSDIALOG_H

#include <QBitArray>
#include <QDialog>
#include <QSignalMapper>

namespace Ui {
    class MelFiltersDialog;
}

/**
 * Okno wyboru filtrów w skali Mel.
 */
class MelFiltersDialog : public QDialog
{
    Q_OBJECT

public:
    MelFiltersDialog(QWidget *parent = 0);
    ~MelFiltersDialog();

    /**
     * Zwraca tablicę włączonych filtrów.
     */
    QBitArray getEnabledFilters() const { return enabledArray; }

private slots:
    void toggleFilter(int filterNum);

private:
    /**
     * Tablica włączonych filtrów.
     */
    QBitArray enabledArray;

    /**
     * Obiekt interfejsu wygenerowany przez Designera.
     */
    Ui::MelFiltersDialog *ui;
};

#endif // MELFILTERSDIALOG_H
