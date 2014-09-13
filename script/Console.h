/**
 * @file Console.h
 *
 * Domyślna konsola wyjścia skryptów JS - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#ifndef CONSOLE_H
#define CONSOLE_H

#include <QObject>
#include <QString>


/**
 * Domyślna konsola wyjścia skryptów JS.
*/
class Console : public QObject
{
    Q_OBJECT

public:
    explicit Console(QObject *parent = 0);

    /**
     * Destruktor - nie robi nic.
     */
    virtual ~Console() {}

public slots:
    virtual void log(QString message);
};

#endif // CONSOLE_H
