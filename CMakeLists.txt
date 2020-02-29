cmake_minimum_required(VERSION 3.2)

project(ATM)

find_package(Qt5 COMPONENTS REQUIRED Core Gui Widgets)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories(${Qt5Widgets_INCLUDES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


add_definitions(${Qt5Widgets_DEFINITIONS})

add_subdirectory(src)

add_executable(${PROJECT_NAME} "app/main.cpp")

target_link_libraries(${PROJECT_NAME} ATMLib -lpthread
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets)
