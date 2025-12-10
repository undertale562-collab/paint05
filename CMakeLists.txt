cmake_minimum_required(VERSION 3.19)
project(paint05 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Gui)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})


target_link_libraries(paint05 PRIVATE Qt6::Widgets)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Gui
)
