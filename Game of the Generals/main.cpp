#include "Game.h"
#include "Level.h"

int main()
{
    Game game;
    
    while(game.isRunning())
    {
        game.run();
    }
    
    Level level;

    while(level.isRunning())
    {
        level.run();
    }
    
    return 0;
}