#include "Core/Window.h"
#include <stdexcept>

Window::Window()
{
    _sdlWindow = nullptr;
    _width = 0;
    _height = 0;
    _openFlag = false;
}

SDL_Window* Window::getSdlWindow()
{
    if(_sdlWindow == nullptr) {
        throw std::invalid_argument("Window is not created!"); // TODO: Add exception
    }

    return _sdlWindow;
}

void Window::open(const char* title, int width, int height)
{
    _sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        width, height, SDL_WINDOW_SHOWN);
    if(_sdlWindow == NULL) {
        throw std::invalid_argument(SDL_GetError()); // TODO: Add exception
    }

    _openFlag = true;
    _width = width;
    _height = height;
}

bool Window::isOpen()
{
    return _openFlag;
}

void Window::close()
{
    if(_sdlWindow == nullptr) {
        throw std::invalid_argument("Window is not created!"); // TODO: Add exception
    }

    _openFlag = false;
    SDL_DestroyWindow(_sdlWindow);
    _sdlWindow = nullptr;
}

int Window::getWidth()
{
    return _width;
}

int Window::getHeight()
{
    return _height;
}

Window::~Window()
{
    if(_sdlWindow != nullptr) {
        SDL_DestroyWindow(_sdlWindow);
    }
}