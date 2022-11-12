#include "Graphics/GraphicsStorage.h"
#include "World/Tile/Tile.h"

Tile::Tile()
{
    _spriteEnum = SpriteEnum::Ground;
}

Tile::Tile(SpriteEnum spriteEnum, std::string tileName)
{
    _spriteEnum = spriteEnum;
    _tileName = tileName;
}

void Tile::addMoveHandler(std::function<bool(ITile*, IEntity*)> handler)
{
    _onMoveDelegate += handler;
}

void Tile::addUseHandler(std::function<bool(ITile*, IEntity*)> handler)
{
    _onUseDelegate += handler;
}

bool Tile::onMove(IEntity* source)
{
    return _onMoveDelegate(this, source);
}

bool Tile::onUse(IEntity* source)
{
    return _onUseDelegate(this, source);
}

void Tile::draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect)
{
    GraphicsStorage::init()->initSprite(_spriteEnum)->draw(renderer, dstRect, srcRect);
}

std::string Tile::getName()
{
    return _tileName;
}