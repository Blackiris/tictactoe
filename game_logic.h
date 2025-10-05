#pragma once

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
