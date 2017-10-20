TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
#INCLUDEPATH    += ../echowindow

HEADERS         = connector_plugin.h \                  
                  menu.h


SOURCES         = connector_plugin.cpp \                  
                  menu.cpp
                  

LIB_NAME = $$system(basename $(pwd))

COMMAND = "mv libplugin.so ../../../build/compiled_plugins/"

FINAL_PATH = $$join(COMMAND,"","",$$LIB_NAME)  

#system(echo $$FINAL_PATH)

QMAKE_POST_LINK += $$FINAL_PATH

CONFIG += install_ok  # Do not cargo-cult this!
