#include <gtest/gtest.h>
#include "../include/suma.hpp"

const int MAX_SIZE = 100;

TEST(SumaTest, LiczbyDodatnieIUjemne) {
    int A[] = {-1, 2, -3};
    int nA = 3;
    int B[] = {-3, 4, 5};
    int nB = 3;
    
    int wynik[MAX_SIZE];
    int nW = 0;

    suma(nA, A, nB, B, wynik, nW);

    ASSERT_EQ(nW, 5);
    EXPECT_EQ(wynik[0], -1);
    EXPECT_EQ(wynik[1], 2);
    EXPECT_EQ(wynik[2], -3);
    EXPECT_EQ(wynik[3], 4);
    EXPECT_EQ(wynik[4], 5);
}

// Przepełnienie tablicy wynikowej ( MAX_SIZE)
TEST(SumaTest, PrzepełnienieTablicyWynikowej) {
    int A[60]; 
    int B[60];
    
    for(int i=0; i<60; i++) A[i] = i;
    for(int i=0; i<60; i++) B[i] = i + 100;

    int wynik[MAX_SIZE];
    int nW = 0;

    // Suma powinna mieć 120 elementów
    suma(60, A, 60, B, wynik, nW);

    EXPECT_EQ(nW, MAX_SIZE);
    EXPECT_EQ(wynik[99], 139); 
}

// Zbiory puste
TEST(SumaTest, ZbioryPuste) {
    int A[] = {};
    int B[] = {1, 2};
    int wynik[MAX_SIZE];
    int nW = 0;

    suma(0, A, 2, B, wynik, nW);

    ASSERT_EQ(nW, 2);
    EXPECT_EQ(wynik[0], 1);
    EXPECT_EQ(wynik[1], 2);
}