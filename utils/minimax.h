#pragma once

#include "../game_state.h"
#include "vector2d.h"
#include <vector>

namespace Minimax {
struct MinimaxTree {
    GameState game_state;
    Vector2D move_just_played;
    int player_now;

    std::vector<MinimaxTree> next_steps;
};

Vector2D find_best_move(const GameState &game_state, const int &player, const unsigned max_depth);
MinimaxTree generate_minimax_tree(const GameState &game_state, const int &player, const Vector2D &previous_move, const unsigned &max_depth);
int minmax(const MinimaxTree &minimax_tree, int maximize_player, bool maximize);
}
