#include "Core/Game.h"
#include "Graphics/GraphicsStorage.h"
#include "World/Entity/Player.h"

Player::Player()
{
    _spriteEnum = SpriteEnum::Player;
    _position = Vec2i { x : 0, y : 0 };
}

Vec2i Player::getPosition()
{
    return _position;
}

void Player::setPosition(Vec2i position)
{
    _position = position;
}

void Player::move(Vec2i position)
{
    WorldMap* worldMap = Game::init()->getWorldMap();
    const int worldWidth = worldMap->getWidth();
    const int worldHeight = worldMap->getHeight();

    if(position.x >= 0 && position.x < worldWidth && position.y >= 0 && position.y < worldHeight) {
        _position = position;
    }
}

void Player::draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect)
{
    GraphicsStorage::init()->initSprite(_spriteEnum)->draw(renderer, dstRect, srcRect);
}