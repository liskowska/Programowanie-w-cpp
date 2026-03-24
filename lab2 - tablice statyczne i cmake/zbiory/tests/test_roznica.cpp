#include <gtest/gtest.h>
#include "../include/roznica.hpp"

const int MAX_SIZE = 100;

TEST(RoznicaTest, PodstawowaRoznica) {
    int A[] = {1, 2, 3, -4, 5};
    int nA = 5;
    int B[] = {2, 5, 6};
    int nB = 3;

    int wynik[MAX_SIZE];
    int nW = 0;

    roznica(nA, A, nB, B, wynik, nW);

    // Oczekujemy: {1, 3, -4}
    ASSERT_EQ(nW, 3);
    EXPECT_EQ(wynik[0], 1);
    EXPECT_EQ(wynik[1], 3);
    EXPECT_EQ(wynik[2], -4);
}

TEST(RoznicaTest, ZbioryIdentyczne) {
    int A[] = {10, 20, 30};
    int wynik[MAX_SIZE];
    int nW = 100;

    roznica(3, A, 3, A, wynik, nW);

    EXPECT_EQ(nW, 0);
}

TEST(RoznicaTest, ZbioryRozlaczne) {
    int A[] = {1, 2, 3};
    int B[] = {4, 5, 6};
    int wynik[MAX_SIZE];
    int nW = 0;

    roznica(3, A, 3, B, wynik, nW);

    ASSERT_EQ(nW, 3);
    EXPECT_EQ(wynik[0], 1);
    EXPECT_EQ(wynik[1], 2);
    EXPECT_EQ(wynik[2], 3);
}

TEST(RoznicaTest, OdejmijPusty) {
    int A[] = {1, 2};
    int B[] = {};
    int wynik[MAX_SIZE];
    int nW = 0;

    roznica(2, A, 0, B, wynik, nW);

    EXPECT_EQ(nW, 2);
}

TEST(RoznicaTest, OdPustegoOdejmij) {
    int A[] = {};
    int B[] = {1, 2, 3};
    int wynik[MAX_SIZE];
    int nW = 0;

    roznica(0, A, 3, B, wynik, nW);

    EXPECT_EQ(nW, 0);
}