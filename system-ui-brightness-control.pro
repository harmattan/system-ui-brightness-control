TEMPLATE      = lib
CONFIG       += plugin gui meegotouch system-ui

TARGET        = statusindicatormenu-brightness

CONFIG += link_pkgconfig
PKGCONFIG += gq-gconf

INCLUDEPATH  += /usr/include/meegotouch
INCLUDEPATH  += /usr/include/system-ui

HEADERS += \
    brightnessplugin.h \
    brightnesscontroller.h

SOURCES += \
    brightnessplugin.cpp \
    brightnesscontroller.cpp

OTHER_FILES += \
    statusindicatormenu-brightness.desktop

target.path = /usr/lib/meegotouch/applicationextensions

desktop.files = statusindicatormenu-brightness.desktop
desktop.path = /usr/share/meegotouch/applicationextensions

INSTALLS += target desktop
