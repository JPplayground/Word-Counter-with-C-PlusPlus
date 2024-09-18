cmake_minimum_required(VERSION 3.10)
project(WordFrequencyCounter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(WordFrequencyCounter 
    src/main.cpp
    src/UserInterface.cpp
    src/UserInterface.h
    data/example.txt
)

add_custom_command(
    TARGET WordFrequencyCounter POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/data/example.txt
        $<TARGET_FILE_DIR:WordFrequencyCounter>/example.txt
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT WordFrequencyCounter)

