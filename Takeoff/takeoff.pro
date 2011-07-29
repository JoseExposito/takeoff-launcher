QT          += core gui xml
TARGET       = plasmoid/plasma_applet_takeoff

TEMPLATE     = lib

OBJECTS_DIR += build
MOC_DIR     += build
UI_DIR      += build
LIBS        += -lplasma

include(src/takeoff/takeoff.pri)
