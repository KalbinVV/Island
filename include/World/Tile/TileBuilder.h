#ifndef TILEBUILDER_H_INCLUDED
#define TILEBUILDER_H_INCLUDED

#include "World/Tile/TileEnum.h"
#include "World/Tile/Tile.h"

class TileBuilder{
public:
    static Tile getTile(TileEnum tileEnum);
};

#endif // TILEBUILDER_H_INCLUDED