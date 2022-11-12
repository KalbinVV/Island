#include "Graphics/AtlasSprite.h"

#include <stdexcept>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

AtlasSprite::AtlasSprite(SpriteAtlas* spriteAtlas, SDL_Rect rect, Renderer* renderer)
{
    _rect = SDL_Rect { x : rect.x * rect.w, y : rect.y * rect.h, w : rect.w, h : rect.h };

    _spriteAtlas = spriteAtlas;
}

void AtlasSprite::draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect)
{
    srcRect = &_rect;
    SDL_RenderCopy(renderer->getSdlRenderer(), _spriteAtlas->getTexture(), srcRect, dstRect);
}