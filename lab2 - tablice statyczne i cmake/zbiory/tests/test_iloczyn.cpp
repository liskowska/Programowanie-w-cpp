#include <gtest/gtest.h>
#include "../include/iloczyn.hpp"

const int MAX_SIZE = 100;
TEST(IloczynTest, PodstawowaCzescWspolna) {
    int A[] = {1, -2, 3, 4};
    int nA = 4;
    int B[] = {5, 3, -2, 9};
    int nB = 4;

    int wynik[MAX_SIZE];
    int nW = 0;

    iloczyn(nA, A, nB, B, wynik, nW);

    ASSERT_EQ(nW, 2);
    EXPECT_EQ(wynik[0], -2);
    EXPECT_EQ(wynik[1], 3);
}

// Zbiory rozłączne 
TEST(IloczynTest, ZbioryRozlaczne) {
    int A[] = {1, 2, 3};
    int B[] = {4, 5, 6};
    int wynik[MAX_SIZE];
    int nW = 100;

    iloczyn(3, A, 3, B, wynik, nW);

    EXPECT_EQ(nW, 0);
}

// Jeden zbiór jest podzbiorem drugiego
TEST(IloczynTest, Podzbior) {
    int A[] = {1, 2};
    int B[] = {0, 1, 2, 3};
    int wynik[MAX_SIZE];
    int nW = 0;

    iloczyn(2, A, 4, B, wynik, nW);

    ASSERT_EQ(nW, 2);
    EXPECT_EQ(wynik[0], 1);
    EXPECT_EQ(wynik[1], 2);
}

// Test 4: Zbiory identyczne
TEST(IloczynTest, IdentynczneZbiory) {
    int A[] = {10, 20, 30};
    int wynik[MAX_SIZE];
    int nW = 0;

    iloczyn(3, A, 3, A, wynik, nW);

    ASSERT_EQ(nW, 3);
    EXPECT_EQ(wynik[0], 10);
    EXPECT_EQ(wynik[1], 20);
    EXPECT_EQ(wynik[2], 30);
}

// Test 5: Pusty zbiór
TEST(IloczynTest, PustyZbior) {
    int A[] = {};
    int B[] = {1, 2, 3};
    int wynik[MAX_SIZE];
    int nW = 0;

    iloczyn(0, A, 3, B, wynik, nW);

    EXPECT_EQ(nW, 0);
}