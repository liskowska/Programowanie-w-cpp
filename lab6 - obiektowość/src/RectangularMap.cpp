#include <sstream>
#include <iomanip>
#include <format>
#include <vector>
#include <string>

#include "mapVisualizer.hpp"
#include "car.hpp"
#include "vector2d.hpp"
#include "mapDirection.hpp"
#include "moveDirection.hpp"


using namespace std;
using namespace MapDirection;

bool RectangularMap::isOccupied(Vector2d position) {
    for (auto& car : cars) {
        if (car.position() == position) {
            return true;
        }
    }
    return false;
}

vector<MoveDirection> RectangularMap::parse(int argc, char* argv[]) {
    vector<MoveDirection> moves;
    
    // od 1, bo argv[0] to nazwa programu
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        
        for (char c : arg) {
            if (c == 'f') moves.push_back(MoveDirection::FORWARD); //pushback = append
            else if (c == 'b') moves.push_back(MoveDirection::BACKWARD);
            else if (c == 'l') moves.push_back(MoveDirection::LEFT);
            else if (c == 'r') moves.push_back(MoveDirection::RIGHT);
            // nieprawidłowe wartości są ignorowane
        }
    }
    return moves;
}

void RectangularMap::run(const vector<MoveDirection>& moves) {
    if (cars.empty()) return;

    for (size_t i = 0; i < moves.size(); ++i) {
        int carIndex = i % cars.size();
        cars[carIndex].move(moves[i]);
    }
}

Car* RectangularMap::objectAt(Vector2d position) {
    for (auto& car : cars) {
        if (car.position() == position) {
            return &car; // kopia znalezionego auta
        }
    }
    
    return nullptr;
}

string RectangularMap::toString(){
    MapVisualizer visualizer(*this);

    Vector2d lowerLeft;
    lowerLeft.x(0);
    lowerLeft.y(0);

    Vector2d upperRight; 
    upperRight.x(n - 1);
    upperRight.y(m-1);

    return visualizer.draw(lowerLeft, upperRight);    
}
