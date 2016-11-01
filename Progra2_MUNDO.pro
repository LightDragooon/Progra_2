#-------------------------------------------------
#
# Project created by QtCreator 2016-10-15T09:16:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Progra2_MUNDO
TEMPLATE = app


SOURCES += main.cpp\
        ventanaprincipal.cpp \
    hilopintar.cpp \
    hiloconfigurar.cpp \
    ventanainfopersonas.cpp\
    hilobase.cpp \
    ventananacimiento.cpp \
    ventanadiablo.cpp \
    ventanaarbol.cpp

HEADERS  += ventanaprincipal.h \
    estructuras.h \
    hilopintar.h \
    simulacionmundo.h \
    el_mundo.h \
    hiloconfigurar.h \
    ventanainfopersonas.h\
    hilobase.h \
    ventananacimiento.h \
    ventanadiablo.h \
    ventanaarbol.h


FORMS    += ventanaprincipal.ui \
    ventanainfopersonas.ui\
    ventananacimiento.ui \
    ventanadiablo.ui \
    ventanaarbol.ui

RESOURCES += \
    recursos.qrc
