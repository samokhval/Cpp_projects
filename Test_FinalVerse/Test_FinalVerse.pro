#-------------------------------------------------
#
# Project created by QtCreator 2014-11-03T10:27:33
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test_FinalVerse
TEMPLATE = app


SOURCES += main.cpp\
        TestUI.cpp \
    TestQuestions.cpp \
    TestDB.cpp \
    AbstractUI.cpp

HEADERS  += TestUI.h \
    TestQuestions.h \
    TestDB.h \
    AbstractUI.h

FORMS    += TestUI.ui
