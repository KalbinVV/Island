#include "Graphics/GraphicsStorage.h"

#include <stdexcept>

#include "Core/Game.h"
#include "Graphics/AsciiSprite.h"
#include "Graphics/AtlasSprite.h"
#include "Graphics/SpriteAtlasesStorage.h"

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
    case SpriteEnum::Ground: {
        sprite = new AtlasSprite(SpriteAtlasesStorage::init()
            ->getSpriteAtlas(SpriteAtlasEnum::Tiles), 
            SDL_Rect { x : 1, y : 1, w : 10, h : 10 }, game->getRenderer());
        break;
    }
    case SpriteEnum::Player: {
        sprite = new AtlasSprite(SpriteAtlasesStorage::init()
            ->getSpriteAtlas(SpriteAtlasEnum::People), 
            SDL_Rect { x : 1, y : 0, w : 10, h : 10 }, game->getRenderer());
        break;
    }
    case SpriteEnum::Grass: {
        sprite = new AsciiSprite(game->getFont(), '_', SDL_Color { r : 49, g : 89, b : 67 }, game->getRenderer());
        break;
    }
    case SpriteEnum::Tree: {
        sprite = new AtlasSprite(SpriteAtlasesStorage::init()
            ->getSpriteAtlas(SpriteAtlasEnum::Tiles), 
            SDL_Rect { x : 30, y : 2, w : 10, h : 10 }, game->getRenderer());
        break;
    }
    default:
        throw std::invalid_argument("Invalid spriteEnum!"); // TODO: add exception
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