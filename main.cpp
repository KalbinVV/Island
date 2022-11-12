#include <iostream>

#include "Core/Game.h"

int main()
{
    Game::initModules();

    Game* game = Game::init();
    try {
        game->initWorld(50, 50);
        game->setViewRange(7);
        game->openFont("./Assets/font.ttf", 8);
        game->run();
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    Game::unInitModules();
}