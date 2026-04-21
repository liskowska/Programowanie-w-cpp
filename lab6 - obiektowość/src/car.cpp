#include<string>
#include<sstream>
#include "mapDirection.hpp"
#include "vector2d.hpp"
#include "moveDirection.hpp"
#include "car.hpp"

using namespace std;
using namespace MapDirection;

Vector2d Car::position(){return position_;}
Direction Car::direction(){return direction_;}

Car::Car(Vector2d newPosition, Direction newDirection) {
    this->position_ = newPosition;
    this->direction_ = newDirection;
}

string Car::toString(){
    ostringstream oss;
    oss << "Direction: " << direction_ << ". Position: " << position_.toString() << ".";
    return oss.str();
}

bool Car::isAt(Vector2d position){
    return position_ == position;
}

void Car::move(MoveDirection direction){
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

void Car::checkPosition(int step) {
    int newX = position_.x();
    int newY = position_.y();

    // pozycja auta bez granic mapy
    switch(direction_) {
        case MapDirection::NORTH: newY += step; break;
        case MapDirection::SOUTH: newY -= step; break;
        case MapDirection::EAST:  newX += step; break;
        case MapDirection::WEST:  newX -= step; break;
    }

    // jezeli nowa pozycja jest poza mapa to obrot orientacji o 180 stopni
    if (newX >= 0 && newX <= 4 && newY >= 0 && newY <= 4) {
        position_.x(newX);
        position_.y(newY);
    } else {
        direction_ = MapDirection::next(MapDirection::next(direction_));
    }
}