#include <gtest/gtest.h>
#include "vector2d.hpp"

// konstruktory i gettery
TEST(Vector2dTest, ConstructorAndGetters) {
    Vector2d v1(10, 20);
    EXPECT_EQ(v1.x(), 10);
    EXPECT_EQ(v1.y(), 20);

    Vector2d v2; // Domyślny (0,0)
    EXPECT_EQ(v2.x(), 0);
    EXPECT_EQ(v2.y(), 0);
}

// settery
TEST(Vector2dTest, Setters) {
    Vector2d v;
    v.x(5);
    v.y(15);
    EXPECT_EQ(v.x(), 5);
    EXPECT_EQ(v.y(), 15);
}

// operator ==
TEST(Vector2dTest, EqualityOperator) {
    Vector2d v1(2, 3);
    Vector2d v2(2, 3);
    Vector2d v3(4, 5);

    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 == v3);
}

// precedes i follows
TEST(Vector2dTest, PrecedesFollows) {
    Vector2d v1(1, 1);
    Vector2d v2(2, 2);
    Vector2d v3(1, 2);

    EXPECT_TRUE(v1.precedes(v2));
    EXPECT_TRUE(v1.precedes(v3));
    EXPECT_TRUE(v2.follows(v1));
    EXPECT_FALSE(v1.follows(v2));
}

// dodawanie i odejmowanie
TEST(Vector2dTest, ArithmeticOperations) {
    Vector2d v1(1, 2);
    Vector2d v2(3, 4);

    Vector2d sum = v1.add(v2);
    EXPECT_EQ(sum.x(), 4);
    EXPECT_EQ(sum.y(), 6);

    Vector2d diff = v2.subtract(v1);
    EXPECT_EQ(diff.x(), 2);
    EXPECT_EQ(diff.y(), 2);
}

// upperRight, lowerLeft
TEST(Vector2dTest, BoundsOperations) {
    Vector2d v1(1, 5);
    Vector2d v2(3, 2);

    Vector2d ur = v1.upperRight(v2);
    EXPECT_EQ(ur.x(), 3);
    EXPECT_EQ(ur.y(), 5);

    Vector2d ll = v1.lowerLeft(v2);
    EXPECT_EQ(ll.x(), 1);
    EXPECT_EQ(ll.y(), 2);
}

// wektora przeciwny i toString
TEST(Vector2dTest, OppositeAndString) {
    Vector2d v(5, -10);
    
    Vector2d opp = v.opposite();
    EXPECT_EQ(opp.x(), -5);
    EXPECT_EQ(opp.y(), 10);

    EXPECT_EQ(v.toString(), "(5, -10)");
}