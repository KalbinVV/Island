#include <SDL2/SDL.h>

#include "Stage/DefaultStage.h"

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
        x : viewRange / 2 * spriteWidth, 
        y : viewRange / 2 * spriteHeight, 
        w : spriteWidth, 
        h : spriteHeight 
    };

    _game->getPlayer()->draw(_game->getRenderer(), &dstRect);
}

void DefaultStage::drawMap()
{
    const int viewRange = _game->getViewRange();
    const int windowWidth = _game->getWindow()->getWidth();
    const int windowHeight = _game->getWindow()->getHeight();
    const int spriteWidth = windowWidth / viewRange;
    const int spriteHeight = windowHeight / viewRange;
    const Vec2i playerPosition = _game->getPlayer()->getPosition();
    const int worldWidth = _game->getWorldMap()->getWidth();
    const int worldHeight = _game->getWorldMap()->getHeight();
    WorldMap* worldMap = _game->getWorldMap();

    for(int i = playerPosition.y - viewRange; i < playerPosition.y + viewRange; i++) {
        for(int j = playerPosition.x - viewRange; j < playerPosition.x + viewRange; j++) {
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
    renderer->clear(SDL_Color { r : 255, g : 255, b : 255 });

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
        } else if(event.type == SDL_KEYDOWN) {
            Player* player = _game->getPlayer();
            switch(event.key.keysym.scancode) {
            case SDL_SCANCODE_D:
                player->move(player->getPosition().addX(1));
                break;
            case SDL_SCANCODE_A:
                player->move(player->getPosition().addX(-1));
                break;
            case SDL_SCANCODE_S:
                player->move(player->getPosition().addY(1));
                break;
            case SDL_SCANCODE_W:
                player->move(player->getPosition().addY(-1));
                break;
            default:
                break;
            }
        }
    }
}