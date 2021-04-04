#include "Game.h"
#include "Level.h"

/* CHANGES AS OF 4/4/2021 11:17 AM
* added classes of each piece, modeled after airplanePlayer by korbocoder
* added texturemanager, properly loads all piece textures na
* added game object manager, works properly pa naman, pwede mo icheck
* Level.cpp properly loads and plays, need ko lang ayusin yung exit to menu button
* 
* WHAT IS NEEDED TO WORK ON
* = moving the 5 star general sample piece doon sa FiveStarG.cpp
* = applying the same to all piece classes
* = exitButton in Level.cpp (ako na dito)
*/

int main()
{
    Game game;
    
    while(game.isRunning())
    {
        game.run();
    }
    return 0;
}