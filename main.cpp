#include <iostream>
#include "calc.hpp"

int main() {
    Calcolatrice c;
    std::cout << "10 + 5 = " << c.somma(10, 5) << std::endl;
    return 0;
}
