#ifndef WORLDMAP_H_INCLDUED
#define WORLDMAP_H_INCLUDED

#include "World/Tile/Tile.h"

class WorldMap
{
private:
    Tile** _tiles;
    int _worldWidth;
    int _worldHeight;

public:
    WorldMap();
    void initMap(int worldWidth, int worldHeight);
    int getWidth();
    int getHeight();
    Tile* at(int y, int x);
    void set(int y, int x, Tile tile);
    ~WorldMap();
};

#endif // WORLDMAP_H_INCLUDED