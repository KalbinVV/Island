#include "Graphics/GraphicsStorage.h"
#include "World/Tile/Tile.h"

Tile::Tile(){
    _spriteEnum = SpriteEnum::Grass;
}

Tile::Tile(SpriteEnum spriteEnum)
{
    _spriteEnum = spriteEnum;
}

void Tile::draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect)
{
    GraphicsStorage::init()->initSprite(_spriteEnum)->draw(renderer, dstRect, srcRect);
}