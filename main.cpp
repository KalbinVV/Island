#include "Core/Game.h"

int main()
{
    Game::initModules();
    
    Game* game = Game::init();
    game->run();
    
    Game::unInitModules();
}