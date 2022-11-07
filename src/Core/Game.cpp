#include "Core/Game.h"

#include <SDL2/SDL.h>

#include "Stage/DefaultStage.h"

Game* Game::uniquePtr = nullptr;

void Game::initModules()
{
    SDL_Init(SDL_INIT_EVERYTHING);
}

void Game::unInitModules()
{
    SDL_Quit();
}

Game::Game(const char* title, int width, int height)
{
    _window.open(title, width, height);
    _renderer.bindWindow(&_window);
    _stage = new DefaultStage(this);
}

Game* Game::init()
{
    if(uniquePtr == nullptr) {
        uniquePtr = new Game("Island", 800, 600);
    }

    return uniquePtr;
}

Window* Game::getWindow()
{
    return &_window;
}

Renderer* Game::getRenderer()
{
    return &_renderer;
}

void Game::run()
{
    while(_window.isOpen()) {
        _stage->handleEvents();
        _stage->render();
    }
}

Game::~Game()
{
    delete _stage;
}