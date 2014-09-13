/**
 * @file ProgressBarIndicator.cpp
 *
 * Interfejs wskaźnika postępu wykorzystującego QProgressBar - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.3.0
 */

#include "ProgressBarIndicator.h"

#include <QApplication>

/**
 * Inicjalizuje wskaźnik - przekazuje mu pewne wartości graniczne.
 *
 * @param min wartość minimalna (początkowa)
 * @param max wartość maksymalna (końcowa)
 */
void ProgressBarIndicator::start(int min, int max)
{
    progressBar->setRange(min, max);
    progressBar->show();
}

/**
 * Metoda wywoływana w każdym kroku iteracji z aktualną wartością stanu.
 *
 * Zapewnia responsywność interfejsu dzięki wywołaniu processEvents().
*
 * @param value aktualna wartość postępu iteracji
 */
void ProgressBarIndicator::progress(int value)
{
    progressBar->setValue(value);
    qApp->processEvents();
}

/**
 * Metoda wywoływana na zakończenie przetwarzania.
 */
void ProgressBarIndicator::stop()
{
    progressBar->hide();
}

