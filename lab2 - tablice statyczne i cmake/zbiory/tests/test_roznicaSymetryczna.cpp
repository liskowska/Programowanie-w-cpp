#include <gtest/gtest.h>
#include "../include/roznicaSymetryczna.hpp"

const int MAX_SIZE = 100;
TEST(RoznicaSymetrycznaTest, PodstawowyScenariusz) {
    int A[] = {1, 2, 3};
    int nA = 3;
    int B[] = {3, 4, 5};
    int nB = 3;

    int wynik[MAX_SIZE];
    int nW = 0;

    roznicaSymetryczna(nA, A, nB, B, wynik, nW);

    ASSERT_EQ(nW, 4);
    EXPECT_EQ(wynik[0], 1);
    EXPECT_EQ(wynik[1], 2);
    EXPECT_EQ(wynik[2], 4);
    EXPECT_EQ(wynik[3], 5);
}

TEST(RoznicaSymetrycznaTest, Przemiennosc) {
    int A[] = {1, 2, 10};
    int B[] = {2, 3, 20};
    
    int wynikAB[MAX_SIZE], wynikBA[MAX_SIZE];
    int nAB = 0, nBA = 0;

    roznicaSymetryczna(3, A, 3, B, wynikAB, nAB);
    roznicaSymetryczna(3, B, 3, A, wynikBA, nBA);

    ASSERT_EQ(nAB, nBA);
    EXPECT_TRUE(nAB == 4);
}

TEST(RoznicaSymetrycznaTest, ZbioryIdentyczne) {
    int A[] = {1, 2, 3};
    int wynik[MAX_SIZE];
    int nW = 100;

    roznicaSymetryczna(3, A, 3, A, wynik, nW);

    EXPECT_EQ(nW, 0);
}

TEST(RoznicaSymetrycznaTest, ZbioryRozlaczne) {
    int A[] = {1, 2};
    int B[] = {3, 4};
    int wynik[MAX_SIZE];
    int nW = 0;

    roznicaSymetryczna(2, A, 2, B, wynik, nW);

    EXPECT_EQ(nW, 4);
}

TEST(RoznicaSymetrycznaTest, JedenPusty) {
    int A[] = {1, 2, 3};
    int B[] = {};
    int wynik[MAX_SIZE];
    int nW = 0;

    roznicaSymetryczna(3, A, 0, B, wynik, nW);

    EXPECT_EQ(nW, 3);
    EXPECT_EQ(wynik[0], 1);
}