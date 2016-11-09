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
    hiloconfigurar.cpp \
    ventanainfopersonas.cpp\
    hilobase.cpp \
    ventananacimiento.cpp \
    ventanadiablo.cpp \
    ventanaarbol.cpp \
    ventanatop10.cpp \
    ventanatop5.cpp \
    ventanaid.cpp \
    ventanafamilia.cpp \
    ventanaarbolinfierno.cpp \
    ventanaarbolavl.cpp \
    ventanaarbolvida.cpp \
    ventanapecados.cpp \
    hiloarbolvida.cpp \
    ventanaarbolpersonasavl.cpp

HEADERS  += ventanaprincipal.h \
    estructuras.h \
    simulacionmundo.h \
    el_mundo.h \
    hiloconfigurar.h \
    ventanainfopersonas.h\
    hilobase.h \
    ventananacimiento.h \
    ventanadiablo.h \
    ventanatop10.h \
    ventanatop5.h \
    ventanaid.h \
    ventanafamilia.h \
    ventanaarbolinfierno.h \
    ventanaarbolavl.h \
    ventanaarbolvida.h \
    ventanaarbol.h \
    ventanapecados.h \
    hiloarbolvida.h \
    ventanaarbolpersonasavl.h



FORMS    += ventanaprincipal.ui \
    ventanainfopersonas.ui\
    ventananacimiento.ui \
    ventanadiablo.ui \
    ventanaarbol.ui \
    ventanatop10.ui \
    ventanatop5.ui \
    ventanaid.ui \
    ventanafamilia.ui \
    ventanaarbolinfierno.ui \
    ventanaarbolavl.ui \
    ventanaarbolvida.ui \
    ventanapecados.ui \
    ventanaarbolpersonasavl.ui

RESOURCES += recursos.qrc

QTPLUGIN += qgif
