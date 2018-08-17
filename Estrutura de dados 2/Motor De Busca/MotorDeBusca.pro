#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T17:01:57
#
#-------------------------------------------------

QT       += core gui



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MotorDeBusca
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


SOURCES += main.cpp\
    nodoc.cpp \
    documento.cpp \
    palavradocumento.cpp \
    documentopalavra.cpp \
    tabelahash.cpp \
    interface.cpp \
    retorno.cpp

HEADERS  += \
    nodoc.h \
    documento.h \
    palavradocumento.h \
    documentopalavra.h \
    defines.h \
    tabelahash.h \
    hahshfuncoes.h \
    nodoc.hpp \
    tabelahash.hpp \
    interface.h \
    retorno.h \
    ordenar.h

FORMS    +=

RESOURCES +=
