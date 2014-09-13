/**
 * @file QtScriptHighligher.h
 *
 * Kolorowanie składni w skryptach QtScript - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#ifndef QTSCRIPTHIGHLIGHER_H
#define QTSCRIPTHIGHLIGHER_H

#include <QRegExp>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QVector>

/**
 * Kolorowanie składni w skryptach QtScript.
 */
class QtScriptHighligher : public QSyntaxHighlighter
{
Q_OBJECT
public:
    explicit QtScriptHighligher(QTextEdit* parent = 0);

protected:
     void highlightBlock(const QString &text);

 private:
     /**
      * Pomocnicza struktura przyporządkowująca regule odpowiedni format tekstu.
      */
     struct HighlightingRule
     {
         QRegExp pattern;
         QTextCharFormat format;
     };

     /**
      * Kolekcja reguł kolorowania.
      */
     QVector<HighlightingRule> highlightingRules;

     /**
      * Wyrażenie dopasowujące początek komentarza blokowego.
      */
     QRegExp commentStartExpression;

     /**
      * Wyrażenie dopasowujące koniec komentarza blokowego.
      */
     QRegExp commentEndExpression;

     /**
      * Format tekstu dla słów kluczowych.
      */
     QTextCharFormat keywordFormat;

     /**
      * Format tekstu dla specjalnych obiektów aplikacji.
      */
     QTextCharFormat specialObjectFormat;

     /**
      * Format tekstu dla komentarzy jednolinijkowych.
      */
     QTextCharFormat singleLineCommentFormat;

     /**
      * Format tekstu dla komentarzy wielolinijkowych.
      */
     QTextCharFormat multiLineCommentFormat;

     /**
      * Format tekstu dla łańcuchów znaków.
      */
     QTextCharFormat quotationFormat;

     /**
      * Format tekstu dla wywołań funkcji/metod.
      */
     QTextCharFormat functionFormat;
};

#endif // QTSCRIPTHIGHLIGHER_H
