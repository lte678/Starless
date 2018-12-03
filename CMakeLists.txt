cmake_minimum_required(VERSION 3.12)
project(Starless)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Starless main.cpp Utils/Logging.cpp Utils/Logging.h GameManager.cpp GameManager.h MainMenu/MainMenu.cpp MainMenu/MainMenu.h)
#target_link_libraries(Starless ${SDL2_LIBRARIES})
target_link_libraries(Starless SDL2::SDL2)