QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sourse/credit.cpp \
#    sourse/deposit_window_tuan.cpp
    sourse/form.cpp \
    main.cpp \
    sourse/mainwindow.cpp \
    sourse/qcustomplot.cpp \
#    s21_calc.c \
#    s21_steck.c \
#    s21_validation.c

HEADERS += \
    headers/credit.h \
#    headers/deposit_window_tuan.h \
    headers/form.h \
    headers/mainwindow.h \
    headers/qcustomplot.h \
#    s21_calc.h

FORMS += \
    form/credit.ui \
#    form/deposit_window_tuan.ui \
    form/form.ui \
    form/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
