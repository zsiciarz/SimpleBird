/**
 * @file RecognizerPrototype.cpp
 *
 * Prototyp klasy skryptowej dla obiektu rozpoznawania - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.2
 */

#include "RecognizerPrototype.h"

#include "SimpleBirdApplication.h"
#include "SimpleBirdSettings.h"
#include "recognizing/DtwRecognizer.h"
#include <QDateTime>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QInputDialog>
#include <QProgressDialog>
#include <QStringList>


RecognizerPrototype::RecognizerPrototype(QObject *parent):
    QObject(parent)
{
    QString dbfile = SimpleBirdApplication::directoryOf("data") + "/dictionary.db";
    dict = new Dictionary(dbfile, this);

    recognizer = new DtwRecognizer(dict, this);
    connect(recognizer, SIGNAL(sendMessage(QString)), this, SIGNAL(sendMessage(QString)));
}

void RecognizerPrototype::recognizeFile(QString filename)
{
    QProgressDialog progress(tr("Recognizing..."), tr("Cancel"), 0, dict->countEntries()-1);
    connect(recognizer, SIGNAL(progressRangeChanged(int,int)), &progress, SLOT(setRange(int,int)));
    connect(recognizer, SIGNAL(progressChanged(int)), &progress, SLOT(setValue(int)));

    QApplication::setOverrideCursor(Qt::BusyCursor);

    recognizer->recognizeFile(filename);

    QApplication::restoreOverrideCursor();
}

void RecognizerPrototype::recognizeFiles(QString directory, QString expectedLabel)
{
    SimpleBirdSettings settings;
    if (directory.isEmpty())
    {
        directory = QFileDialog::getExistingDirectory(0, tr("Choose directory"),
            settings.value("general/initialDirectory").toString());
    }
    if (directory.isEmpty())
        return;

    if (expectedLabel.isEmpty())
    {
        bool ok;
        expectedLabel = QInputDialog::getText(0, tr("Expected label"),
            tr("Expected label:"), QLineEdit::Normal, QString(), &ok);
        if (!ok)
            return;
    }
    if (expectedLabel.isEmpty())
        return;

    emit sendMessage(tr("Starting batch recognizing"));
    QDateTime start = QDateTime::currentDateTime();
    emit sendMessage(tr("Started at %1").arg(start.toString()));
    emit sendMessage(tr("Directory: %1, expected label: %2").arg(directory).arg(expectedLabel));
    QFileInfoList files = QDir(directory).entryInfoList(QStringList() << "*.wav", QDir::Files);
    int total = files.count(), correct = 0, i = 0;
    emit sendMessage(tr("Number of files: %1").arg(total));

    QProgressDialog progress(tr("Batch recognizing..."), tr("Cancel"), 0, total);

    foreach (QFileInfo fi, files)
    {
        QString file = fi.canonicalFilePath();
        emit sendMessage(file);
        emit sendMessage(tr("Recognizing file %1 of %2").arg(++i).arg(total));
        progress.setValue(i);

        RecognizingResult result = recognizer->recognizeFile(file);
        if (result.label == expectedLabel)
            correct++;

        qApp->processEvents();
    }

    emit sendMessage(tr("Batch recognizing finished"));
    QString percentage = QString::number(100.0 * correct / static_cast<double>(total), 'f', 4);
    emit sendMessage(tr("Correctly recognized %1 out of %2 files (%3 percent)").
        arg(correct).arg(total).arg(percentage));
    emit sendMessage(">>> " + percentage);
    QDateTime stop = QDateTime::currentDateTime();
    emit sendMessage(tr("Finished at %1").arg(stop.toString()));
    emit sendMessage(tr("Total time: %1 seconds").arg(start.secsTo(stop)));
}



/**
 * Reprezentuje konstruktor rozpoznawacza w skrypcie.
 *
 * @param context kontekst wykonania skryptu
 * @param engine interpreter
 * @return obiekt słownika w skrypcie
 */
QScriptValue constructRecognizer(QScriptContext* context, QScriptEngine* engine)
{
    Q_UNUSED(context);

    return engine->newQObject(new RecognizerPrototype());
}
