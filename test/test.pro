QT += testlib sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    ../src/contact.cpp \
    ../src/contacts_manager.cpp \
    contact_test.cpp \
    contacts_manager_test.cpp \
    main.cpp

INCLUDEPATH += \
    ../src

HEADERS += \
    ../src/contact.h \
    ../src/contacts_manager.h
