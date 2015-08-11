# -------------------------------------------------
# Project created by QtCreator 2009-05-27T19:43:30

# License: GPL 
# Owner: Marcin Brysz
# Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
# Version: 1.3 Beta

# -------------------------------------------------
CONFIG += precompile_header \
    qt \
    warn_on \
    debug \
    release
ICON = Thermometer.icns
TEMPLATE = app

OPTION += thread
OPTION += static
QT = gui \
    core \
    webkit

SOURCES += main.cpp \
    edge.cpp \
    dragwidget.cpp \
    moveablepoint.cpp \
    mygraph.cpp \
    mygraphsupplement.cpp \
    mygraphbase.cpp \
    hidetoolwindow.cpp \
    imagepoint.cpp \
    mywindow.cpp \
    interpretationnpr.cpp \
    interpretationbytemperature.cpp \
    interpretationbymucus.cpp \
    myviewwidget.cpp \
    qtarbzip2decompressor.cpp \
    qmydecompressor.cpp

# moc_hidetoolwindow.cpp \
# moc_moveablepoint.cpp \
# moc_mygraphbase.cpp \
# moc_mywindow.cpp \
# moc_imagepoint.cpp \
# moc_mygraph.cpp \
# moc_mygraphsupplement.cpp \
# moc_ui_mainwindow.cpp
HEADERS += moveablepoint.h \
    edge.h \
    dragwidget.h \
    mygraph.h \
    mygraphsupplement.h \
    mygraphbase.h \
    hidetoolwindow.h \
    imagepoint.h \
    mywindow.h \
    interpretationnpr.h \
    interpretationbytemperature.h \
    interpretationbymucus.h \
    myviewwidget.h \
    ui_viewwidget.h \
    ui_mainwindow.h \
    ui_about.h \
    qmydecompressor.h \
    qtarbzip2decompressor.h
unix { 
    TARGET = "Asystent NPR"
    INCLUDEPATH += /opt/local/include
    LIBS += /opt/local/lib/libtar.a
    LIBS += /opt/local/lib/libbz2.a
}

mac { 
    TARGET = "Asystent NPR"
#    INCLUDEPATH += /opt/local/include
#    LIBS += /opt/local/lib/libtar.a
 #   LIBS += /opt/local/lib/libbz2.a
}

win32 { 
    # unix { #dla crossCompile
    TARGET = "Asystent_NPR.exe"
    INCLUDEPATH += /opt/local/include
    
    # INCLUDEPATH += /Users/marcinbrysz/crossCompileWin/qt4.6.0-beta1/include
    # QMAKE_LIBS += /Users/marcinbrysz/crossCompileWin/qt4.6.0-beta1/lib
    # INCLUDEPATH += Z:\boost-trunk_53033
    # LIBS += /Users/marcinbrysz/crossCompileWin/qt4.6.0-beta1/lib/libQtCore.a
    # LIBS += /Users/marcinbrysz/crossCompileWin/qt4.6.0-beta1/lib/libQtGui.a
    # LIBS += /Users/marcinbrysz/crossCompileWin/qt4.6.0-beta1/lib/libQtWebKit.a
    LIBS += /Users/marcinbrysz/crossCompileWin/Dev-CPP/lib/libzzip.a
}

# DEFINES += QT_DLL
# INCLUDEPATH += /Users/marcinbrysz/crossCompileWin/qt4.6.0-beta1/include
# INCLUDEPATH += /Users/marcinbrysz/crossCompileWin/qt4.6.0-beta1/include/Qt
# INCLUDEPATH += /Users/marcinbrysz/crossCompileWin/qt4.6.0-beta1/include/QtCore
# INCLUDEPATH += /Users/marcinbrysz/crossCompileWin/qt4.6.0-beta1/include/QtGui
# INCLUDEPATH += /Users/marcinbrysz/crossCompileWin/qt4.6.0-beta1/include/QtWebKit
RESOURCES += draggableicons.qrc
FORMS += mainwindow.ui \
    viewwidget.ui \
    about.ui
TRANSLATIONS = metody_naturalne_uk.ts \
    metody_naturalne_pl.ts
