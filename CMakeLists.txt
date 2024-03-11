cmake_minimum_required(VERSION 3.20)
project(Minka)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR ../../SFML/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML 2.6 COMPONENTS graphics audio REQUIRED)

add_executable(Minka main.cpp
        MainMenu.hpp
        MainMenu.cpp
        Functions.cpp
        Functions.hpp
        SettingsMenu.cpp
        SettingsMenu.hpp
        Game.cpp
        Game.hpp
        Class.cpp
        Class.hpp)

target_link_libraries(Minka sfml-graphics sfml-audio)
