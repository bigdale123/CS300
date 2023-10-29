#include <iostream>
#include "pirate.h"
#include "roman.h"

int main() {
    PirateTranslator pt = PirateTranslator();
    pt.runUnitTests();

    std::cout << std::endl;
    std::cout << "MCMLXIX = " << romanToDecimal("MCMLXIX") << std::endl;
    std::cout << "DXLIV = " << romanToDecimal("DXLIV") << std::endl;
    std::cout << "CCCXXXII = " << romanToDecimal("CCCXXXII") << std::endl;
    return 0;
}