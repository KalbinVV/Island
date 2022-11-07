#include "Core/Renderer.h"

#include <SDL2/SDL.h>

#include <stdexcept>

Renderer::Renderer()
{
    _sdlRenderer = nullptr;
    _window = nullptr;
}

SDL_Renderer* Renderer::getSdlRenderer()
{
    return _sdlRenderer;
}

void Renderer::bindWindow(Window* window)
{
    _sdlRenderer = SDL_CreateRenderer(window->getSdlWindow(), -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(_sdlRenderer == nullptr) {
        throw std::invalid_argument(SDL_GetError()); // TODO: add exception
    }

    _window = window;
}

Window* Renderer::getWindow()
{
    return _window;
}

void Renderer::unBindWindow()
{
    if(_sdlRenderer == nullptr) {
        throw std::invalid_argument("Renderer is not created!"); // TODO: add exception
    }

    SDL_DestroyRenderer(_sdlRenderer);
    _sdlRenderer = nullptr;
    _window = nullptr;
}

void Renderer::clear(SDL_Color color)
{
    if(_sdlRenderer == nullptr) {
        throw std::invalid_argument("Renderer is not created!"); // TODO: add exception
    }

    SDL_SetRenderDrawColor(_sdlRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(_sdlRenderer);
}

void Renderer::update()
{
    SDL_RenderPresent(_sdlRenderer);
}

Renderer::~Renderer(){
    if(_sdlRenderer != nullptr) {
        SDL_DestroyRenderer(_sdlRenderer);
    }
}