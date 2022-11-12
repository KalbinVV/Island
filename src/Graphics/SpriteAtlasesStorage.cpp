#include "Graphics/SpriteAtlasesStorage.h"

#include "Core/Game.h"
#include "Graphics/SpriteAtlasEnum.h"

SpriteAtlasesStorage* SpriteAtlasesStorage::uniquePtr = nullptr;

SpriteAtlasesStorage::SpriteAtlasesStorage()
{
    Game* game = Game::init();
    _spriteAtlasesDict = { 
        { SpriteAtlasEnum::Tiles,new SpriteAtlas("./Assets/Tiles.png", game->getRenderer()) },
        { SpriteAtlasEnum::People, new SpriteAtlas("./Assets/People.png", game->getRenderer()) } 
    };
}

SpriteAtlasesStorage* SpriteAtlasesStorage::init()
{
    if(uniquePtr == nullptr) {
        uniquePtr = new SpriteAtlasesStorage();
    }

    return uniquePtr;
}

SpriteAtlas* SpriteAtlasesStorage::getSpriteAtlas(SpriteAtlasEnum spriteAtlasEnum)
{
    return _spriteAtlasesDict.at(spriteAtlasEnum);
}

SpriteAtlasesStorage::~SpriteAtlasesStorage()
{
    for(std::pair<SpriteAtlasEnum, SpriteAtlas*> pr : _spriteAtlasesDict) {
        delete pr.second;
    }
}