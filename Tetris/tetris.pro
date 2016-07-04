#-------------------------------------------------
#
# Project created by QtCreator 2016-05-27T09:24:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 27_05_16
TEMPLATE = app

CONFIG   += c++11

SOURCES += main.cpp\
    CItem.cpp \
    CTetris.cpp \
    CBoard.cpp \
    CShape1.cpp \
    CShape2.cpp \
    CShape3.cpp \
    CShape4.cpp \
    CShape5.cpp \
    CShape6.cpp \
    CShape7.cpp

HEADERS  += \
    CItem.h \
    CTetris.h \
    CBoard.h \
    ITetris.h \
    IItemBehavior.h \
    CShape1.h \
    CShape2.h \
    CShape3.h \
    CShape4.h \
    CShape5.h \
    CShape6.h \
    CShape7.h

FORMS    +=

DEFINES += PRO_FILE_PWD=$$sprintf("\"\\\"%1\\\"\"", $$_PRO_FILE_PWD_)
