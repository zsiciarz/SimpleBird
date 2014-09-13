/**
 * @file ScriptIconProvider.h
 *
 * Dostawca ikony skryptu dla modelu - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#ifndef SCRIPTICONPROVIDER_H
#define SCRIPTICONPROVIDER_H

#include <QFileIconProvider>
#include <QFileInfo>
#include <QIcon>

/**
 * Dostawca ikony skryptu dla modelu.
 */
class ScriptIconProvider : public QFileIconProvider
{
    /**
     * Zwraca ikonkę odpowiadającą danemu typowi pliku.
     *
     * Jeśli plik ma rozszerzenie "js", zwraca ikonkę skryptu znalezioną w
     * zasobach programu, w przeciwnym razie korzysta z domyślnej implementacji.
     *
     * @param info obiekt informacji o pliku
     * @return obiekt ikony
     */
    QIcon icon(const QFileInfo& info) const
    {
        if (info.suffix() == "js")
            return QIcon(":/icons/script.png");

        return QFileIconProvider::icon(info);
    }
};

#endif // SCRIPTICONPROVIDER_H
