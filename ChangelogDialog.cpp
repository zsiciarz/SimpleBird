/**
 * @file ChangelogDialog.cpp
 *
 * Okno wyświetlające historię zmian - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.4.0
 */

#include "ChangelogDialog.h"
#include "ui_ChangelogDialog.h"

#include <QFile>
#include <QFont>
#include <QMessageBox>
#include <QTextStream>


/**
 * Tworzy okno historii i wczytuje pliki zmian z zasobów aplikacji.
 *
 * @param parent obiekt rodzica
 */
ChangelogDialog::ChangelogDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::ChangelogDialog)
{
    ui->setupUi(this);

    QFont txtFont("Consolas", 10);
    txtFont.setStyleHint(QFont::TypeWriter);
    ui->txtAquila->setFont(txtFont);
    ui->txtSimpleBird->setFont(txtFont);

    loadFile(":/texts/CHANGELOG.txt", ui->txtSimpleBird);
    loadFile(":/texts/aquila/CHANGELOG.txt", ui->txtAquila);
}

/**
 * Destruktor - usuwa obiekt interfejsu.
 */
ChangelogDialog::~ChangelogDialog()
{
    delete ui;
}

/**
 * Wczytuje plik tekstowy do pola tekstowego.
 *
 * @param filename ścieżka do pliku
 * @param txtEdit wskaźnik na pole, do którego wczytujemy
 */
void ChangelogDialog::loadFile(QString filename, QTextEdit* txtEdit)
{
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("SimpleBird"), tr("Cannot read file %1:\n%2.").
            arg(filename).arg(file.errorString()));
         return;
     }

     QTextStream in(&file);
     in.setCodec("UTF-8");
     txtEdit->setPlainText(in.readAll());
}
