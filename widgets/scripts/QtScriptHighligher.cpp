/**
 * @file QtScriptHighligher.cpp
 *
 * Kolorowanie składni w skryptach QtScript - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#include "QtScriptHighligher.h"

#include <QFont>
#include <QStringList>


/**
 * Tworzy obiekt kolorowania składni i wiąże go z podanym edytorem tekstowym.
 *
 * Inicjalizuje reguły kolorowania.
 *
 * @param parent obiekt rodzica
 */
QtScriptHighligher::QtScriptHighligher(QTextEdit* parent):
    QSyntaxHighlighter(parent)
{
    HighlightingRule rule;
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywords;
    keywords << "break" << "case" << "catch" << "continue" << "default" <<
                "delete" << "do" << "else" << "finally" << "for" << "function" <<
                "if" << "in" << "instanceof" << "new" << "return" << "switch" <<
                "this" << "throw" << "try" << "typeof" << "var" << "void" <<
                "undefined" << "while" << "with";
    foreach (const QString &keyword, keywords)
    {
        rule.pattern = QRegExp("\\b" + keyword + "\\b");
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    specialObjectFormat.setForeground(Qt::darkMagenta);
    specialObjectFormat.setFontWeight(QFont::Bold);
    QStringList specialObjects;
    specialObjects << "console" << "settings";
    foreach (const QString &obj, specialObjects)
    {
        rule.pattern = QRegExp("\\b" + obj + "\\b");
        rule.format = specialObjectFormat;
        highlightingRules.append(rule);
    }

    multiLineCommentFormat.setForeground(Qt::darkGray);
    singleLineCommentFormat.setForeground(Qt::darkGray);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("\".*\"");
    rule.pattern.setMinimal(true);
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}

/**
 * Odpowiada za pokolorowanie bloku tekstu.
 *
 * Ciało metody zostało zapożyczone z dokumentacji Qt.
 *
 * @param text blok tekstu do kolorowania
 */
void QtScriptHighligher::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules)
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0)
        {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

    while (startIndex >= 0)
    {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1)
        {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        }
        else
        {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }

        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}
