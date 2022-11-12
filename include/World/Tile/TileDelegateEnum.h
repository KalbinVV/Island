#ifndef TILEDELEGATEENUM_H_INCLUDED
#define TILEDELEGATEENUM_H_INCLUDED

enum class TileDelegateEnum{
    Nothing, // Forbid any actions (return false) (can use for all types of actions)
    Print // Print name of tile (For debug only)
};

#endif // TILEDELEGATEENUM_H_INCLUDED