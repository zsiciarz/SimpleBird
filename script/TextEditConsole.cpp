/**
 * @file TextEditConsole.cpp
 *
 * Konsola wyjścia skryptów JS zapisująca do edytora tekstowego - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#include "TextEditConsole.h"


/**
 * Konstruktor - tworzy obiekt konsoli.
 *
 * @param txtEdit wskaźnik do edytora tekstowego
 * @param parent obiekt rodzica
 */
TextEditConsole::TextEditConsole(QTextEdit *txtEdit, QObject *parent):
    Console(parent), edit(txtEdit)
{
}

/**
 * Zapisuje wiadomość jako kolejną linię edytora tekstowego.
 *
 * @param message wiadomość konsoli
 */
void TextEditConsole::log(QString message)
{
    edit->append(message);
}
