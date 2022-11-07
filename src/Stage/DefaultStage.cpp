#include <SDL2/SDL.h>

#include "Stage/DefaultStage.h"

DefaultStage::DefaultStage(Game* game)
{
    _game = game;
}

void DefaultStage::render()
{
    Renderer* renderer = _game->getRenderer();
    renderer->clear(SDL_Color{
       r: 0,
       g: 150,
       b: 255
    });
    renderer->update();
}

void DefaultStage::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            _game->getWindow()->close();
        }
    }
}