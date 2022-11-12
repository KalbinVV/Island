
#include "World/Tile/TileBuilder.h"

#include <stdexcept>

#include "World/Tile/TileDelegatesStorage.h"

Tile TileBuilder::getTile(TileEnum tileEnum)
{
    switch(tileEnum) {
        case TileEnum::Tree: {
            Tile tile(SpriteEnum::Tree, "Tree");
            tile.addMoveHandler(TileDelegatesStorage::getFunction(TileDelegateEnum::Nothing));
            tile.addMoveHandler(TileDelegatesStorage::getFunction(TileDelegateEnum::Print));
            return tile;
        }
        case TileEnum::Ground: {
            return Tile(SpriteEnum::Ground, "Ground");
        }
        default:
            throw std::invalid_argument("Tile is not exist!");
            break;
    }
}