QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
 RC_ICONS =favicon.ico
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AllWidget.cpp \
    FramelessWidget.cpp \
    MaskLabel.cpp \
    VideoWidget.cpp \
    audiodecoder.cpp \
    avpacketqueue.cpp \
    decoder.cpp \
    main.cpp

HEADERS += \
    AllWidget.h \
    FramelessWidget.h \
    MaskLabel.h \
    VideoWidget.h \
    audiodecoder.h \
    avpacketqueue.h \
    decoder.h



FORMS += \
    AllWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc


#INCLUDEPATH +=$$PWD\ffmpeg\include
#INCLUDEPATH +=$$PWD\sdl\include
#LIBS +=-L$$PWD\sdl\lib\x64  -lSDL2
#LIBS +=-L$$PWD\ffmpeg\lib  -lavcodec -lavformat -lswscale -lswresample -lavutil -lavdevice

INCLUDEPATH += $$PWD/ffmpeg/include \
                $$PWD/sdl/include

LIBS    += $$PWD/ffmpeg/lib/avcodec.lib \
            $$PWD/ffmpeg/lib/avdevice.lib \
            $$PWD/ffmpeg/lib/avfilter.lib \
            $$PWD/ffmpeg/lib/avformat.lib \
            $$PWD/ffmpeg/lib/avutil.lib \
            $$PWD/ffmpeg/lib/postproc.lib \
            $$PWD/ffmpeg/lib/swresample.lib \
            $$PWD/ffmpeg/lib/swscale.lib \
            $$PWD/sdl/lib/libSDL2.a

