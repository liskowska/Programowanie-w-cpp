#include <string>

using namespace std;

namespace MapDirection{
    enum Direction{
        NORTH,
        SOUTH,
        EAST,
        WEST
    };
    
    string toString(Direction mapDirection){
        switch(mapDirection){
            case NORTH: return "Polnoc";
            case SOUTH: return "Poludnie";
            case EAST: return "Wschod";
            case WEST: return "Zachod";
            default: throw("Złe wejście!");
        };
    }

    Direction next(Direction mapDirection){
        switch(mapDirection){
            case NORTH: return EAST;
            case EAST: return SOUTH;
            case SOUTH: return WEST;
            case WEST: return NORTH;
            default: throw("Złe wejście!");
        }
    }

    Direction previous(Direction mapDirection){
        switch(mapDirection){
            case NORTH: return WEST;
            case WEST: return SOUTH;
            case SOUTH: return EAST;
            case EAST : return NORTH;
            default: throw("Złe wejście!");
        }
    }

}