#-------------------------------------------------
#
# Project created by QtCreator 2015-12-28T15:39:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Signature_detector
TEMPLATE = app

CONFIG   += c++11

SOURCES += main.cpp\
        CUI.cpp \
    Scanner.cpp \
    CFile.cpp

HEADERS  += CUI.h \
    Scanner.h \
    CFile.h

FORMS    += CUI.ui
