#ifndef ATLASSPRITE_H_INCLUDED
#define ATLASSPRITE_H_INCLUDED

#include "Graphics/ISprite.h"
#include "Graphics/SpriteAtlas.h"

class AtlasSprite : public ISprite
{
private:
    SpriteAtlas* _spriteAtlas;
    SDL_Rect _rect;
public:
    AtlasSprite(SpriteAtlas* spriteAtlas, SDL_Rect rect, Renderer* renderer);
    void draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect = NULL) override;
};

#endif