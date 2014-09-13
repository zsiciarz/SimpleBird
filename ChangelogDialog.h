/**
 * @file ChangelogDialog.h
 *
 * Okno wyświetlające historię zmian - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.4.0
 */


#ifndef CHANGELOGDIALOG_H
#define CHANGELOGDIALOG_H

#include <QDialog>
#include <QString>
#include <QTextEdit>

namespace Ui {
    class ChangelogDialog;
}

/**
 * Okno wyświetlające historię zmian.
 */
class ChangelogDialog : public QDialog
{
    Q_OBJECT

public:
    ChangelogDialog(QWidget *parent = 0);
    ~ChangelogDialog();

private:
    /**
     * Klasa interfejsu wygenerowana przez Designera.
     */
    Ui::ChangelogDialog *ui;

    void loadFile(QString filename, QTextEdit* txtEdit);
};

#endif // CHANGELOGDIALOG_H
