cmake_minimum_required(VERSION 3.9)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


project(CryptIt LANGUAGES CXX)

#add_compile_options(/MT)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        globalcustomstyle.cpp
        globalcustomstyle.h
        mainwindow.cpp
        mainwindow.h
	aeskey.cpp
	rsakey.cpp
	keys.h


        mainwindow.ui
)

add_library(Cryptopp IMPORTED STATIC)


set_property(TARGET Cryptopp PROPERTY
IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/libs/libcryptopp.a")

add_executable(CryptIt WIN32 ${PROJECT_SOURCES})


target_link_libraries(CryptIt PRIVATE Qt6::Widgets Cryptopp)
