#include "game_logic.h"

#include "game_state.h"
#include "utils/minimax.h"

#include <raylib.h>

GameLogic::GameLogic(Backend &backend): backend(backend) {}


void display_help() {
    DrawText("Left click to place choice", 20, 20, 20, RED);
}

void display_winner(const int &winner) {
    DrawText(TextFormat("Winner is Player %i", winner), 20, 150, 20, RED);
}

int GameLogic::start() {
    const unsigned grid_size = 3;
    const unsigned cpu_max_depth = 10;
    backend.init(300, 300);
    bool is_player_turn = true;
    GameState current_game_state(grid_size);
    bool game_finished = false;


    while (!backend.should_window_closed()) {
        backend.begin();

        if (!game_finished) {
            if (is_player_turn) {
                Vector2D mouse_pos = backend.get_mouse_pos(grid_size);
                if (backend.is_mouse_button_pressed(MouseButtonName::MOUSE_LEFT)
                    && current_game_state.values[mouse_pos.x][mouse_pos.y] == 0) {
                    current_game_state.values[mouse_pos.x][mouse_pos.y] = 1;
                    is_player_turn = !is_player_turn;
                }
            } else {
                Vector2D best_move = Minimax::find_best_move(current_game_state, 2, cpu_max_depth);
                current_game_state.values[best_move.x][best_move.y] = 2;
                is_player_turn = !is_player_turn;
            }
        }

        const int winner = current_game_state.get_winner();
        if (winner > 0) {
            display_winner(winner);
        }

        if (winner > 0 || current_game_state.get_available_moves().empty()) {
            game_finished = true;
        }

        backend.display_board(current_game_state);

        display_help();
        backend.end();
    }
    backend.close();

    return 0;
}


