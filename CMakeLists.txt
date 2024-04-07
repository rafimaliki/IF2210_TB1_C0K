cmake_minimum_required(VERSION 3.22.1)
project(main)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
    src/main.cpp
    src/class/game/game.cpp
    src/class/muat/config_reader.cpp
    src/class/game_object/item_config/item_config.cpp
    src/class/game_object/item/item.cpp
    src/class/game_object/item/plant/plant.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)