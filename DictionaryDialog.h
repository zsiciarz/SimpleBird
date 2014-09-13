/**
 * @file DictionaryDialog.h
 *
 * Okno widoku słownika wzorców - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.3
 */

#ifndef DICTIONARYDIALOG_H
#define DICTIONARYDIALOG_H

#include "recognizing/Dictionary.h"
#include <QColor>
#include <QDialog>
#include <QSqlTableModel>
#include <QString>


namespace Ui {
    class DictionaryDialog;
}

/**
 * Okno widoku słownika wzorców.
 */
class DictionaryDialog : public QDialog
{
    Q_OBJECT

public:
    DictionaryDialog(QWidget *parent = 0);
    ~DictionaryDialog();

signals:
    void sendMessage(QString message, QColor color = Qt::black);

private slots:
    void addDirectory();
    void addFile();
    void clear();
    void rebuildDictionary();

private:
    /**
     * Obiekt interfejsu wygenenerowany przez Designera.
     */
    Ui::DictionaryDialog *ui;

    /**
     * Wskaźnik do obiektu zarządzającego bazą danych słownika.
     */
    Dictionary* dict;

    /**
     * Model tabeli słownika w bazie danych.
     */
    QSqlTableModel* model;
};

#endif // DICTIONARYDIALOG_H
