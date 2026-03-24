cmake_minimum_required(VERSION 3.10)
project(
    Sum 
    VERSION 0.0.1 
    DESCRIPTION "Sample Linux VSCode/CMake Project"
    LANGUAGES CXX
)

# Wypisz nazwę oraz katalog główny projektu
message("Project_Name: ${PROJECT_NAME}")
message("Project_Dir: ${CMAKE_CURRENT_SOURCE_DIR}")  

# Opcje kompilatora
set(CMAKE_CXX_STANDARD 20) # Dodaj opcję '-std=c++20'
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug) # Dodaj opcję '-ggdb'

# Pliki źródłowe naszego przykładowego projektu
set(SOURCE 
    src/main.cpp 
    src/sum.cpp
)
add_executable(main ${SOURCE}) #  Jako wynik kompilacji podanych plików źródłowych ma być tworzony plik wykonywalny 'main' 
target_include_directories(main PUBLIC include) # Określamy katalogi, w których kompilator ma szukać plików nagłówkowych

###############
# Dla zadania 3
###############
# include(CTest) 
# find_package(GTest REQUIRED)
# include(GoogleTest)
# add_executable(test_sum tests/test_sum.cpp)
# target_link_libraries(test_sum GTest::gtest_main)
# enable_testing()
# gtest_discover_tests(test_sum)