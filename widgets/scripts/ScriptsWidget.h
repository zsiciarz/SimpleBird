/**
 * @file ScriptsWidget.h
 *
 * Kontrolka zarządzająca skryptami - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#ifndef SCRIPTSWIDGET_H
#define SCRIPTSWIDGET_H

#include "QtScriptHighligher.h"
#include "script/ScriptEngine.h"
#include <QString>
#include <QDirModel>
#include <QMenu>
#include <QModelIndex>
#include <QWidget>

namespace Ui {
    class ScriptsWidget;
}

/**
 * Kontrolka zarządzająca skryptami.
 */
class ScriptsWidget: public QWidget
{
    Q_OBJECT

public:
    ScriptsWidget(QWidget *parent = 0);
    ~ScriptsWidget();

    /**
     * Zwraca wskaźnik do menu związanego z tą kontrolką.
     */
    QMenu* getMenu() const { return menu; }

public slots:
    void loadScripts(QString directory);
    void runCurrentScript();
    void saveCurrentScript();

signals:
    /**
     * Sygnał wiadomości wysyłanej przez kontrolkę na zewnątrz.
     */
    void sendMessage(QString message);

private slots:
    void scriptDoubleClicked(QModelIndex index);

    void updateUi();

private:
    /**
     * Klasa interfejsu wygenerowana przez Designera.
     */
    Ui::ScriptsWidget *ui;

    /**
     * Menu powiązane z kontrolką skryptów.
     */
    QMenu* menu;

    /**
     * Model katalogu, w którym znajdują się skrypty.
     */
    QDirModel* model;

    /**
     * Obiekt interpretera skryptu.
     */
    ScriptEngine* engine;

    /**
     * Ścieżka do bieżącego skryptu.
     */
    QString currentScriptFilename;

    /**
     * Kod źródłowy aktualnie załadowanego skryptu.
     */
    QString currentScript;

    /**
     * Obiekt odpowiedzialny za kolorowanie składni kodu źródłowego.
     */
    QtScriptHighligher* highlighter;
};

#endif // SCRIPTSWIDGET_H
