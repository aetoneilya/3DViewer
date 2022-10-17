include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

QMAKE_CXX_FLAGS_COVERAGE += -fprofile-arcs -ftest-coverage -O0

HEADERS += \
        ../model/drawer/matrix_builder/matrix_builder.h \
        tests_matrix.h \
        tests_filereader.h

SOURCES += \
        ../model/drawer/matrix_builder/matrix_builder.cc \
        tests_main.cc

INCLUDEPATH += ../calcul/back