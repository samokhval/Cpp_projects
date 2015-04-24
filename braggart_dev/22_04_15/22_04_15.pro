TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    IFileParser.cpp \
    CDirectory.cpp \
    CFile.cpp

HEADERS += \
    IFileParser.h \
    CDirectory.h \
    CFile.h

DEFINES -= UNICODE
