#include "game_logic.h"

#include "game_state.h"

#include <iostream>
#include <raylib.h>

GameLogic::GameLogic(Backend &backend): backend(backend) {}

struct Level {

};

void GameLogic::init_level() {

}

void display_help() {
    DrawText("Left click to place choice", 20, 20, 20, RED);
}

void display_winner(const int &winner) {
    DrawText(TextFormat("Winner is Player %i", winner), 20, 150, 20, RED);
}

int GameLogic::start() {

    backend.init(300, 300);
    init_level();
    bool is_player_turn = true;
    GameState current_game_state;


    while (!backend.should_window_closed()) {
        backend.begin();

        Vector2D mouse_pos = backend.get_mouse_pos(3);
        if (backend.is_mouse_button_pressed(MouseButtonName::MOUSE_LEFT)
                && current_game_state.values[mouse_pos.x][mouse_pos.y] == 0) {
            current_game_state.values[mouse_pos.x][mouse_pos.y] = is_player_turn ? 1 : 2;
            is_player_turn = !is_player_turn;
        }

        const int winner = current_game_state.get_winner();
        if (winner > 0) {
            display_winner(winner);
        }

        backend.display_board(current_game_state);

        display_help();
        backend.end();
    }
    backend.close();

    return 0;
}


