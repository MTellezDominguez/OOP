#include <iostream>
#include "counter.h"

int main() {
    Counter c(10, 0, 50);
    
    std::cout << "Inicial: " << c << std::endl;

    std::cout << "++c: " << ++c << std::endl;
    std::cout << "c++: " << c++ << std::endl;
    std::cout << "Despues c++: " << c << std::endl;

    std::cout << "--c: " << --c << std::endl;
    std::cout << "c--: " << c-- << std::endl;
    std::cout << "Despues c--: " << c << std::endl;

    Counter c2 = c + 20;
    std::cout << "c + 20: " << c2 << std::endl;

    Counter c3 = 20 + c;
    std::cout << "20 + c: " << c3 << std::endl;

    Counter c4 = c - 5;
    std::cout << "c - 5: " << c4 << std::endl;

    Counter c5 = 100 - c;
    std::cout << "100 - c: " << c5 << std::endl;

    Counter c6(1000, 0, 100);
    std::cout << "Prueba limite max (c + 1000): " << c + 1000 << std::endl;
    std::cout << "Prueba limite min (c - 1000): " << c - 1000 << std::endl;

    std::cout << "Introduce valor (0-50): ";
    std::cin >> c;
    std::cout << "Valor final: " << c << std::endl;

    return 0;
}