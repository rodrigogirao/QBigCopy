#-------------------------------------------------
#
# Project created by QtCreator 2013-10-23T14:33:58
#
#-------------------------------------------------

QT       += core gui
CONFIG += console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCopyBigData
TEMPLATE = app


SOURCES += main.cpp\
        janelaprincipal.cpp \
    dialogcopia.cpp \
    progess.cpp

HEADERS  += janelaprincipal.h \
include(/home/creonilson/Downloads/qt-solutions-qt-solutions/qtwinmigrate/src/qtwinmigrate.pri)\
    dialogcopia.h \
    progess.h

FORMS    += janelaprincipal.ui \
    dialogcopia.ui
