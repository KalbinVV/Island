#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

// Singletone

#include <map>

#include "Graphics/ISprite.h"
#include "Graphics/SpriteEnum.h"

class GraphicsStorage
{
private:
    static GraphicsStorage* uniquePtr;

    int _amountOfSpritesInStorage;
    std::map<SpriteEnum, ISprite*> _spritesDict;

    GraphicsStorage();
    ISprite* genSprite(SpriteEnum spriteEnum);

public:
    static GraphicsStorage* init();
    static void unInit();

    ISprite* initSprite(SpriteEnum spriteEnum);
    ~GraphicsStorage();
};

#endif // GRAPHICS_H_INCLUDED