cmake_minimum_required(VERSION 3.25)
project(bezier_curves)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.5.1_2/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(bezier_curves main.cpp)

target_link_libraries(bezier_curves sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
