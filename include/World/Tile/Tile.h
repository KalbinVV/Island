#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <functional>

#include "Graphics/ISprite.h"
#include "Graphics/SpriteEnum.h"
#include "World/Tile/TileDelegate.h"
#include "World/Entity/IEntity.h"
#include "World/Tile/ITile.h"


class Tile : public ISprite, public ITile
{
private:
    std::string _tileName;
    SpriteEnum _spriteEnum;
    TileDelegate _onMoveDelegate;
    TileDelegate _onUseDelegate;

public:
    Tile();
    Tile(SpriteEnum spriteEnum, std::string tileName);
    void addMoveHandler(std::function<bool(ITile*, IEntity*)> handler);
    void addUseHandler(std::function<bool(ITile*, IEntity*)> handler);
    bool onMove(IEntity* source) override;
    bool onUse(IEntity* source) override;
    void draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect = NULL) override;
    std::string getName() override;
};

#endif // TILE_H_INCLUDED