cmake_minimum_required(VERSION 3.10)
project(QHexView)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
INCLUDE(FindPkgConfig)

add_library(qhexview STATIC
    document/buffer/qfilebuffer.cpp
    document/buffer/qfilebuffer.h
    document/buffer/qhexbuffer.cpp
    document/buffer/qhexbuffer.h
    document/buffer/qmemorybuffer.cpp
    document/buffer/qmemorybuffer.h
    document/buffer/qmemoryrefbuffer.cpp
    document/buffer/qmemoryrefbuffer.h
    document/commands/hexcommand.cpp
    document/commands/hexcommand.h
    document/commands/insertcommand.cpp
    document/commands/insertcommand.h
    document/commands/removecommand.cpp
    document/commands/removecommand.h
    document/commands/replacecommand.cpp
    document/commands/replacecommand.h
    document/qhexcursor.cpp
    document/qhexcursor.h
    document/qhexdocument.cpp
    document/qhexdocument.h
    document/qhexmetadata.cpp
    document/qhexmetadata.h
    document/qhexrenderer.cpp
    document/qhexrenderer.h
    qhexview.cpp
    qhexview.h
)

target_link_libraries(qhexview PRIVATE Qt5::Widgets Qt5::Core)
target_include_directories(qhexview PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${Qt5Widgets_INCLUDE_DIRS}
)


