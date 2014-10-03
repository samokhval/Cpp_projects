#-------------------------------------------------
#
# Project created by QtCreator 2014-09-23T12:48:33
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 01_10_14
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    tdatabase.cpp \
    tquestion.cpp \
    itestinterface.cpp

HEADERS  += dialog.h \
    tdatabase.h \
    tquestion.h \
    itestinterface.h

FORMS    += dialog.ui
