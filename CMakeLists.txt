cmake_minimum_required(VERSION 3.5)

project(DiskTool LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
INCLUDE(FindPkgConfig)
# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()
pkg_check_modules(PKGS_DEP REQUIRED
                blkid
)


find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(DiskTool SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
else()
  add_executable(DiskTool
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
endif()
pkg_search_module(BLKID REQUIRED blkid)
target_include_directories(DiskTool SYSTEM PUBLIC ${BLKID_INCLUDE_DIRS})

target_link_libraries(DiskTool PRIVATE Qt5::Widgets)
target_link_libraries(DiskTool PRIVATE blkid)

target_link_libraries(DiskTool PRIVATE ${BLKID_LIBRARIES})
