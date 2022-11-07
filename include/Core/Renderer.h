#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <SDL2/SDL.h>

#include "Core/Window.h"

class Renderer
{
private:
    SDL_Renderer* _sdlRenderer;
    Window* _window;

public:
    Renderer();
    SDL_Renderer* getSdlRenderer();
    void bindWindow(Window* window);
    Window* getWindow();
    void unBindWindow();
    void clear(SDL_Color color);
    void update();
    ~Renderer();
};

#endif // RENDERER_H_INCLUDED