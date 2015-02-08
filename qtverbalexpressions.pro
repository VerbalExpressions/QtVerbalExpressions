TEMPLATE = lib

CONFIG += c++11 staticlib
QMAKE_CXXFLAGS += -Wall

macx {
    QMAKE_CXXFLAGS += -mmacosx-version-min=10.7
    QMAKE_CXXFLAGS += -stdlib=libc++
}

DEFINES += QT_USE_QSTRINGBUILDER

TARGET = qtverbalexpressions

QT -= gui
QT += core

SOURCES += \
    QVerbalExpressions.cpp

HEADERS += \
    QVerbalExpressions.h

