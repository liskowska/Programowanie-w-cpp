#include <gtest/gtest.h>
#include "car.hpp"
#include "vector2d.hpp"
#include "moveDirection.hpp"

// skrecanie
TEST(CarTest, RotationTest) {
    Car car(Vector2d(2, 2), MapDirection::NORTH);
    
    car.move(MoveDirection::RIGHT);
    EXPECT_EQ(car.direction(), MapDirection::EAST);
    
    car.move(MoveDirection::LEFT);
    EXPECT_EQ(car.direction(), MapDirection::NORTH);
}

// poruszanie do przodu
TEST(CarTest, MoveForwardWithinBounds) {
    Car car(Vector2d(2, 2), MapDirection::NORTH);
    
    car.move(MoveDirection::FORWARD); // (2, 2) NORTH -> (2, 3)
    EXPECT_EQ(car.position().x(), 2);
    EXPECT_EQ(car.position().y(), 3);
    EXPECT_EQ(car.direction(), MapDirection::NORTH);
}

// poruszanie do tylu (w granicach mapy)
TEST(CarTest, MoveBackwardWithinBounds) {
    Car car(Vector2d(2, 2), MapDirection::SOUTH);
    
    car.move(MoveDirection::BACKWARD); // (2, 2) SOUTH + BACKWARD -> (2, 3)
    EXPECT_EQ(car.position().y(), 3);
}

// odbicie od sciany (poruszanie do produ poza mapa)
TEST(CarTest, BoundaryCollisionTest) {
    Car car(Vector2d(2, 4), MapDirection::NORTH);
    
    car.move(MoveDirection::FORWARD);
    
    EXPECT_EQ(car.position().x(), 2);
    EXPECT_EQ(car.position().y(), 4);
    EXPECT_EQ(car.direction(), MapDirection::SOUTH);
}

// toString
TEST(CarTest, ToStringFormat) {
    Car car(Vector2d(0, 0), MapDirection::WEST);
    std::string expectedStart = "Direction:";
    EXPECT_EQ(car.toString().substr(0, 10), expectedStart);
}
