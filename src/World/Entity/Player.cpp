#include "World/Entity/Player.h"

#include <stdexcept>

#include "Core/Game.h"
#include "Graphics/GraphicsStorage.h"

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
    WorldMap* worldMap = Game::init()->getWorldMap();
    const int worldWidth = worldMap->getWidth();
    const int worldHeight = worldMap->getHeight();
    
    if(position.x < 0 || position.x >= worldWidth || position.y < 0 || position.y >= worldHeight) {
        throw std::invalid_argument("Invalid player move!"); //TODO: add exception
    }
    
    _position = position;
}

void Player::draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect)
{
    GraphicsStorage::init()->initSprite(_spriteEnum)->draw(renderer, dstRect, srcRect);
}

std::string Player::getName(){
    return "Player";
}