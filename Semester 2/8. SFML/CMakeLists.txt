cmake_minimum_required(VERSION 3.10)
project(SFML_Example)

set(SFML_ROOT_DIR "/path/to/SFML")  # Укажите здесь путь к установленной библиотеке SFML

find_package(SFML 2.6.1 REQUIRED)

add_executable(SFML_Example main.cpp)

target_include_directories(SFML_Example PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries(SFML_Example ${SFML_LIBRARIES})
