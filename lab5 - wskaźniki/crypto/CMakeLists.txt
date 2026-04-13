cmake_minimum_required(VERSION 3.10)
project(
    crypto
    VERSION 0.0.1 
    DESCRIPTION ""
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
    src/encryptXOR.cpp
    src/vulnerability.cpp)
add_executable(main ${SOURCE}) #  Jako wynik kompilacji podanych plików źródłowych ma być tworzony plik wykonywalny 'main' 
target_include_directories(main PUBLIC include) # Określamy katalogi, w których kompilator ma szukać plików nagłówkowych