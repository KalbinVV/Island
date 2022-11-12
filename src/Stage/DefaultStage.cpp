#include "Stage/DefaultStage.h"

#include <cmath>

#include <SDL2/SDL.h>

#include "Graphics/AsciiSprite.h"
#include "World/Tile/Tile.h"

DefaultStage::DefaultStage(Game* game)
{
    _game = game;
}

void DefaultStage::drawPlayer()
{
    Window* window = _game->getWindow();
    const int viewRange = _game->getViewRange();

    const int spriteWidth = window->getWidth() / viewRange;
    const int spriteHeight = window->getHeight() / viewRange;

    SDL_Rect dstRect { 
        x : viewRange / 2 * spriteWidth + spriteWidth / 3,
        y : viewRange / 2 * spriteHeight + spriteHeight / 3, 
        w : static_cast<int>(spriteWidth * 0.45), 
        h : static_cast<int>(spriteHeight * 0.45) 
    };

    _game->getPlayer()->draw(_game->getRenderer(), &dstRect);
}

void DefaultStage::drawMap()
{
    const int viewRange = _game->getViewRange();
    const int windowWidth = _game->getWindow()->getWidth();
    const int windowHeight = _game->getWindow()->getHeight();
    const int spriteWidth = static_cast<int>(std::ceil(windowWidth / static_cast<float>(viewRange)));
    const int spriteHeight = static_cast<int>(std::ceil(windowHeight / static_cast<float>(viewRange)));
    const Vec2i playerPosition = _game->getPlayer()->getPosition();
    const int worldWidth = _game->getWorldMap()->getWidth();
    const int worldHeight = _game->getWorldMap()->getHeight();
    WorldMap* worldMap = _game->getWorldMap();

    for(int i = playerPosition.y - viewRange; i <= playerPosition.y + viewRange; i++) {
        for(int j = playerPosition.x - viewRange; j <= playerPosition.x + viewRange; j++) {
            if(i < worldHeight && i >= 0 && j < worldWidth && j >= 0) {
                SDL_Rect dstRect {
                    x : (j - playerPosition.x + (viewRange / 2)) * spriteWidth,
                    y : (i - playerPosition.y + (viewRange / 2)) * spriteHeight,
                    w : spriteWidth,
                    h : spriteHeight
                };
                worldMap->at(i, j)->draw(_game->getRenderer(), &dstRect);
            }
        }
    }
}

void DefaultStage::render()
{
    Renderer* renderer = _game->getRenderer();
    renderer->clear(SDL_Color { r : 32, g : 18, b : 8 });

    drawMap();
    drawPlayer();

    renderer->update();
}

void DefaultStage::handleEvents()
{

    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            _game->getWindow()->close();
        }else if(event.type == SDL_WINDOWEVENT){
            if(event.window.event == SDL_WINDOWEVENT_RESIZED){
                _game->getWindow()->setWidth(event.window.data1);
                _game->getWindow()->setHeight(event.window.data2);
            }
        } else if(event.type == SDL_KEYDOWN) {
            Player* player = _game->getPlayer();
            WorldMap* worldMap = _game->getWorldMap();
            Vec2i newPosition = player->getPosition();
            switch(event.key.keysym.scancode) {
                case SDL_SCANCODE_RIGHT:
                case SDL_SCANCODE_D:{
                    newPosition = newPosition.addX(1);
                    break;
                }
                case SDL_SCANCODE_LEFT:
                case SDL_SCANCODE_A:
                    newPosition = newPosition.addX(-1);
                    break;
                case SDL_SCANCODE_DOWN:
                case SDL_SCANCODE_S:
                    newPosition = newPosition.addY(1);
                    break;
                case SDL_SCANCODE_UP:
                case SDL_SCANCODE_W:
                    newPosition = newPosition.addY(-1);
                    break;
                default:
                    break;
            }
            if(newPosition.x >= 0 && newPosition.x < worldMap->getWidth() && newPosition.y >= 0 &&
                newPosition.y < worldMap->getHeight()) {
                ITile* tile = worldMap->at(newPosition.y, newPosition.x);
                if(tile->onMove(player)) {
                    player->setPosition(newPosition);
                }
            }
        }
    }
}