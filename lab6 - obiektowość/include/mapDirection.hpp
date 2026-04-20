#ifndef MAP_DIRECTION_HPP
#define MAP_DIRECTION_HPP

#include<string>

using namespace std;

namespace MapDirection {
    enum Direction {
        NORTH,
        SOUTH,
        EAST,
        WEST
    };
    
    string toString(Direction mapDirection);

    Direction next(Direction mapDirection);

    Direction previous(Direction mapDirection);
}
#endif