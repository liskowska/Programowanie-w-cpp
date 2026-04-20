#pragma once

#include <string>
using namespace std;

class Vector2d{
    private:
        int x_;
        int y_;
    
    public:
    int x();
    int y();

    void x(int new_x);
    void y(int new_y);
    void vector2d(int new_x, int new_y);

    bool operator==(Vector2d other);
    string toString();

    bool precedes(Vector2d other);
    bool follows(Vector2d other);
    Vector2d add(Vector2d other) ;
    Vector2d substract(Vector2d other);
    Vector2d upperRight(Vector2d other);
    Vector2d lowerLeft(Vector2d other);
    Vector2d opposite();
};