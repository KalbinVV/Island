#include "World/Tile/TileDelegatesStorage.h"

#include <iostream>
#include <stdexcept>

std::function<bool(ITile*, IEntity*)> TileDelegatesStorage::getFunction(TileDelegateEnum tileDelegateEnum)
{
    switch(tileDelegateEnum) {
    case TileDelegateEnum::Nothing:
        return [](ITile* tile, IEntity* source) { return false; };
    case TileDelegateEnum::Print:
        return [](ITile* tile, IEntity* source) {
            std::cout << "Tile name: " << tile->getName() << "\t"
                      << "Entity name: " << source->getName() << std::endl;
            return true;
        };
    default:
        throw std::invalid_argument("This delegate is not exist!");
    }
}