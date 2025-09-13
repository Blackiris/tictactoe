#include "raylib_display_backend.h"
#include "raylib.h"


RaylibDisplayBackend::RaylibDisplayBackend() {}

void RaylibDisplayBackend::init(const int &screen_width_arg, const int &screen_height_arg) {
    screen_width = screen_width_arg;
    screen_height = screen_height_arg;
    InitWindow(screen_width, screen_height, "TicTacToe");
    SetTargetFPS(30);
}

void RaylibDisplayBackend::begin() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void RaylibDisplayBackend::end() {
    EndDrawing();
}

void RaylibDisplayBackend::close() {
    CloseWindow();
}

bool RaylibDisplayBackend::should_window_closed() {
    return WindowShouldClose();
}

void display_cross(int x, int y) {
    DrawLine(x-20, y-20, x+20, y+20, RED);
    DrawLine(x-20, y+20, x+20, y-20, RED);
}

void display_circle(int x, int y) {
    DrawCircleLines(x, y, 20, BLUE);
}

void RaylibDisplayBackend::display_board(const GameState &game_state) {
    const int h_space = (screen_width - margin * 2) / game_state.grid_size;
    const int v_space = (screen_height - top_margin - margin) / game_state.grid_size;

    for (int i=0; i<=game_state.grid_size; i++) {
        // Horizontal lines
        DrawLine(margin, top_margin + i*v_space, screen_width - margin, top_margin + i*v_space, BLACK);

        // Vertical lines
        DrawLine(margin + i*h_space, top_margin, margin + i*h_space, screen_height - margin, BLACK);
    }


    for (int i=0; i<game_state.grid_size; i++) {
        for (int j=0; j<game_state.grid_size; j++) {
            if (game_state.values[i][j] == 1) {
                display_cross(margin+i*h_space+h_space/2, top_margin+j*v_space+v_space/2);
            }
            if (game_state.values[i][j] == 2) {
                display_circle(margin+i*h_space+h_space/2, top_margin+j*v_space+v_space/2);
            }
        }
    }
}

Vector2D RaylibDisplayBackend::get_mouse_pos(const int &grid_size) const {
    const int h_space = (screen_width - margin * 2) / grid_size;
    const int v_space = (screen_height - top_margin - margin) / grid_size;

    const Vector2 pos = GetMousePosition();
    const int x_grid = (pos.x - margin) / h_space;
    const int y_grid = (pos.y - top_margin) / v_space;
    return Vector2D{x_grid, y_grid};
}

bool RaylibDisplayBackend::is_mouse_button_pressed(const MouseButtonName &button_name) const {
    MouseButton rl_mouse_button;
    switch (button_name) {
    case MouseButtonName::MOUSE_LEFT:
        rl_mouse_button = MOUSE_BUTTON_LEFT;
        break;
    case MouseButtonName::MOUSE_RIGHT:
        rl_mouse_button = MOUSE_BUTTON_RIGHT;
        break;
    }

    return IsMouseButtonPressed(rl_mouse_button);
}
