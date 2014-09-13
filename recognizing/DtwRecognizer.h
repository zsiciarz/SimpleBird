/**
 * @file DtwRecognizer.h
 *
 * Rozpoznawanie i klasyfikacja metodą DTW - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.7.0
 */


#ifndef DTWRECOGNIZER_H
#define DTWRECOGNIZER_H

#include "Recognizer.h"


class DtwRecognizer : public Recognizer
{
Q_OBJECT

public:
    DtwRecognizer(Dictionary* dict = 0, QObject *parent = 0);

public slots:
    RecognizingResult recognizeFile(QString filename);
};

#endif // DTWRECOGNIZER_H
