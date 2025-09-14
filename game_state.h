#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "utils/vector2d.h"
#include <vector>

class GameState
{
public:
    GameState(const unsigned &grid_size) noexcept;
    unsigned grid_size = 3;
    std::vector<std::vector<int>> values;

    int get_winner() const;
    std::vector<Vector2D> get_available_moves() const;
};

#endif // GAME_STATE_H
