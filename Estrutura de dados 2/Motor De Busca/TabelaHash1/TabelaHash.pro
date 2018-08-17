QT += core
QT -= gui

CONFIG += c++11

TARGET = TabelaHash
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tabelahash.cpp \
    docpalavra.cpp \
    documento.cpp \
    listadepalavra.cpp \
    relevancia.cpp \
    interface.cpp \
    ordena.cpp

HEADERS += \
    tabelahash.h \
    node.h \
    docpalavra.h \
    documento.h \
    tabelahash.hpp \
    listadepalavra.h \
    relevancia.h \
    interface.h \
    ordena.h \
    ordena.hpp

FORMS +=
