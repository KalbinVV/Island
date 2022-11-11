#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Core/Renderer.h"
#include "Core/Window.h"
#include "Stage/IStage.h"
#include "Core/Font.h"
#include "World/WorldMap.h"
#include "World/Entity/Player.h"

// Global game singletone

class Game
{
private:
    Window _window;
    Renderer _renderer;
    Font _font;
    IStage* _stage;
    WorldMap _worldMap;
    int _viewRange;
    Player _player;

    static Game* uniquePtr;

    Game(const char* title, int width, int height);

public:
    // sdl modules [un]initialization
    static void initModules();
    static void unInitModules();

    static Game* init();

    Window* getWindow();
    Renderer* getRenderer();
    void initWorld(int worldWidth, int worldHeight);
    WorldMap* getWorldMap();
    int getViewRange();
    void setViewRange(int viewRange);
    void openFont(const char* path, unsigned int ptSize);
    Font* getFont();
    Player* getPlayer();
    void run();
    ~Game();
};

#endif // GAME_H_INCLUDED