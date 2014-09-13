/**
 * @file ConsoleWidget.cpp
 * Konsola tekstowa - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.4
 */

#include "ConsoleWidget.h"

#include "ui_ConsoleWidget.h"
#include <QDateTime>
#include <QDesktopServices>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QTextStream>


/**
 * Konstruktor - tworzy obiekt konsolki.
 *
 * @param parent obiekt rodzica
 */
ConsoleWidget::ConsoleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConsoleWidget)
{
    ui->setupUi(this);

    connect(ui->btnClearConsole, SIGNAL(clicked()), SLOT(clear()));
    connect(ui->btnSaveConsole, SIGNAL(clicked()), SLOT(saveLog()));
}

/**
 * Usuwa obiekt interfejsu.
 */
ConsoleWidget::~ConsoleWidget()
{
    delete ui;
}

/**
 * Zwraca wskaźnik do edytora tekstowego, który prezentuje wiadomości.
 *
 * @return wskaźnik do QTextEdit
 */
QTextEdit* ConsoleWidget::getTextEdit()
{
    return ui->txtConsole;
}

/**
 * Wypisuje dany tekst na "konsoli" programu.
 *
 * @param msg wiadomość dopisywana do konsoli jako nowa linia tekstu
 * @param color kolor tekstu (domyślnie czarny)
 */
void ConsoleWidget::logMessage(const QString& msg, QColor color)
{
    ui->txtConsole->append(QString("<font color=\"%3\">[%1]:: %2</font>").
        arg(QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss.zzz")).arg(msg).arg(color.name()));

    emit messageLogged(msg, 2000);
}

/**
 * Wyświetla okienko komunikatu oraz dopisuje ostrzeżenie do konsoli.
 *
 * @param msg wiadomość
 */
void ConsoleWidget::logWarning(const QString& msg)
{
    QMessageBox::warning(this, tr("SimpleBird"), msg, QMessageBox::Ok);
    logMessage(tr("WARNING: %1").arg(msg), Qt::red);
}

/**
 * Czyści konsolę.
 */
void ConsoleWidget::clear()
{
    ui->txtConsole->clear();
}

/**
 * Zapisuje bieżący tekst w konsoli do pliku loga.
 */
void ConsoleWidget::saveLog()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save console log"),
        QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation),
        tr("Text files (*.txt)"));
    if (filename.isEmpty())
        return;

    QFile file(filename);
    if (!file.open(QFile::WriteOnly))
    {
        logWarning(tr("Cannot write to file %1").arg(filename));
        return;
    }

    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    stream << ui->txtConsole->toPlainText();
    file.close();
    logMessage(tr("Console log saved to %1").arg(filename));
}
