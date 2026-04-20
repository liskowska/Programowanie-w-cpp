#include <gtest/gtest.h>
#include "vector2d.hpp"

// gettery i settery
TEST(Vector2dTest, SettersAndGetters) {
    Vector2d v;
    v.x(10);
    v.y(20);
    EXPECT_EQ(v.x(), 10);
    EXPECT_EQ(v.y(), 20);
}

// porównanie
TEST(Vector2dTest, EqualityOperator) {
    Vector2d v1, v2, v3;
    v1.vector2d(2, 3);
    v2.vector2d(2, 3);
    v3.vector2d(4, 5);

    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 == v3);
}

// precedes i follows
TEST(Vector2dTest, PrecedesFollows) {
    Vector2d v1, v2;
    v1.vector2d(1, 1);
    v2.vector2d(2, 2);

    EXPECT_TRUE(v1.precedes(v2));
    EXPECT_FALSE(v2.precedes(v1));
    
    EXPECT_TRUE(v2.follows(v1));
    EXPECT_FALSE(v1.follows(v2));
}

// dodawanie i odejmowanie
TEST(Vector2dTest, ArithmeticOperations) {
    Vector2d v1, v2;
    v1.vector2d(10, 5);
    v2.vector2d(2, 3);

    Vector2d resAdd = v1.add(v2);
    EXPECT_EQ(resAdd.x(), 12);
    EXPECT_EQ(resAdd.y(), 8);

    Vector2d resSub = v1.substract(v2);
    EXPECT_EQ(resSub.x(), 8);
    EXPECT_EQ(resSub.y(), 2);
}

// rogi (upperRight / lowerLeft)
TEST(Vector2dTest, BoundsOperations) {
    Vector2d v1, v2;
    v1.vector2d(1, 5);
    v2.vector2d(4, 2);

    Vector2d ur = v1.upperRight(v2);
    EXPECT_EQ(ur.x(), 4);
    EXPECT_EQ(ur.y(), 5);

    Vector2d ll = v1.lowerLeft(v2);
    EXPECT_EQ(ll.x(), 1);
    EXPECT_EQ(ll.y(), 2);
}

// Test napisu toString
TEST(Vector2dTest, ToStringConversion) {
    Vector2d v;
    v.vector2d(-1, 7);
    EXPECT_EQ(v.toString(), "(-1, 7)");
}

// Test wektora przeciwnego
TEST(Vector2dTest, OppositeVector) {
    Vector2d v;
    v.vector2d(3, -4);
    Vector2d opp = v.opposite();
    EXPECT_EQ(opp.x(), -3);
    EXPECT_EQ(opp.y(), 4);
}