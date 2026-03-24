#include <gtest/gtest.h>
#include "../include/czyRowne.hpp"

TEST(CzyRowneTest, IdentyczneKolejnosc) {
    int A[] = {1, 2, 3};
    int B[] = {1, 2, 3};
    EXPECT_TRUE(czyRowne(3, A, 3, B));
}

TEST(CzyRowneTest, TaSamaZawartoscInnaKolejnosc) {
    int A[] = {1, 2, 3};
    int B[] = {3, 1, 2};
    EXPECT_TRUE(czyRowne(3, A, 3, B));
}

TEST(CzyRowneTest, RozneRozmiary) {
    int A[] = {1, 2, 3};
    int B[] = {1, 2};
    EXPECT_FALSE(czyRowne(3, A, 2, B));
}

TEST(CzyRowneTest, RozneElementyTenSamRozmiar) {
    int A[] = {1, 2, 3};
    int B[] = {1, 2, 4};
    EXPECT_FALSE(czyRowne(3, A, 3, B));
}

TEST(CzyRowneTest, ObaPuste) {
    int A[] = {};
    int B[] = {};
    EXPECT_TRUE(czyRowne(0, A, 0, B));
}

TEST(CzyRowneTest, LiczbyUjemne) {
    int A[] = {-5, 10, 0};
    int B[] = {0, -5, 10};
    EXPECT_TRUE(czyRowne(3, A, 3, B));
}