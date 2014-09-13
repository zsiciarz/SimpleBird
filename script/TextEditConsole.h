/**
 * @file TextEditConsole.h
 *
 * Konsola wyjścia skryptów JS zapisująca do edytora tekstowego - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#ifndef TEXTEDITCONSOLE_H
#define TEXTEDITCONSOLE_H

#include "Console.h"
#include <QTextEdit>

/**
 * Konsola wyjścia skryptów JS zapisująca do edytora tekstowego.
 */
class TextEditConsole : public Console
{
    Q_OBJECT

public:
    explicit TextEditConsole(QTextEdit* txtEdit, QObject *parent = 0);

public slots:
    virtual void log(QString message);

private:
    /**
     * Wskaźnik do edytora tekstowego, nie jest własnością konsoli.
     */
    QTextEdit* edit;
};

#endif // TEXTEDITCONSOLE_H
