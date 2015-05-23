#-------------------------------------------------
#
# Project created by QtCreator 2015-05-22T10:54:12
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = New_File_Parser
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    IFileSystemObject.cpp \
    CFile.cpp \
    CDirectory.cpp \
    IFileOperations.cpp \
    CFileOperations.cpp

HEADERS += \
    IFileSystemObject.hpp \
    CFile.hpp \
    CDirectory.hpp \
    IFileOperations.hpp \
    CFileOperations.hpp

DEFINES -= UNICODE
