#include <gtest/gtest.h>

int main(int argc, char **argv) {
    // Inicjalizacja silnika Google Test
    testing::InitGoogleTest(&argc, argv);
    
    // przeszukiwanie programu w poszukiwaniu makr TEST(...) 
    // i jego uruchomienie, zwracając wynik do systemu
    return RUN_ALL_TESTS();
}