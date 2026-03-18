#include <gtest/gtest.h>
#include "../include/czyZawiera.hpp"

TEST(CzyZawieraTest, PodzbiorWlasciwy) {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {2, 4};
    EXPECT_TRUE(czyZawiera(5, A, 2, B));
}

TEST(CzyZawieraTest, ZbioryIdentyczne) {
    int A[] = {1, 2, 3};
    int B[] = {3, 2, 1};
    EXPECT_TRUE(czyZawiera(3, A, 3, B));
}

TEST(CzyZawieraTest, BWiekszyNizA) {
    int A[] = {1, 2};
    int B[] = {1, 2, 3};
    EXPECT_FALSE(czyZawiera(2, A, 3, B));
}

TEST(CzyZawieraTest, TenSamRozmiarRozneElementy) {
    int A[] = {1, 2, 3};
    int B[] = {1, 2, 4};
    EXPECT_FALSE(czyZawiera(3, A, 3, B));
}

TEST(CzyZawieraTest, CzyZawieraPusty) {
    int A[] = {1, 2, 3};
    int B[] = {};
    EXPECT_TRUE(czyZawiera(3, A, 0, B));
}

TEST(CzyZawieraTest, LiczbyUjemneInkluzja) {
    int A[] = {-10, 0, 10, 20, -5};
    int B[] = {-5, 20, -10};
    EXPECT_TRUE(czyZawiera(5, A, 3, B));
}