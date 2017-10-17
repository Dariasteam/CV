TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../echowindow
HEADERS         = echoplugin.h \
		  plugin_template.h
SOURCES         = echoplugin.cpp \

FIRST_PATH = "mv libplugin.so ../../../compiled_plugins/" 
SECOND_PATH = $$system(basename $(pwd))

FINAL_PATH = $$join(FIRST_PATH,"","",$$SECOND_PATH)

QMAKE_POST_LINK += $$FINAL_PATH

CONFIG += install_ok  # Do not cargo-cult this!
