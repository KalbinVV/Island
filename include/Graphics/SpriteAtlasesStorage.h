#ifndef SPRITEATLASESSTORAGE_H_INCLUDED
#define SPRITEATLASESSTORAGE_H_INCLUDED

#include <map>

#include "Graphics/SpriteAtlas.h"
#include "Graphics/SpriteAtlasEnum.h"

class SpriteAtlasesStorage
{
private:
    static SpriteAtlasesStorage* uniquePtr;

    SpriteAtlasesStorage();
    std::map<SpriteAtlasEnum, SpriteAtlas*> _spriteAtlasesDict;

public:
    static SpriteAtlasesStorage* init();
    SpriteAtlas* getSpriteAtlas(SpriteAtlasEnum spriteAtlasEnum);
    ~SpriteAtlasesStorage();
};

#endif // SPRITEATLASESSTORAGE_H_INCLUDED