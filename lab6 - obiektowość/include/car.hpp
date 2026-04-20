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
    Vector2d position();
    Direction Direction();

    string toString();
    bool isAt(Vector2d position);
    void move(MoveDirection direction);
};