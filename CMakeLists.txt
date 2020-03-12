cmake_minimum_required(VERSION 3.1.0)

project(ATM)

# flags
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# include files
include_directories(${Qt5Widgets_INCLUDE_DIRS})

include_directories(./include
    ./src
    ./src/atm
    ./src/atm/physical
    ./src/atm/transaction
    ./src/banking
    ./src/simulation
)

add_subdirectory(./src/banking)
add_subdirectory(./src/atm/physical)
add_subdirectory(./src/atm/transaction)
add_subdirectory(./src/atm)
add_subdirectory(./src/simulation)
add_subdirectory(./src/utils)

set (INTERN_LINK_LIBS ${INTERN_LINK_LIBS} banking physical atm transaction simulation utils)
set (EXTERN_LINK_LIBS ${EXTERN_LINK_LIBS} Qt5::Widgets)

# target
add_executable(${PROJECT_NAME}
    ./src/main.cpp
)

target_link_libraries(${PROJECT_NAME} ${INTERN_LINK_LIBS} ${EXTERN_LINK_LIBS})
