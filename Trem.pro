#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T11:14:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Trem
TEMPLATE = app


SOURCES += main.cpp\
    gerente.cpp \
        mainwindow.cpp \
    sinal.cpp \
    trem.cpp \
    trilhoCompartilhado.cpp

HEADERS  += mainwindow.h \
    gerente.h \
    sinal.h \
    trem.h \
    trilhoCompartilhado.h

FORMS    += mainwindow.ui
