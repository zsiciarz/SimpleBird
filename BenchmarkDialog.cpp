/**
 * @file BenchmarkDialog.cpp
 *
 * Okienko wyboru, co testować - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.2
 */

#include "BenchmarkDialog.h"
#include "ui_BenchmarkDialog.h"

BenchmarkDialog::BenchmarkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BenchmarkDialog)
{
    ui->setupUi(this);
}

BenchmarkDialog::~BenchmarkDialog()
{
    delete ui;
}

bool BenchmarkDialog::enableFft()
{
    return ui->cbxFft->isChecked();
}

bool BenchmarkDialog::enableDct()
{
    return ui->cbxDct->isChecked();
}

bool BenchmarkDialog::enableWave()
{
    return ui->cbxWave->isChecked();
}

bool BenchmarkDialog::enableEnergy()
{
    return ui->cbxEnergy->isChecked();
}

bool BenchmarkDialog::enableMfcc()
{
    return ui->cbxMfcc->isChecked();
}

bool BenchmarkDialog::enableDtw()
{
    return ui->cbxDtw->isChecked();
}

int BenchmarkDialog::getIterationsCount()
{
    return ui->editIterations->value();
}
