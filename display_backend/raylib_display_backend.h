#ifndef RAYLIB_DISPLAY_BACKEND_H
#define RAYLIB_DISPLAY_BACKEND_H

#include "backend.h"

class RaylibDisplayBackend : public Backend
{
public:
    RaylibDisplayBackend();

    void init(const int &screen_width, const int &screen_height) override;
    void begin() override;
    void end() override;
    void close() override;
    bool should_window_closed() override;
    void display_board(const GameState &game_state) override;
    Vector2D get_mouse_pos(const int &grid_size) const override;
    bool is_mouse_button_pressed(const MouseButtonName &button_name) const override;

private:
    int screen_width;
    int screen_height;
    int margin = 18;
    int top_margin = 50;

    void draw_cross(Vector2D loc);
    void draw_circle(Vector2D loc);

    int get_h_space() const;
};

#endif // RAYLIB_DISPLAY_BACKEND_H
