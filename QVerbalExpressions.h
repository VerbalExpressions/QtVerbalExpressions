
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
