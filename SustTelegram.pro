# allows to add DEPLOYMENTFOLDERS and links to the Felgo library and QtCreator auto-completion
CONFIG += felgo
CONFIG += c++latest
QT += concurrent
# uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
# for the remaining steps to build a custom Live Code Reload app see here: https://felgo.com/custom-code-reload-app/
# CONFIG += felgo-live

# Project identifier and version
# More information: https://felgo.com/doc/felgo-publishing/#project-configuration
PRODUCT_IDENTIFIER = com.bond.SustTelegram
PRODUCT_VERSION_NAME = 1.0.0
PRODUCT_VERSION_CODE = 1

# Optionally set a license key that is used instead of the license key from
# main.qml file (App::licenseKey for your app or GameWindow::licenseKey for your game)
# Only used for local builds and Felgo Cloud Builds (https://felgo.com/cloud-builds)
# Not used if using Felgo Live
PRODUCT_LICENSE_KEY = ""

qmlFolder.source = qml
DEPLOYMENTFOLDERS += qmlFolder # comment for publishing

assetsFolder.source = assets
DEPLOYMENTFOLDERS += assetsFolder

# Add more folders to ship with the application here

# RESOURCES += resources.qrc # uncomment for publishing

# NOTE: for PUBLISHING, perform the following steps:
# 1. comment the DEPLOYMENTFOLDERS += qmlFolder line above, to avoid shipping your qml files with the application (instead they get compiled to the app binary)
# 2. uncomment the resources.qrc file inclusion and add any qml subfolders to the .qrc file; this compiles your qml files and js files to the app binary and protects your source code
# 3. change the setMainQmlFile() call in main.cpp to the one starting with "qrc:/" - this loads the qml files from the resources
# for more details see the "Deployment Guides" in the Felgo Documentation

# during development, use the qmlFolder deployment because you then get shorter compilation times (the qml files do not need to be compiled to the binary but are just copied)
# also, for quickest deployment on Desktop disable the "Shadow Build" option in Projects/Builds - you can then select "Run Without Deployment" from the Build menu in Qt Creator if you only changed QML files; this speeds up application start, because your app is not copied & re-compiled but just re-interpreted


# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \ \
    libs/TelegramApi/auth/QTdAuthCode.cpp \
    libs/TelegramApi/auth/QTdAuthManager.cpp \
    libs/TelegramApi/auth/QTdAuthParam.cpp \
    libs/TelegramApi/auth/QTdAuthState.cpp \
    libs/TelegramApi/auth/QTdAuthStateFactory.cpp \
    libs/TelegramApi/call/QTdCallDiscardReason.cpp \
    libs/TelegramApi/client/QTdClient.cpp \
    libs/TelegramApi/client/QTdHandle.cpp \
    libs/TelegramApi/client/QTdThread.cpp \
    libs/TelegramApi/common/QAbstractInt32Id.cpp \
    libs/TelegramApi/common/QAbstractInt53Id.cpp \
    libs/TelegramApi/common/QAbstractInt64Id.cpp \
    libs/TelegramApi/common/QAbstractTdObject.cpp \
    libs/TelegramApi/common/QTdInt.cpp \
    libs/TelegramApi/common/QTdRequest.cpp \
    libs/TelegramApi/common/QTdResponse.cpp \
    libs/TelegramApi/connections/QTdConnectionState.cpp \
    libs/TelegramApi/connections/QTdConnectionStateFactory.cpp \
    libs/TelegramApi/files/QTdDocument.cpp \
    libs/TelegramApi/files/QTdFile.cpp \
    libs/TelegramApi/files/QTdLocalFile.cpp \
    libs/TelegramApi/files/QTdPhotoSize.cpp \
    libs/TelegramApi/files/QTdRemoteFile.cpp


android {
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
    OTHER_FILES += android/AndroidManifest.xml       android/build.gradle
}

ios {
    QMAKE_INFO_PLIST = ios/Project-Info.plist
    OTHER_FILES += $$QMAKE_INFO_PLIST
}

# set application icons for win and macx
win32 {
    RC_FILE += win/app_icon.rc
}
macx {
    ICON = macx/app_icon.icns
}


DISTFILES += \
    public_key \
    public_key.txt \
    qml/pages/AuthorizationPage.qml \
    qml/pages/ChatPage.qml \
    qml/pages/MainPage.qml \
    qml/pages/SignUpPage.qml

HEADERS += \
    libs/TelegramApi/GlobalTelegramConstants.hpp \ \
    libs/TelegramApi/auth/QTdAuthCode.hpp \
    libs/TelegramApi/auth/QTdAuthManager.hpp \
    libs/TelegramApi/auth/QTdAuthParam.hpp \
    libs/TelegramApi/auth/QTdAuthState.hpp \
    libs/TelegramApi/auth/QTdAuthStateFactory.hpp \
    libs/TelegramApi/call/QTdCallDiscardReason.hpp \
    libs/TelegramApi/client/QTdClient.hpp \
    libs/TelegramApi/client/QTdHandle.hpp \
    libs/TelegramApi/client/QTdThread.hpp \
    libs/TelegramApi/common/QAbstractInt32Id.hpp \
    libs/TelegramApi/common/QAbstractInt53Id.hpp \
    libs/TelegramApi/common/QAbstractInt64Id.hpp \
    libs/TelegramApi/common/QAbstractTdObject.hpp \
    libs/TelegramApi/common/QTdInt.hpp \
    libs/TelegramApi/common/QTdRequest.hpp \
    libs/TelegramApi/common/QTdResponse.hpp \
    libs/TelegramApi/connections/QTdConnectionState.hpp \
    libs/TelegramApi/connections/QTdConnectionStateFactory.hpp \
    libs/TelegramApi/files/QTdDocument.hpp \
    libs/TelegramApi/files/QTdFile.hpp \
    libs/TelegramApi/files/QTdLocalFile.hpp \
    libs/TelegramApi/files/QTdPhotoSize.hpp \
    libs/TelegramApi/files/QTdRemoteFile.hpp

LIBS +=  -ltdapi -ltdcore -ltdclient -ltdjson_private -ltdjson -ltdjson_static -lssl -lcrypto

