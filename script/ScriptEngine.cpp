/**
 * @file ScriptEngine.cpp
 *
 * Interpreter skryptów Javascript - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#include "ScriptEngine.h"

#include "SimpleBirdSettings.h"


/**
 * Tworzy obiekt interpretera i przypisuje domyślną konsolę - stdout.
 *
 * @param parent obiekt rodzica
 */
ScriptEngine::ScriptEngine(QObject *parent):
    QScriptEngine(parent)
{
    setConsole(new Console(this));

    globalObject().setProperty("settings", newQObject(new SimpleBirdSettings(), ScriptOwnership));
}

/**
 * Przypisuje konsolę, na którą będzie kierowane wyjście skryptu.
 *
 * Przekierowanie wyjścia na tą konsolę działa w wypadku, gdy skrypt używa
 * funkcji console.log(...) i jej podobnych, a nie zwykłego print(...).
 *
 * @param console wskaźnik do obiektu konsoli
 */
void ScriptEngine::setConsole(Console *console)
{
    globalObject().setProperty("console", newQObject(console));
}

/**
 * Analizuje obiekt konfiguracji zawarty w ewaluowanym skrypcie.
 *
 * Może rzucać wyjątkiem typu ReferenceError do skryptu!
 *
 * @return obiekt funkcji uruchamiającej skrypt (run function), albo niepoprawna wartość
 */
QScriptValue ScriptEngine::configure()
{
    // odczyt konfiguracji skryptu
    config = globalObject().property("config");
    if (!config.isValid())
    {
        currentContext()->throwError(QScriptContext::ReferenceError,
            tr("There is no \"config\" object in the script!"));
        return QScriptValue();
    }

    // poszukiwanie głównej funkcji
    QScriptValue runFunction = config.property("run");
    if (!runFunction.isValid())
    {
        currentContext()->throwError(QScriptContext::ReferenceError,
            tr("There is no \"run\" function in the script!"));
        return QScriptValue();
    }

    return runFunction;
}

/**
 * Wykonuje funkcję podaną w argumencie, gdzie obiektem "this" jest konfiguracja skryptu.
 *
 * @param runFunction obiekt funkcji, powinna to być główna funkcja skryptu
 * @return wynik zwracany przez tą funkcję
 */
QScriptValue ScriptEngine::run(QScriptValue runFunction)
{
    return runFunction.call(config);
}
