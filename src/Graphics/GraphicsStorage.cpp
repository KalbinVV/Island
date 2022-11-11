#include "Graphics/GraphicsStorage.h"

#include <stdexcept>

#include "Core/Game.h"
#include "Graphics/AsciiSprite.h"

GraphicsStorage* GraphicsStorage::uniquePtr = nullptr;

GraphicsStorage::GraphicsStorage()
{
    _amountOfSpritesInStorage = 0;
}

GraphicsStorage* GraphicsStorage::init()
{
    if(uniquePtr == nullptr) {
        uniquePtr = new GraphicsStorage();
    }

    return uniquePtr;
}

void GraphicsStorage::unInit()
{
    if(uniquePtr == nullptr) {
        throw std::invalid_argument("Graphics storage is not started!"); // TODO: add exception
    }

    delete uniquePtr;
}

ISprite* GraphicsStorage::genSprite(SpriteEnum spriteEnum)
{
    ISprite* sprite = nullptr;
    Game* game = Game::init();
    _amountOfSpritesInStorage++;

    switch(spriteEnum) {
    case SpriteEnum::Player: {
        sprite = new AsciiSprite(game->getFont(), '#', 
            SDL_Color { r : 220, g : 96, b : 46 }, 
            game->getRenderer());
        break;
    }
    case SpriteEnum::Grass: {
        sprite = new AsciiSprite(game->getFont(), '_', 
            SDL_Color { r : 49, g : 89, b : 67 }, 
            game->getRenderer());
        break;
    }
    case SpriteEnum::Tree: {
        sprite = new AsciiSprite(game->getFont(), 't', 
            SDL_Color { r : 162, g : 215, b : 41 }, 
            game->getRenderer());
        break;
    }
    }

    return sprite;
}

ISprite* GraphicsStorage::initSprite(SpriteEnum spriteEnum)
{
    if(_spritesDict.count(spriteEnum) > 0) {
        return _spritesDict.at(spriteEnum);
    }

    _spritesDict[spriteEnum] = genSprite(spriteEnum);

    return _spritesDict.at(spriteEnum);
}

GraphicsStorage::~GraphicsStorage()
{
    for(std::pair<SpriteEnum, ISprite*> pr : _spritesDict) {
        delete pr.second;
    }
}