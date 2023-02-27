include($$(VTBUILD_CORE_PATH)/VTBuildConf.pri)
!exists($$(VTBUILD_CORE_PATH)/VTBuildConf.pri) : error("Can't find VTBuildConf.pri")

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

ES_PRODUCT_DIR=C:/SVN/cleverone/product

#import ES2DViewer library
ES2DVIEWER_IMPORT_PATH = $$ES_PRODUCT_DIR/common/ESViewerCommon/ES2DViewer/ImportES2DViewer.pri
!exists($$ES2DVIEWER_IMPORT_PATH) : error("Can't include $${ES2DVIEWER_IMPORT_PATH}")
include($$ES2DVIEWER_IMPORT_PATH)


SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += $${ES_PRODUCT_DIR}/common/
INCLUDEPATH += $${ES_PRODUCT_DIR}/inc/

PRE_TARGETDEPS += $${ES_PRODUCT_DIR}/common/ESViewerCommon/ES2DViewer/lib/$${VT_LIB_BUILD_TARGET}/ES2DViewer.lib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
