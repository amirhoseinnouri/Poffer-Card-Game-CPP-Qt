QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# You might need to add Qt Network module later for server communication
 QT += network

# Default installation path
target.path = $$OUT_PWD/install
INSTALLS += target
