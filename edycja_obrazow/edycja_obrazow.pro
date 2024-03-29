#-------------------------------------------------
#
# Project created by QtCreator 2018-03-08T15:00:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = edycja_obrazow
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    menu_odczytu_i_zapisu.cpp \
    okno_rgb.cpp \
    wincyj.cpp \
    manipulacja_rgb.cpp \
    podglad.cpp \
    sobel.cpp \
    wytnij.cpp \
    rozdzielczosc.cpp \
    rozmycie.cpp \
    wlasna_maska.cpp \
    autor.cpp \
    gornoprzepustowe.cpp \
    grey.cpp

HEADERS  += mainwindow.h \
    menu_odczytu_i_zapisu.h \
    okno_rgb.h \
    wincyj.h \
    klasy_miedzyplikowe.h \
    manipulacja_rgb.h \
    podglad.h \
    sobel.h \
    wytnij.h \
    rozdzielczosc.h \
    rozmycie.h \
    wlasna_maska.h \
    autor.h \
    gornoprzepustowe.h \
    grey.h

FORMS    += mainwindow.ui \
    menu_odczytu_i_zapisu.ui \
    okno_rgb.ui \
    wincyj.ui \
    manipulacja_rgb.ui \
    podglad.ui \
    sobel.ui \
    wytnij.ui \
    rozdzielczosc.ui \
    rozmycie.ui \
    wlasna_maska.ui \
    autor.ui \
    gornoprzepustowe.ui \
    grey.ui
