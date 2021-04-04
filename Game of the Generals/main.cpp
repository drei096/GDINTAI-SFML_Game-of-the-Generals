#include "Game.h"
#include "Level.h"

/* CHANGES AS OF 4/4/2021 4:26 PM
* added classes of each piece, modeled after airplanePlayer by korbocoder
* added texturemanager, properly loads all piece textures na
* added game object manager, works properly pa naman, pwede mo icheck
* Level.cpp properly loads and plays, need ko lang ayusin yung exit to menu button
* mouse input recognition in FiveStarG.cpp 
* 
* WHAT IS NEEDED TO WORK ON
* = moving the 5 star general sample piece doon sa FiveStarG.cpp
* = localized piece recognition, narerecogize kasi mouse input anywhere on the screen,
*   mouse input should be recognized kapag naclick lang yung piece. Kagaya sa nangyayari sa buttons natin
* 
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