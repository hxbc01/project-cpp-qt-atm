cmake_minimum_required(VERSION 3.1.0)

project(ATM)

# flags
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# include files
include_directories(./include
    ./src
    ./src/atm
    ./src/atm/physical
    ./src/atm/transaction
    ./src/banking
    ./src/simulation
)


# target
add_executable(ATM
    ./src/main.cpp
)

# 3rd party libs




target_link_libraries(ATM Qt5::Widgets)
