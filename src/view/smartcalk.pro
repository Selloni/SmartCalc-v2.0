QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sourse/credit.cpp \
    sourse/form.cpp \
    main.cpp \
    sourse/mainwindow.cpp \
    sourse/qcustomplot.cpp \
    ../model/s21_calc.cc \
    ../controller/s21_controller.cc \

HEADERS += \
    headers/credit.h \
    headers/form.h \
    headers/mainwindow.h \
    qcustomplot.h \
    ../model/s21_calc.h \
    ../controller/s21_controller.h \

FORMS += \
    form/credit.ui \
    form/form.ui \
    form/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
