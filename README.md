# TicTacToe
Play TicTacToe against CPU. CPU AI is powered by the Minimax algorithm.

![TicTacToe screenshot](/tictactoe_screenshot.png?raw=true "TicTacToe")

# How to build
On root,

    conan install . --output-folder=build --build=missing

    cd build/build/Release/generators
    cmake ../../../.. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
    cmake --build .

