#-------------------------------------------------
#
# Project created by QtCreator 2012-10-14T01:02:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rainbow_X
TEMPLATE = app


SOURCES += main.cpp\
        rainbowwidget.cpp \
    pixelswidget.cpp \
    fixmath.c \
    ibniz.cpp

HEADERS  += rainbowwidget.h \
    pixelswidget.h \
    fixmath.h \
    ibniz.h

FORMS    += rainbowwidget.ui
