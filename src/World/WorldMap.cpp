#include "World/WorldMap.h"

#include <stdexcept>

WorldMap::WorldMap()
{
    _tiles = nullptr;
}

void WorldMap::initMap(int worldWidth, int worldHeight)
{
    _worldWidth = worldWidth;
    _worldHeight = worldHeight;

    _tiles = new Tile*[worldHeight];

    for(int i = 0; i < worldHeight; i++) {
        _tiles[i] = new Tile[worldWidth];
    }
}

int WorldMap::getWidth()
{
    return _worldWidth;
}

int WorldMap::getHeight()
{
    return _worldHeight;
}

Tile* WorldMap::at(int y, int x)
{
    if(y < 0 || y >= _worldHeight || x < 0 || x >= _worldWidth) {
        throw std::invalid_argument("Invalid index in worldmap!");
    }

    return &_tiles[y][x];
}

void WorldMap::set(int y, int x, Tile tile)
{
    if(y < 0 || y >= _worldHeight || x < 0 || x >= _worldWidth) {
        throw std::invalid_argument("Invalid index in worldmap!");
    }

    _tiles[y][x] = tile;
}

WorldMap::~WorldMap()
{
    for(int i = 0; i < _worldHeight; i++) {
        delete[] _tiles[i];
    }

    delete[] _tiles;
}