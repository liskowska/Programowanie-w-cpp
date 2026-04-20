#include <string>
#include<sstream>
#include "vector2d.hpp"

using namespace std;

int Vector2d::x() {return x_;}
int Vector2d::y() {return y_;}

void Vector2d::x(int new_x){x_ = new_x;}
void Vector2d::y(int new_y){y_ = new_y;}
void Vector2d::vector2d(int new_x, int new_y){
    x_ = new_x;
    y_ = new_y;
}

bool Vector2d::operator==(Vector2d other){
    if (x_ == other.x_ && y_ == other.y_) return true;
    else return false;
}

string Vector2d::toString(){
    ostringstream oss;
    oss << "(" << x_ << ", "<< y_ << ")";
    return oss.str();
}

bool Vector2d::precedes(Vector2d other) {
    return (x_ <= other.x_ && y_ <= other.y_);
}

bool Vector2d::follows(Vector2d other) {
    return x_ >= other.x_ && y_ >= other.y_;
}

Vector2d Vector2d::add(Vector2d other) {
    Vector2d vector2d;
    vector2d.x(x_ + other.x_);
    vector2d.y(y_ + other.y_);
    return vector2d;
}

Vector2d Vector2d::substract(Vector2d other) {
    Vector2d vector2d;
    vector2d.x(x_ - other.x_);
    vector2d.y(y_ - other.y_);
    return vector2d;    
}

Vector2d Vector2d::upperRight(Vector2d other) {
    int x = x_;
    int y = y_;

    if (other.x_ > x)
        x = other.x_;
    if (other.y_ > y)
        y = other.y_;

    Vector2d vector2d;
    vector2d.x_ = x;
    vector2d.y_ = y;

    return vector2d;
}

Vector2d Vector2d::lowerLeft(Vector2d other) {
    int x = x_;
    int y = y_;
    if (other.x_ < x)
        x = other.x_;
    if (other.y_ < y)
        y = other.y_;

    Vector2d vector2d;
    vector2d.x_ = x;
    vector2d.y_ = y;

    return vector2d;
}

Vector2d Vector2d::opposite() {
    int x = -x_;
    int y = -y_;

    Vector2d vector2d;
    vector2d.x_ = x;
    vector2d.y_ = y;

    return vector2d;
}



















