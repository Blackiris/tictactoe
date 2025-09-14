#include "minimax.h"
#include <algorithm>
#include <limits>

namespace Minimax {
Vector2D find_best_move(const GameState &game_state, const int &player, const unsigned max_depth){
    MinimaxTree minimax_tree = generate_minimax_tree(game_state, player, {-1, -1}, max_depth);

    Vector2D move = {0, 0};
    int best_score = std::numeric_limits<int>::min();

    for (unsigned i=0; i<minimax_tree.next_steps.size(); i++) {
        MinimaxTree next_minimax_tree = minimax_tree.next_steps[i];
        int new_score = minmax(next_minimax_tree, player, false);
        if (new_score > best_score) {
            best_score = new_score;
            move = next_minimax_tree.move_just_played;
        }
    }

    return move;
}

MinimaxTree generate_minimax_tree(const GameState &game_state, const int &player, const Vector2D &previous_move, const unsigned &max_depth) {
    std::vector<MinimaxTree> next_steps;

    if (game_state.get_winner() == 0 && max_depth > 0) {
        const std::vector<Vector2D> available_moves = game_state.get_available_moves();
        std::transform(available_moves.cbegin(), available_moves.cend(), std::back_inserter(next_steps), [&](const Vector2D& move) {
            GameState new_game_state(game_state);
            new_game_state.values[move.x][move.y] = player;
            return generate_minimax_tree(new_game_state, player == 1 ? 2 : 1, move, max_depth-1);
        });
    }

    return {game_state, previous_move, player, std::move(next_steps)};
}

int minmax(const MinimaxTree &minimax_tree, int maximize_player, bool maximize) {
    const std::vector<MinimaxTree> &next_opponent_steps = minimax_tree.next_steps;

    //Leaf
    if (next_opponent_steps.empty()) {
        const int winner = minimax_tree.game_state.get_winner();
        if (winner == 0) {
            return 0;
        }
        return winner == maximize_player ? 10 : -10;
    }

    std::vector<int> next_steps_scores;
    std::transform(next_opponent_steps.cbegin(), next_opponent_steps.cend(), std::back_inserter(next_steps_scores), [&](const MinimaxTree& minmax_tree) {
        return minmax(minmax_tree, maximize_player, !maximize);
    });

    if (maximize) {
        auto max = std::max_element(next_steps_scores.cbegin(), next_steps_scores.cend());
        return *max;
    } else {
        auto min = std::min_element(next_steps_scores.cbegin(), next_steps_scores.cend());
        return *min;
    }
}
}
