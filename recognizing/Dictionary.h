/**
 * @file Dictionary.h
 *
 * Dostęp do słownika wzorców - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.5
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "aquila/ProcessingIndicator.h"
#include <QDateTime>
#include <QMap>
#include <QMapIterator>
#include <QObject>
#include <QString>
#include <QStringList>


/**
 * Klasa dostępu do słownika wzorców.
 */
class Dictionary : public QObject
{
Q_OBJECT

public:
    typedef QMap<QString, QString> entryMap;

    typedef QMapIterator<QString, QString> entryMapIterator;

    Dictionary(QString dbFile, QObject *parent = 0);

    int countEntries();

    bool hasFile(QString filename);

    bool addFile(QString filename, QString label = "uknown");

    bool removeFile(QString filename);

    bool clear();

    bool addDirectory(QString dirname, bool recursive = true, bool top = true);

    entryMap entries();

    QStringList labels();

    QString findLabel(QString filename);

    void setProcessingIndicator(Aquila::ProcessingIndicator* indicator) { m_indicator = indicator; }

    static QString getCorrespondingFeatureFilename(QString waveFilename);

    void rebuild(bool useMultithreading = false);

signals:
    /**
     * Sygnał emitowany przez metodę rebuild(), informuje o stanie przetwarzania.
     */
    void sendMessage(QString message);

private slots:
    void rebuildFinished();

private:
    void rebuildST();
    void rebuildMT();

    void createTable();

    static bool dbInitialized;

    Aquila::ProcessingIndicator* m_indicator;

    /**
     * Data i czas rozpoczęcia przetwarzania.
     */
    QDateTime start;

    /**
     * Wskaźnik do listy plików utrzymywanej na stercie.
     */
    QList<QString>* filenamesHeap;
};


void rebuildOne(QString waveFilename);



#endif // DICTIONARY_H
