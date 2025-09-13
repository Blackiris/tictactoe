#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <array>

class GameState
{
public:
    GameState();
    int grid_size = 3;
    std::array<std::array<int, 3>, 3> values;

    int get_winner() const;
};

#endif // GAME_STATE_H
