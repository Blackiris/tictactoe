#ifndef BACKEND_H
#define BACKEND_H

#include "../utils/vector2d.h"
#include "../game_state.h"

enum class MouseButtonName {
    MOUSE_LEFT, MOUSE_RIGHT
};

class Backend {
public:
    virtual void init(const int &screen_width, const int &screen_height) = 0;
    virtual void begin() = 0;
    virtual void end() = 0;
    virtual void close() = 0;
    virtual bool should_window_closed() = 0;
    virtual void display_board(const GameState &game_state) = 0;
    virtual Vector2D get_mouse_pos(const int &grid_size) const = 0;
    virtual bool is_mouse_button_pressed(const MouseButtonName &button_name) const = 0;
};

#endif // BACKEND_H
