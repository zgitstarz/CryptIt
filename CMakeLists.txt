cmake_minimum_required(VERSION 3.9)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


project(CryptIt LANGUAGES CXX)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 20)
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

if(MSVC)
        add_compile_options(/MT)  

        set_property(TARGET Cryptopp PROPERTY
                IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/libs/cryptlib.lib")
elseif(MINGW)

        set_property(TARGET Cryptopp PROPERTY
                IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/libs/libcryptopp.a") 
endif()

add_executable(CryptIt WIN32 ${PROJECT_SOURCES})


target_link_libraries(CryptIt PRIVATE Qt6::Widgets Cryptopp)
