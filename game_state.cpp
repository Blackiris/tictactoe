#include "game_state.h"
#include <algorithm>

GameState::GameState() {
    for (auto& column: values) {
        column.fill(0);
    }
}

int GameState::get_winner() const {
    int winner = 0;
    bool has_win = false;
    // Check columns
    for (auto& column: values) {
        has_win = column[0]>0 && std::all_of(column.begin(), column.end(), [&](int v) {return v == column[0];});
        if (has_win) {
            winner = column[0];
        }
    }

    if (!has_win) {
        // Check lines
        for (int line=0; line<grid_size; line++) {
            int first = values[0][line];
            has_win = true;
            for (int col=1; col<grid_size; col++) {
                if (values[col][line] != first) {
                    has_win = false;
                    break;
                }
            }

            if (has_win) {
                winner = first;
                break;
            }
        }
    }

    if (!has_win) {
        // Check diagonals
        int first = values[0][0];
        has_win = true;
        for (int i=1; i<grid_size; i++) {
            if (values[i][i] != first) {
                has_win = false;
                break;
            }
        }
        if (has_win) {
            winner = first;
        } else {
            has_win = true;
            first = values[0][grid_size-1];
            for (int i=1; i<grid_size; i++) {
                if (values[i][grid_size-i-1] != first) {
                    has_win = false;
                    break;
                }
            }
            if (has_win) {
                winner = first;
            }
        }
    }

    return winner;
}
