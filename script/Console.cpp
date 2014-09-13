/**
 * @file Console.cpp
 *
 * Domyślna konsola wyjścia skryptów JS - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#include "Console.h"

#include <QDebug>


/**
 * Konstruktor - tworzy obiekt konsoli.
 *
 * @param parent obiekt rodzica
 */
Console::Console(QObject *parent):
    QObject(parent)
{
}

/**
 * Zapisuje wiadomość na standardowe wyjście programu.
 *
 * @param message wiadomość konsoli
 */
void Console::log(QString message)
{
    qDebug() << message;
}
