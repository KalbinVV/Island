#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Core/Vec2i.h"
#include "Graphics/ISprite.h"
#include "Graphics/SpriteEnum.h"

class Player : ISprite
{
private:
    SpriteEnum _spriteEnum;
    Vec2i _position;

public:
    Player();
    Vec2i getPosition();
    void setPosition(Vec2i position);
    void move(Vec2i position);
    void draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect = NULL) override;
};

#endif // PLAYER_H_INCLUDED