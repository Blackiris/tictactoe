#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "display_backend/backend.h"


class GameLogic
{
public:
    GameLogic(Backend &backend);
    int start();

private:
    void init_level();

    Backend &backend;
};

#endif // GAME_LOGIC_H
