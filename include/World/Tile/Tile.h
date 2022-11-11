#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include "Graphics/ISprite.h"
#include "Graphics/SpriteEnum.h"

class Tile : public ISprite
{
private:
    SpriteEnum _spriteEnum;

public:
    Tile();
    Tile(SpriteEnum spriteEnum);
    void draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect = NULL) override;
};

#endif // TILE_H_INCLUDED