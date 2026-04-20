#include<string>
#include<sstream>
#include "mapDirection.hpp"
#include "vector2d.hpp"
#include "moveDirection.hpp"

using namespace std;
using namespace MapDirection;

class Car{
    private:
    Direction direction_ = NORTH;
    Vector2d position_;

    public:
    Vector2d position(){return position_;}
    Direction Direction(){return direction_;}

    string toString(){
        ostringstream oss;
        oss << "Direction: " << direction_ << ". Position: " << position_.toString() << ".";
        return oss.str();
    }

    bool isAt(Vector2d position){
        return position_ == position;
    }

    void move(MoveDirection direction){
        switch(direction){
            case RIGHT: {
                direction_ = next(direction_);
                break;
            }
            case LEFT: {
                direction_ = previous(direction_);
                break;
            }
            case FORWARD: {
                checkPosition(1);
                break;
            }
            case BACKWARD: {
                checkPosition(-1);
                break;
            }
        }
    }

    void checkPosition(int step) {
    int newX = position_.x();
    int newY = position_.y();

    // 1. Obliczamy gdzie auto CHCIAŁOBY być
        switch(direction_) {
            case MapDirection::NORTH: newY += step; break;
            case MapDirection::SOUTH: newY -= step; break;
            case MapDirection::EAST:  newX += step; break;
            case MapDirection::WEST:  newX -= step; break;
        }

        // 2. Sprawdzamy granice mapy (0,0) do (4,4)
        if (newX >= 0 && newX <= 4 && newY >= 0 && newY <= 4) {
            position_.x(newX);
            position_.y(newY);
        } else {
            // 3. Jeśli poza mapą -> odwracamy orientację o 180 stopni
            // Wywołujemy next dwa razy, żeby obrócić się o 180 stopni
            direction_ = MapDirection::next(MapDirection::next(direction_));
        }
    }

};