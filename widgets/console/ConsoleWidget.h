/**
 * @file ConsoleWidget.h
 * Konsola tekstowa - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.4
 */

#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H

#include <QColor>
#include <QString>
#include <QTextEdit>
#include <QWidget>

namespace Ui {
    class ConsoleWidget;
}

/**
 * Konsola tekstowa wraz z przyciskami czyszczenia i zapisu.
 */
class ConsoleWidget : public QWidget
{
    Q_OBJECT

public:
    ConsoleWidget(QWidget *parent = 0);
    ~ConsoleWidget();

    QTextEdit* getTextEdit();

public slots:
    void logMessage(const QString& msg, QColor color = Qt::black);
    void logWarning(const QString& msg);
    void clear();
    void saveLog();

signals:
    /**
     * Sygnał emitowany po zapisaniu wiadomości na konsoli.
     */
    void messageLogged(QString, int);

private:
    /**
     * Obiekt interfejsu wygenerowany przez Designera.
     */
    Ui::ConsoleWidget *ui;
};

#endif // CONSOLEWIDGET_H
