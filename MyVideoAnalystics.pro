#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T16:11:12
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = MyVideoAnalystics
CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += /usr/local/include \
               /usr/local/include/opencv \
               /usr/local/include/opencv2



LIBS        +=/usr/local/lib/libopencv_highgui.so \
              /usr/local/lib/libopencv_core.so    \
              /usr/local/lib/libopencv_imgproc.so \
              /usr/local/lib/libopencv_calib3d.so \
              /usr/local/lib/libopencv_contrib.so \
              /usr/local/lib/libopencv_ml.so \
              /usr/local/lib/libopencv_gpu.so \
              /usr/local/lib/libopencv_ocl.so \
              /usr/local/lib/libopencv_viz.so \
              /usr/local/lib/libopencv_flann.so \
              /usr/local/lib/libopencv_photo.so \
              /usr/local/lib/libopencv_video.so \
              /usr/local/lib/libopencv_legacy.so \
              /usr/local/lib/libopencv_nonfree.so \
              /usr/local/lib/libopencv_superres.so \
              /usr/local/lib/libopencv_objdetect.so \
              /usr/local/lib/libopencv_videostab.so \
              /usr/local/lib/libopencv_features2d.so
TEMPLATE = app
SOURCES += main.cpp \
    FGDetector.cpp \
    VideoFrameGetter.cpp
HEADERS += \
    FGDetector.h \
    DataStrue.h \
    VideoFrameGetter.h
