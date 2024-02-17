QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CApple.cpp \
    CMap.cpp \
    CSnake.cpp \
    CTile.cpp \
    game.cpp \
    main.cpp \
    mainwindow.cpp \
    resultwindow.cpp

HEADERS += \
    CApple.h \
    CMap.h \
    CSnake.h \
    CTile.h \
    game.h \
    mainwindow.h \
    resultwindow.h

FORMS += \
    mainwindow.ui \
    resultwindow.ui

# Nastaveni SFML knihovny

INCLUDEPATH += ..\Snake\SFML-2.6.0-sources\SFML-2.6.0\include
DEPENDPATH += ..\Snake\SFML-2.6.0-sources\SFML-2.6.0\include

LIBS += -L..\Snake\LIBS\

CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-system-d -lsfml-network-d -lsfml-main-d -lsfml-window-d -lsfml-graphics-d
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-system -lsfml-network -lsfml-main -lsfml-window -lsfml-graphics

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
