cmake_minimum_required(VERSION 3.16)

project(TicTacToe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib 5.5 REQUIRED)

add_executable(TicTacToe main.cpp
    game_logic.h game_logic.cpp
    display_backend/raylib_display_backend.h display_backend/raylib_display_backend.cpp

    utils/vector2d.h utils/vector2d.cpp


    game_state.h game_state.cpp
)
target_link_libraries(${PROJECT_NAME} raylib)

include(GNUInstallDirs)
install(TARGETS TicTacToe
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
