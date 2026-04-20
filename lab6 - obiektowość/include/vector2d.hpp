#pragma once

#include <string>
using namespace std;

class Vector2d{
    private:
        int x_;
        int y_;
    
    public:
    Vector2d();
    Vector2d(int x, int y);

    int x();
    int y();

    void x(int new_x);
    void y(int new_y);

    bool operator==(Vector2d other);
    string toString();

    bool precedes(Vector2d other);
    bool follows(Vector2d other);
    Vector2d add(Vector2d other) ;
    Vector2d subtract(Vector2d other);
    Vector2d upperRight(Vector2d other);
    Vector2d lowerLeft(Vector2d other);
    Vector2d opposite();
};