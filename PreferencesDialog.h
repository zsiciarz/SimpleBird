/**
 * @file PreferencesDialog.h
 *
 * Okno ustawień programu - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QAbstractButton>
#include <QDialog>

namespace Ui {
    class PreferencesDialog;
}

/**
 * Okno ustawień programu.
 */
class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    PreferencesDialog(QWidget *parent = 0);
    ~PreferencesDialog();

    void readSettings();
    void saveSettings();

private slots:
    void selectMelFilters();
    void restoreDefaults(QAbstractButton* btn);

private:
    /**
     * Klasa interfejsu wygenerowana przez Qt Designera.
     */
    Ui::PreferencesDialog *ui;
};

#endif // PREFERENCESDIALOG_H
