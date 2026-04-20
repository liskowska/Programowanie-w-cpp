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
        };
    }

    Direction next(Direction mapDirection){
        switch(mapDirection){
            case NORTH: EAST;
            case EAST: SOUTH;
            case SOUTH: WEST;
            case WEST: NORTH;
        }
    }

    Direction previous(Direction mapDirection){
        switch(mapDirection){
            case NORTH: WEST;
            case WEST: SOUTH;
            case SOUTH: EAST;
            case EAST : NORTH;
        }
    }

}