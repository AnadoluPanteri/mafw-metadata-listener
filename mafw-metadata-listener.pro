
TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += .

QT += dbus

CONFIG += link_pkgconfig
PKGCONFIG += qmafw qmafw-shared

HEADERS += mafw-metadata-listener.h
SOURCES += mafw-metadata-listener.cc

