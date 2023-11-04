cmake_minimum_required(VERSION 3.24)

project(KapibaraControlApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Quick3D)

option(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

include_directories(_grpc)

set(PROJECT_SOURCES
        main.cpp
        qml.qrc
        controller.h
        controller.cpp
        grpc.h
        grpc.cpp
)

set(GRPC_SOURCES
        ./_grpc/rc_service.pb.cc
        ./_grpc/rc_service.grpc.pb.cc
)

set(GRPC_HEADERS
        ./_grpc/rc_service.pb.h
        ./_grpc/rc_service.grpc.pb.h
)



if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(KapibaraControlApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        MiniBara.qml
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET KapibaraControlApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(KapibaraControlApp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(KapibaraControlApp
          ${PROJECT_SOURCES}
        )
    endif()
endif()

add_library(rg_grpc_proto
    ${GRPC_SOURCES}
    ${GRPC_HEADERS}
)

target_link_libraries(KapibaraControlApp
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Quick3D protobuf::libprotobuf gRPC::grpc++ gRPC::grpc++_reflection rg_grpc_proto)

set_target_properties(KapibaraControlApp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)



install(TARGETS KapibaraControlApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(KapibaraControlApp)
    qt_finalize_executable(KapibaraControlApp)
endif()
