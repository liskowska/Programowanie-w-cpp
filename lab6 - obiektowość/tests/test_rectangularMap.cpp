#include <gtest/gtest.h>
#include "rectangularMap.hpp"
#include "car.hpp"
#include "vector2d.hpp"
#include "moveDirection.hpp"

// test parsera
TEST(MapTest, ParseTest) {
    RectangularMap map(5, 5);
    char* args[] = {(char*)"test", (char*)"f", (char*)"b", (char*)"l", (char*)"r"};
    
    auto moves = map.parse(5, args);
    
    ASSERT_EQ(moves.size(), 4);
    EXPECT_EQ(moves[0], MoveDirection::FORWARD);
    EXPECT_EQ(moves[1], MoveDirection::BACKWARD);
    EXPECT_EQ(moves[2], MoveDirection::LEFT);
    EXPECT_EQ(moves[3], MoveDirection::RIGHT);
}

// sprawdzenie wektora cars i funkcji objectAt()
TEST(MapTest, AddAndObjectAtTest) {
    RectangularMap map(10, 10);
    Vector2d pos(3, 3);
    Car car(pos, MapDirection::NORTH);
    
    map.addCar(car);
    
    EXPECT_TRUE(map.isOccupied(pos));
    Car* found = map.objectAt(pos);
    ASSERT_NE(found, nullptr);
    
    EXPECT_EQ(found->position().x(), 3);
    EXPECT_EQ(found->position().y(), 3);
}

// test poruszania aut (move())
TEST(MapTest, RunTest) {
    RectangularMap map(5, 5);
    map.addCar(Car(Vector2d(2, 2), MapDirection::NORTH));
    map.addCar(Car(Vector2d(1, 1), MapDirection::NORTH));
    
    std::vector<MoveDirection> moves = {MoveDirection::FORWARD, MoveDirection::FORWARD};
    map.run(moves);
    
    EXPECT_TRUE(map.isOccupied(Vector2d(2, 3)));
    EXPECT_TRUE(map.isOccupied(Vector2d(1, 2)));
}

// sprawdzanie granic i logiki checkPosition
TEST(MapTest, BoundaryTest) {
    RectangularMap map(5, 5);
    // Auto na górnej krawędzi
    map.addCar(Car(Vector2d(2, 4), MapDirection::NORTH));
    
    // Ruch do przodu (poza mapę) -> powinno zostać na (2,4) i zmienić kierunek na SOUTH
    map.run({MoveDirection::FORWARD});
    
    Car* c = map.objectAt(Vector2d(2, 4));
    ASSERT_NE(c, nullptr);
    // kierunek powinien być teraz SOUTH (1)
    // MapDirection::NORTH to 0, SOUTH to 1. (taka kolejnosc w enumie)
    EXPECT_EQ((int)c->direction(), 1); 
}