#-------------------------------------------------

#

# Project created by QtCreator 2012-04-05T16:25:29

#

#-------------------------------------------------

QT       += phonon

TARGET = menutest

TEMPLATE = app

unix:LIBS += -lical

SOURCES += main.cpp\
    mainwindow.cpp \
    log.cpp \
    globals.cpp \
    addevent.cpp \
    addcategory.cpp \
    addalarm.cpp \
    recurrence.cpp \
    editevent.cpp

HEADERS  += mainwindow.h \
    log.h \
    globals.h \
    exception.h \
    addevent.h \
    addcategory.h \
    addalarm.h \
    libical/ical.h \
    recurrence.h \
    editevent.h

FORMS    += mainwindow.ui \
    addevent.ui \
    addcategory.ui \
    addalarm.ui \
    recurrence.ui \
    editevent.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llibical

else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llibicald

INCLUDEPATH += $$PWD/

DEPENDPATH += $$PWD/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llibicalss

else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llibicalssd

INCLUDEPATH += $$PWD/

DEPENDPATH += $$PWD/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llibicalss-static

else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llibicalss-staticd

INCLUDEPATH += $$PWD/

DEPENDPATH += $$PWD/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llibical-static

else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llibical-staticd

INCLUDEPATH += $$PWD/

DEPENDPATH += $$PWD/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llibicalvcal

else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llibicalvcald

INCLUDEPATH += $$PWD/

DEPENDPATH += $$PWD/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llibicalvcal-static

else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llibicalvcal-staticd

INCLUDEPATH += $$PWD/

DEPENDPATH += $$PWD/

OTHER_FILES += \
    alarm.mp3
