#include "Core/Game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Stage/DefaultStage.h"
#include "World/Tile/TileBuilder.h"

Game* Game::uniquePtr = nullptr;

void Game::initModules()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
}

void Game::unInitModules()
{
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}

Game::Game(const char* title, int width, int height)
{
    _window.open(title, width, height);
    _renderer.bindWindow(&_window);
    _stage = new DefaultStage(this);

    const int defaultViewRange = 5;
    _viewRange = defaultViewRange;
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

void Game::initWorld(int worldWidth, int worldHeight)
{
    _worldMap.initMap(worldWidth, worldHeight);
    _worldMap.set(5, 5, TileBuilder::getTile(TileEnum::Tree));
}

WorldMap* Game::getWorldMap()
{
    return &_worldMap;
}

int Game::getViewRange()
{
    return _viewRange;
}

void Game::setViewRange(int viewRange)
{
    _viewRange = viewRange;
}

void Game::openFont(const char* path, unsigned int ptSize)
{
    _font.open(path, ptSize);
}

Font* Game::getFont()
{
    return &_font;
}

Player* Game::getPlayer(){
    return &_player;
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