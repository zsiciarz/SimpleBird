/**
 * @file prototypes.cpp
 *
 * Rejestracja prototypów klas wykorzystywanych w skryptach - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#include "prototypes.h"

#include "DictionaryPrototype.h"
#include "RecognizerPrototype.h"
#include "WaveFilePrototype.h"


/**
 * Rejestruje wszystkie znane prototypy klas w danym interpreterze JS.
 *
 * @param engine wskaźnik do interpretera skryptów
 */
void registerAllPrototypes(ScriptEngine *engine)
{
    REGISTER_TYPE_FOR_SCRIPT(engine, Dictionary);
    REGISTER_TYPE_FOR_SCRIPT(engine, Recognizer);
    REGISTER_TYPE_FOR_SCRIPT(engine, WaveFile);
}
