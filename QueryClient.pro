SOURCES += \
    appmain.cpp \
    mainwindow.cpp \
    define.cpp \
    userinfodisplay.cpp \
    setnatsinfo.cpp \
    indepinfotabwidget.cpp \
    slowspeedinfotabwidget.cpp

HEADERS += \
    mainwindow.h \
    define.h \
    natsclient.h \
    userinfodisplay.h \
    setnatsinfo.h \
    indepinfotabwidget.h \
    slowspeedinfotabwidget.h

TARGET = QueryClient

RESOURCES += icon.qrc

QT += gui widgets core network

RC_FILE = logo.rc

CONFIG += C++11


DISTFILES +=
