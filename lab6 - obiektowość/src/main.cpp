#include<iostream>
#include<string>

#include "vector2d.hpp"
#include "car.hpp"
#include "rectangularMap.hpp"

using namespace std;

int main(int argc, char* argv[]){
int width = 10;
    int height = 5;
    RectangularMap map(width, height);

    Car car1(Vector2d(2, 2), MapDirection::NORTH);
    Car car2(Vector2d(5, 3), MapDirection::EAST);
    Car car3(Vector2d(8, 0), MapDirection::WEST);

    map.addCar(car1);
    map.addCar(car2);
    map.addCar(car3);

    std::vector<MoveDirection> moves = map.parse(argc, argv);
    std::cout << "Mapa przed ruchami:" << std::endl;
    std::cout << map.toString() << std::endl;

    map.run(moves);

    std::cout << "Mapa po wykonaniu ruchow:" << std::endl;
    std::cout << map.toString() << std::endl;

    return 0;
}
