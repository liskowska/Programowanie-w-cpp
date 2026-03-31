cmake_minimum_required(VERSION 3.10)
project(
    Wyrazenia-regularne
    VERSION 0.0.1 
    DESCRIPTION "Program służący do wykonywania poleceń przypomanających komendy 'grep', 'sort' i 'tail' z Basha."
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
    src/grep.cpp
    src/tail.cpp
    src/sort.cpp)
add_executable(main ${SOURCE}) #  Jako wynik kompilacji podanych plików źródłowych ma być tworzony plik wykonywalny 'main' 
target_include_directories(main PUBLIC include) # Określamy katalogi, w których kompilator ma szukać plików nagłówkowych

# testy
# enable_testing()
# find_package(GTest REQUIRED)
# include(GoogleTest)

# # 1. Dodajemy executable - pliki które testuję
# add_executable(unit_tests
#     tests/test_grep
#     tests/test_sort
#     tests/test_tail

#     src/grep.cpp
#     src/sort.cpp
#     src/tail.cpp
# )

# # 2. Gdzie są nagłówki (.hpp) dla testów
# target_include_directories(unit_tests PUBLIC include)

# # 3. Linkowanie bibliotek (używamy nazwy unit_tests, bo tak nazwano executable wyżej)
# target_link_libraries(unit_tests GTest::gtest GTest::gtest_main)

# # 4. Rejestrujemy testy w systemie
# gtest_discover_tests(unit_tests)