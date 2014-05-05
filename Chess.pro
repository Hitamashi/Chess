#-------------------------------------------------
#
# Project created by QtCreator 2013-11-11T15:48:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Tour.cpp \
    Roi.cpp \
    Reine.cpp \
    Pion.cpp \
    Piece.cpp \
    Joueur.cpp \
    Fou.cpp \
    Echiquier.cpp \
    Cavalier.cpp

HEADERS  += mainwindow.h \
    Tour.h \
    Roi.h \
    Reine.h \
    Pion.h \
    Piece.h \
    Joueur.h \
    Fou.h \
    Echiquier.h \
    Cavalier.h

FORMS    += mainwindow.ui

OTHER_FILES +=

RESOURCES += \
    Images.qrc
