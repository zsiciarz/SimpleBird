/**
 * @file Dictionary.cpp
 *
 * Dostęp do słownika wzorców - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.5
 */

#include "Dictionary.h"

#include "SimpleBirdSettings.h"
#include "aquila/WaveFile.h"
#include "aquila/Transform.h"
#include "formats/FormatFactory.h"
#include <QApplication>
#include <QtConcurrentMap>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFuture>
#include <QFutureWatcher>
#include <QProgressDialog>
#include <QtSql>
#include <QThread>


bool Dictionary::dbInitialized = false;


/**
 * Tworzy obiekt dostępu do słownika.
 *
 * Pierwsze utworzenie obiektu inicjalizuje połączenie z bazą danych, a jeśli
 * plik bazy nie istnieje, zostaje utworzony wraz z tabelą słownika.
 *
 * @param dbFile nazwa pliku bazy danych
 * @param parent obiekt rodzica
 */
Dictionary::Dictionary(QString dbFile, QObject *parent):
    QObject(parent), m_indicator(0), filenamesHeap(0)
{
    if (!dbInitialized)
    {
        bool dbExists = QFile::exists(dbFile);
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbFile);
        if (!db.open())
            qWarning() << db.lastError().text();
        if (!dbExists)
            createTable();

        dbInitialized = true;
    }
}

/**
 * Zwraca liczbę wpisów w słowniku.
 *
 * @return liczba rekordów w tabeli słownika
 */
int Dictionary::countEntries()
{
    QSqlQuery query("SELECT COUNT(*) FROM dictionary");
    if (!query.isActive())
        return 0;

    if (query.next())
        return query.value(0).toInt();

    return 0;
}

/**
 * Sprawdza, czy taki plik już jest w słowniku.
 *
 * @param filename pełna ścieżka do pliku
 * @return true, jeśli plik istnieje w bazie danych
 */
bool Dictionary::hasFile(QString filename)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM dictionary WHERE filename=?");
    query.addBindValue(filename);

    return query.exec() && query.next();
}

/**
 * Dodaje plik do słownika i przypisuje mu daną etykietę.
 *
 * @param filename pełna ścieżka do pliku
 * @param label etykieta, domyślnie "unknown"
 * @return wynik wykonania zapytania
 */
bool Dictionary::addFile(QString filename, QString label)
{
    QSqlQuery query;
    query.prepare("INSERT INTO dictionary (filename, label) VALUES(?, ?)");
    query.addBindValue(filename);
    query.addBindValue(label);

    return query.exec();
}

/**
 * Usuwa plik z bazy danych słownika, ale nie z dysku.
 *
 * @param filename pełna ścieżka do pliku
 * @return true jeśli poprawnie usunięto rekord
 */
bool Dictionary::removeFile(QString filename)
{
    QSqlQuery query;
    query.prepare("DELETE FROM dictionary WHERE filename=?");
    query.addBindValue(filename);

    return query.exec() && (query.numRowsAffected() > 0);
}

/**
 * Czyści bazę danych, używać ostrożnie!
 */
bool Dictionary::clear()
{
    QSqlQuery query("DELETE FROM dictionary");

    return query.isActive();
}

/**
 * Dodaje wszystkie pliki z danego katalogu do słownika.
 *
 * @param dirname nazwa katalogu
 * @param recursive czy przetwarzać rekursywnie katalogi
 * @param top parametr używany tylko w przypadku rekursywnego przetwarzania
 * @return true, jeśli dodawanie wykonano z powodzeniem
 */
bool Dictionary::addDirectory(QString dirname, bool recursive, bool top)
{
    QDir dir(dirname);

    dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList infoList = dir.entryInfoList();

    if (top && m_indicator)
        m_indicator->start(0, infoList.size()-1);
    int i = 0;

    foreach(QFileInfo fi, infoList)
    {
        if (recursive && fi.isDir())
            addDirectory(fi.canonicalFilePath(), recursive, false);

        if (fi.suffix().toUpper() == "WAV")
            addFile(fi.canonicalFilePath());

        if (top && m_indicator)
            m_indicator->progress(++i);
    }

    if (top && m_indicator)
        m_indicator->stop();

    return true;
}

/**
 * Zwraca mapowanie postaci nazwa pliku => etykieta.
 *
 * @return mapowanie ścieżki pliku na etykietę
 */
Dictionary::entryMap Dictionary::entries()
{
    QSqlQuery query("SELECT filename, label FROM dictionary");
    entryMap map;
    if (query.isActive())
    {
        QString filename, label;
        while (query.next())
        {
            filename = query.value(0).toString();
            label = query.value(1).toString();
            map[filename] = label;
        }
    }

    return map;
}

QStringList Dictionary::labels()
{
    QSqlQuery query("SELECT DISTINCT(label) FROM dictionary");
    QStringList l;
    if (query.isActive())
    {
        while (query.next())
        {
            l << query.value(0).toString();
        }
    }

    return l;
}

/**
 * Zwraca etykietkę odpowiadającą danej nazwie pliku.
 */
QString Dictionary::findLabel(QString filename)
{
    QSqlQuery query;
    query.prepare("SELECT label FROM dictionary WHERE filename=?");
    query.addBindValue(filename);

    QString label("unknown");
    if (query.exec() && query.next())
        label = query.value(0).toString();

    return label;
}

/**
 * Zwraca ścieżkę do pliku cech odpowiadającą danemu plikowi dźwiękowemu.
 *
 * @param waveFilename pełna ścieżka do pliku dźwiękowego
 * @return ścieżka do pliku cech (może być nieistniejący)
 */
QString Dictionary::getCorrespondingFeatureFilename(QString waveFilename)
{
    waveFilename.chop(3);
    return waveFilename+"bir";
}

/**
 * Tworzy tabelę słownika w domyślnej bazie danych.
 */
void Dictionary::createTable()
{
    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();
    QSqlQuery query("CREATE TABLE IF NOT EXISTS dictionary ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "filename VARCHAR(255),"
                    "label VARCHAR(63)"
                    ")");
    if (!query.isActive())
    {
        db.rollback();
        qWarning() << "Query failed: " << query.executedQuery();
    }
    db.commit();
}

/**
 * Przebudowuje słownik.
 *
 * @param useMultithreading włącza przetwarzanie wielowątkowe (domyślnie wyłączone)
 */
void Dictionary::rebuild(bool useMultithreading)
{
    emit sendMessage(tr("Rebuilding dictionary..."));
    start = QDateTime::currentDateTime();
    emit sendMessage(tr("Started at %1").arg(start.toString()));

    if (useMultithreading)
        rebuildMT();
    else
        rebuildST();
}

/**
 * Przebudowuje słownik - wersja jednowątkowa.
 */
void Dictionary::rebuildST()
{
    entryMap e = entries();
    entryMapIterator it(e);
    int i = 0;

    QProgressDialog progress(tr("Rebuilding the dictionary..."), tr("Cancel"), 0, e.size());
    QApplication::setOverrideCursor(Qt::BusyCursor);

    while (it.hasNext())
    {
        it.next();
        progress.setValue(++i);
        if (progress.wasCanceled())
        {
            emit sendMessage(tr("Processing canceled!"));
            break;
        }

        rebuildOne(it.key());

        qApp->processEvents();
    }

    rebuildFinished();
}

/**
 * Przebudowuje cały słownik - wersja wielowątkowa.
 */
void Dictionary::rebuildMT()
{
    emit sendMessage(tr("Multithreading enabled, using %1 threads").
                     arg(QThread::idealThreadCount()));

    QList<QString> filenames = entries().keys();
    filenamesHeap = new QList<QString>(filenames);

    QProgressDialog* progress = new QProgressDialog(tr("Rebuilding the dictionary..."),
                                                    tr("Cancel"), 0, filenames.size(), 0);
    progress->setModal(false);

    QApplication::setOverrideCursor(Qt::BusyCursor);

    QFutureWatcher<void>* watcher = new QFutureWatcher<void>(this);
    connect(watcher, SIGNAL(finished()), this, SLOT(rebuildFinished()));
    connect(watcher, SIGNAL(progressRangeChanged(int,int)),
            progress, SLOT(setRange(int,int)));
    connect(watcher, SIGNAL(progressValueChanged(int)),
            progress, SLOT(setValue(int)));
    connect(progress, SIGNAL(canceled()), watcher, SLOT(cancel()));

    QFuture<void> future = QtConcurrent::map(*filenamesHeap, rebuildOne);
    watcher->setFuture(future);
}

/**
 * Slot wywoływany w chwili zakończenia przebudowy słownika.
 */
void Dictionary::rebuildFinished()
{
    QApplication::restoreOverrideCursor();

    emit sendMessage(tr("Rebuilding done."));
    QDateTime stop = QDateTime::currentDateTime();
    emit sendMessage(tr("Finished at %1").arg(stop.toString()));
    emit sendMessage(tr("Total time: %1 seconds").arg(start.secsTo(stop)));

    delete filenamesHeap;
    filenamesHeap = 0;
}

/**
 * Funkcja przetwarzająca pojedynczy plik dźwiękowy do postaci pliku cech.
 *
 * @param waveFilename pełna ścieżka do pliku nagrania
 */
void rebuildOne(QString waveFilename)
{
    QString featureFile = Dictionary::getCorrespondingFeatureFilename(waveFilename);

    SimpleBirdSettings settings;
    unsigned int frameLength = settings.getFrameLength();
    double overlap = settings.getOverlap();

    // obiekt nagrania
    Aquila::WaveFile* wav = new Aquila::WaveFile(frameLength, overlap);
    wav->load(waveFilename.toStdString());
    // opcje transformacji (z wyjątkiem długości ramki!)
    Aquila::TransformOptions options;
    options.windowType = settings.getWindowType();
    options.zeroPaddedLength = wav->getSamplesPerFrameZP();
    options.preemphasisFactor = settings.getPreemphasis();

    Aquila::Extractor* extractor = FormatFactory::getExtractor("MFCC");
    extractor->process(wav, options);
    Aquila::FeatureWriter* writer = FormatFactory::getFeatureWriter(featureFile);
    extractor->save(*writer);

    delete writer;
    delete extractor;
    delete wav;
}
