/**
 * @file ScriptEngine.h
 *
 * Interpreter skryptów Javascript - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#ifndef SCRIPTENGINE_H
#define SCRIPTENGINE_H

#include "Console.h"
#include <QScriptEngine>
#include <QScriptValue>


/**
 * Interpreter skryptów Javascript.
 */
class ScriptEngine : public QScriptEngine
{
    Q_OBJECT

public:
    explicit ScriptEngine(QObject *parent = 0);

    void setConsole(Console* console);

    QScriptValue configure();
    QScriptValue run(QScriptValue runFunction);

    /**
     * Rejestruje prototyp klasy wywoływanej w skrypcie.
     *
     * Parametrem szablonu musi być klasa prototypu!
     *
     * @param ctor wskaźnik do funkcji określającej konstruktor klasy
     * @param scriptClassName nazwa klasy widziana przez skrypt
     */
    template<typename Prototype> void registerPrototype(FunctionSignature ctor, QString scriptClassName)
    {
        Prototype* proto = new Prototype();
        QScriptValue qsProto = newQObject(proto, ScriptOwnership);
        setDefaultPrototype(qMetaTypeId<Prototype*>(), qsProto);

        QScriptValue qsCtor = newFunction(ctor, qsProto);
        globalObject().setProperty(scriptClassName, qsCtor);
    }

private:
    /**
     * Zmienna odczytana ze skryptu, zawiera konfigurację czasu wykonania.
     */
    QScriptValue config;
};

/**
 * Skrótowe makro dla uproszczenia rejestracji nowej klasy w skryptach.
 *
 * @param engine wskaźnik do obiektu klasy ScriptEngine
 * @param type klasa od strony C++ (nie jako string, ale zwykła nazwa!)
 */
#define REGISTER_TYPE_FOR_SCRIPT(engine, type) \
    (engine)->registerPrototype<type##Prototype>(construct##type, #type)

#endif // SCRIPTENGINE_H
