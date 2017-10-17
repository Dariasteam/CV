TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
#INCLUDEPATH    += ../echowindow

HEADERS         = connector_plugin.h \
                  plugin_template.h

SOURCES         = plugin_template.cpp \
                  connector_plugin.cpp \
                  

LIB_NAME = $$system(basename $(pwd))

COMMAND_A = "mv lib"

FIRST_PATH = $$join(COMMAND_A,"","",$$LIB_NAME)  

COMMAND_B = ".so ../../../compiled_plugins/"

SECOND_PATH = $$join(COMMAND_B,"","",$$LIB_NAME)  

FINAL_PATH = $$join(FIRST_PATH,"","",$$SECOND_PATH)

#system(echo $$FINAL_PATH)

QMAKE_POST_LINK += $$FINAL_PATH

CONFIG += install_ok  # Do not cargo-cult this!
