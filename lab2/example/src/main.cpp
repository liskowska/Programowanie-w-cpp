#include <iostream>
#include <format>
#include <sum.hpp>

int main()
{
    int a;
    int b;
    int result;

    std::cout << "Wprowadź dwie liczby: ";
    std::cin >> a >> b;
    result = sum(a, b);
    std::cout << std::format("{}+{}={}", a, b, result) << std::endl;

    return 0;
}