/**
 * @file BenchmarkDialog.h
 *
 * Okienko wyboru, co testować - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.2
 */

#ifndef BENCHMARKDIALOG_H
#define BENCHMARKDIALOG_H

#include <QDialog>

namespace Ui {
    class BenchmarkDialog;
}

class BenchmarkDialog : public QDialog
{
    Q_OBJECT

public:
    BenchmarkDialog(QWidget *parent = 0);
    ~BenchmarkDialog();

    bool enableFft();
    bool enableDct();
    bool enableWave();
    bool enableEnergy();
    bool enableMfcc();
    bool enableDtw();

    int getIterationsCount();

private:
    Ui::BenchmarkDialog *ui;
};

#endif // BENCHMARKDIALOG_H
