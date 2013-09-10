/*
 * VerbalExpressions Qt Library v0.1
 * https://github.com/VerbalExpressions/QtVerbalExpressions
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013 Skhaz
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _QVerbalExpressions_h
#define _QVerbalExpressions_h

#include <QChar>
#include <QString>
#include <QRegularExpression>

#ifdef Q_COMPILER_INITIALIZER_LISTS
#include <initializer_list>
#endif

class QVerbalExpressions
{
    public:
        QVerbalExpressions();
        QVerbalExpressions(const QVerbalExpressions& other);
        QVerbalExpressions& operator=(const QVerbalExpressions& other);

        #ifdef Q_COMPILER_RVALUE_REFS
        QVerbalExpressions(const QVerbalExpressions&& other);
        QVerbalExpressions& operator=(const QVerbalExpressions&& other);
        #endif

        QVerbalExpressions& add(const QString& value = QString());
        QVerbalExpressions& startOfLine(bool enable = true);
        QVerbalExpressions& endOfLine(bool enable = true);
        QVerbalExpressions& then(const QString& value);
        QVerbalExpressions& find(const QString& value);
        QVerbalExpressions& maybe(const QString& value);
        QVerbalExpressions& anything();
        QVerbalExpressions& anythingBut(const QString& value);
        QVerbalExpressions& something();
        QVerbalExpressions& somethingBut(const QString& value);
        QVerbalExpressions& lineBreak();
        QVerbalExpressions& br();
        QVerbalExpressions& tab();
        QVerbalExpressions& word();
        QVerbalExpressions& anyOf(const QString& value);
        QVerbalExpressions& any(const QString& value);
        QVerbalExpressions& addModifier(char modifier);
        QVerbalExpressions& removeModifier(char modifier);
        QVerbalExpressions& withAnyCase(bool enable = true);
        QVerbalExpressions& searchOneLine(bool enable = true);
        QVerbalExpressions& searchGlobal(bool enable = true);
        QVerbalExpressions& multiple(const QString& value);
        QVerbalExpressions& alt(const QString& value);

        bool test(const QString& value);
        QString replace(QString& source, const QString& value);
        friend QDebug operator<< (QDebug debug, const QVerbalExpressions& expression);

        #ifdef Q_COMPILER_INITIALIZER_LISTS
        QVerbalExpressions& range(const std::initializer_list<QString>& args);
        #endif

    private:
        QString prefixes;
        QString	source;
        QString suffixes;
        QString pattern;
        QRegularExpression::PatternOptions modifiers;
};

#endif
