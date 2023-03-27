QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    facedetection.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    facedetection.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += D:\opencv\build\include

LIBS += D:\opencv-build\bin\libopencv_core460.dll
LIBS += D:\opencv-build\bin\libopencv_highgui460.dll
LIBS += D:\opencv-build\bin\libopencv_imgcodecs460.dll
LIBS += D:\opencv-build\bin\libopencv_imgproc460.dll
LIBS += D:\opencv-build\bin\libopencv_features2d460.dll
LIBS += D:\opencv-build\bin\libopencv_calib3d460.dll
LIBS += D:\opencv-build\bin\libopencv_objdetect460.dll
LIBS += D:\opencv-build\bin\libopencv_videoio460.dll


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#RESOURCES += \
#    TestFiles/test.jpg \
#    haarcascades/haarcascade_eye.xml \
#    haarcascades/haarcascade_eye_tree_eyeglasses.xml \
#    haarcascades/haarcascade_frontalcatface.xml \
#    haarcascades/haarcascade_frontalcatface_extended.xml \
#    haarcascades/haarcascade_frontalface_alt.xml \
#    haarcascades/haarcascade_frontalface_alt2.xml \
#    haarcascades/haarcascade_frontalface_alt_tree.xml \
#    haarcascades/haarcascade_frontalface_default.xml \
#    haarcascades/haarcascade_fullbody.xml \
#    haarcascades/haarcascade_lefteye_2splits.xml \
#    haarcascades/haarcascade_licence_plate_rus_16stages.xml \
#    haarcascades/haarcascade_lowerbody.xml \
#    haarcascades/haarcascade_profileface.xml \
#    haarcascades/haarcascade_righteye_2splits.xml \
#    haarcascades/haarcascade_russian_plate_number.xml \
#    haarcascades/haarcascade_smile.xml \
#    haarcascades/haarcascade_upperbody.xml

DISTFILES += \
    TestFiles/test.jpg \
    haarcascades/haarcascade_eye.xml \
    haarcascades/haarcascade_eye_tree_eyeglasses.xml \
    haarcascades/haarcascade_frontalcatface.xml \
    haarcascades/haarcascade_frontalcatface_extended.xml \
    haarcascades/haarcascade_frontalface_alt.xml \
    haarcascades/haarcascade_frontalface_alt2.xml \
    haarcascades/haarcascade_frontalface_alt_tree.xml \
    haarcascades/haarcascade_frontalface_default.xml \
    haarcascades/haarcascade_fullbody.xml \
    haarcascades/haarcascade_lefteye_2splits.xml \
    haarcascades/haarcascade_licence_plate_rus_16stages.xml \
    haarcascades/haarcascade_lowerbody.xml \
    haarcascades/haarcascade_profileface.xml \
    haarcascades/haarcascade_righteye_2splits.xml \
    haarcascades/haarcascade_russian_plate_number.xml \
    haarcascades/haarcascade_smile.xml \
    haarcascades/haarcascade_upperbody.xml
