/**
 * @file DictionaryDialog.cpp
 *
 * Okno widoku słownika wzorców - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.3
 */

#include "DictionaryDialog.h"

#include "ui_DictionaryDialog.h"
#include "aquila/Transform.h"
#include "aquila/WaveFile.h"
#include "aquila/feature/FeatureWriter.h"
#include "ProgressBarIndicator.h"
#include "SimpleBirdApplication.h"
#include "SimpleBirdSettings.h"
#include "formats/FormatFactory.h"
#include <QApplication>
#include <QBitArray>
#include <QDateTime>
#include <QFileDialog>
#include <QMessageBox>


/**
 * Tworzy okno widoku słownika.
 *
 * @param parent obiekt rodzica
 */
DictionaryDialog::DictionaryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DictionaryDialog)
{
    ui->setupUi(this);
    ui->progressBarFile->hide();
    ui->progressBarTotal->hide();

    connect(ui->btnAddDirectory, SIGNAL(clicked()), SLOT(addDirectory()));
    connect(ui->btnAddFile, SIGNAL(clicked()), SLOT(addFile()));
    connect(ui->btnClear, SIGNAL(clicked()), SLOT(clear()));
    connect(ui->btnProcess, SIGNAL(clicked()), SLOT(rebuildDictionary()));

    QString dbfile = SimpleBirdApplication::directoryOf("data") + "/dictionary.db";
    dict = new Dictionary(dbfile, this);
    connect(dict, SIGNAL(sendMessage(QString)), this, SIGNAL(sendMessage(QString)));

    model = new QSqlTableModel(this);
    model->setTable("dictionary");
    model->setHeaderData(1, Qt::Horizontal, tr("Filename"));
    model->setHeaderData(2, Qt::Horizontal, tr("Label"));
    ui->tblDictionary->setModel(model);
    ui->tblDictionary->hideColumn(0); // id column

    model->select();
    ui->tblDictionary->resizeColumnsToContents();
}

/**
 * Usuwa obiekt interfejsu.
 */
DictionaryDialog::~DictionaryDialog()
{
    delete ui;
}

/**
 * Pokazuje okno wyboru katalogu i dodaje wszystkie pliki do słownika.
 */
void DictionaryDialog::addDirectory()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Choose folder"));
    if (!dir.isEmpty())
    {
        ProgressBarIndicator indicator(ui->progressBarTotal);
        dict->setProcessingIndicator(&indicator);
        dict->addDirectory(dir);
        model->select();
        ui->tblDictionary->resizeColumnsToContents();
    }
}

/**
 * Dodaje do słownika plik wybrany przez użytkownika.
 */
void DictionaryDialog::addFile()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose file"),
        "", tr("Wave files (*.wav)"));
    if (!filename.isEmpty())
    {
        dict->addFile(filename);
        model->select();
        ui->tblDictionary->resizeColumnsToContents();
    }
}

/**
 * Usuwa wszystkie wpisy ze słownika, pytając wcześniej o potwierdzenie.
 */
void DictionaryDialog::clear()
{
    if (QMessageBox::question(this, tr("SimpleBird"),
        tr("Are you sure you want to clear all entries in the dictionary?"),
        QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes)
    {
        dict->clear();
        model->select();
        ui->tblDictionary->resizeColumnsToContents();
    }
}

/**
 * Rebuilds the whole dictionary, processing all wave files.
 */
void DictionaryDialog::rebuildDictionary()
{
    bool useMultithreading = ui->cbxMultithreading->isChecked();
    dict->rebuild(useMultithreading);
}

