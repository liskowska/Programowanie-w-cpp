#include <sstream>
#include <iomanip>
#include <format>
#include <vector>
#include <string>
#include "car.hpp"
#include "vector2d.hpp"
#include "mapDirection.hpp"


using namespace std;
using namespace MapDirection;

class RectangularMap {
    private:
    int n;
    int m;
    vector<Car> cars;

    public:

    bool isOccupied(Vector2d position);
    static vector<MoveDirection> parse(int argc, char* argv[]);
    void run(const vector<MoveDirection>& moves);
    string toString();
    Car* RectangularMap::objectAt(Vector2d position);
};