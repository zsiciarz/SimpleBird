/**
 * @file ProgressBarIndicator.h
 *
 * Interfejs wskaźnika postępu wykorzystującego QProgressBar - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2007-2009
 * @version 0.8.2
 * @since 0.6.0
 */

#ifndef PROGRESSBARINDICATOR_H
#define PROGRESSBARINDICATOR_H

#include "aquila/ProcessingIndicator.h"
#include <QProgressBar>


class ProgressBarIndicator : public Aquila::ProcessingIndicator
{
public:
    /**
     * Konstruktor - inicjalizuje wskaźnikiem do paska postępu.
     *
     * @param bar graficzny pasek postępu
     */
    ProgressBarIndicator(QProgressBar* bar):
        progressBar(bar)
    {
    }

    void start(int min, int max);

    void progress(int value);

    void stop();

private:
    /**
     * Wskaźnik do paska postępu.
     */
    QProgressBar* progressBar;
};

#endif // PROGRESSBARINDICATOR_H
