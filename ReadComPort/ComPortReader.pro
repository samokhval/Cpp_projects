TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
CONFIG   += c++11

QT       += serialport
QT       += sql

SOURCES += main.cpp \
    CPort.cpp \
    CTable.cpp

HEADERS += \
    CPort.h \
    CTable.h

