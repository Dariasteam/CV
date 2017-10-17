TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
#INCLUDEPATH    += ../echowindow

HEADERS         = connector_plugin.h \
                  plugin_template.h

SOURCES         = plugin_template.cpp \
                  connector_plugin.cpp \
                  

LIB_NAME = $$system(basename $(pwd))

COMMAND = "mv libplugin.so ../../../compiled_plugins/"

FINAL_PATH = $$join(COMMAND,"","",$$LIB_NAME)  

#system(echo $$FINAL_PATH)

QMAKE_POST_LINK += $$FINAL_PATH

CONFIG += install_ok  # Do not cargo-cult this!
