#include <iostream>
#include "Game.h"

int main()
{
    //Init Game Engine
    Game game;
    // game loop
    while (game.running())
    {
        // Update
        game.update();

        // Render
        game.render();
    }

    return 0;
}