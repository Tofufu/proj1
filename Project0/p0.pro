macx {
   QMAKE_MAC_SDK=macosx10.9
}

QT += core gui opengl #script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = p0

DEPENDPATH += .
INCLUDEPATH += .

SOURCES += main.cpp \
           demo.cpp \
           openglwindow.cpp \
           renderwindow.cpp

HEADERS += demo.h \
           openglwindow.h \
           renderwindow.h

RESOURCES += \
    shaders.qrc

FORMS += \
    dialog.ui
