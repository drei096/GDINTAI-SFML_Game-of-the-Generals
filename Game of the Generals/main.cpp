#include "Game.h"
#include "Level.h"

int main()
{
    Game game;
    
    while(game.isRunning())
    {
        game.run();
    }
    return 0;
}