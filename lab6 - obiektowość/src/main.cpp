#include<iostream>
#include<string>

#include "vector2d.hpp"
#include "car.hpp"
#include "rectangularMap.hpp"

using namespace std;

int main(){
int width = 10;
    int height = 5;
    RectangularMap map(width, height);

    // 2. Tworzymy kilka samochodów
    // Zakładamy, że masz konstruktor Car(Vector2d, MapDirection)
    Car car1(Vector2d(2, 2), MapDirection::NORTH);
    Car car2(Vector2d(5, 3), MapDirection::EAST);
    Car car3(Vector2d(8, 0), MapDirection::WEST);

    // 3. Dodajemy auta do mapy
    map.addCar(car1);
    map.addCar(car2);
    map.addCar(car3);

    // 4. (Opcjonalnie) Wykonujemy jakieś ruchy, żeby zobaczyć, że to działa
    // "f" - forward, "r" - right, "l" - left
    // Jeśli Twoja metoda run przyjmuje vector<MoveDirection>:
    std::vector<MoveDirection> moves = {
        MoveDirection::FORWARD, // car1 jedzie na (2,3)
        MoveDirection::RIGHT,   // car2 obraca się na SOUTH
        MoveDirection::FORWARD  // car3 jedzie na (7,0)
    };
    
    std::cout << "Mapa przed ruchami:" << std::endl;
    std::cout << map.toString() << std::endl;

    map.run(moves);

    std::cout << "Mapa po wykonaniu ruchow:" << std::endl;
    std::cout << map.toString() << std::endl;

    return 0;
}
