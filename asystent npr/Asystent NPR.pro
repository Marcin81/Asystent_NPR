# -------------------------------------------------
# Project created by QtCreator 2009-05-27T19:43:30
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
    myviewwidget.cpp

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
    ui_about.h

unix {
    HEADERS += qmydecompressor.h \
      qtarbzip2decompressor.h

    SOURCES += qtarbzip2decompressor.cpp \
      qmydecompressor.cpp

    TARGET = "Asystent NPR"
    INCLUDEPATH += /opt/local/include
    LIBS += /opt/local/lib/libtar.a
    LIBS += /opt/local/lib/libbz2.a
}

mac { 
    TARGET = "Asystent NPR"
}

win32 { 
    # unix { #dla crossCompile
    TARGET = "Asystent_NPR"
    INCLUDEPATH += c:\zrodla\boost_1_40_0 
    DEFINES += QT_DLL
}

RESOURCES += draggableicons.qrc
FORMS += mainwindow.ui \
    viewwidget.ui \
    about.ui
TRANSLATIONS = metody_naturalne_uk.ts \
    metody_naturalne_pl.ts
