LIBS += -lws2_32
QT += core gui
QT += network

CONFIG += c++20 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        card.cpp \
        deck.cpp \
        gamesession.cpp \
        handevaluator.cpp \
        main.cpp \
        server.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    HandName.h \
    card.h \
    deck.h \
    gamesession.h \
    handevaluator.h \
    server.h


