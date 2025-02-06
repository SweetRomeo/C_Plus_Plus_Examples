#include <iostream>

#include "BallGame.h"
#include "NumberUtil.h"

int main() {
    std::cout << NumberUtil::sumFactors(28);
    NumberUtil::printFactors(28);
    for (int i = 0; i < 10000; ++i) {
        if (NumberUtil::isPerfect(i))
            std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << NumberUtil::calculateDigitalRoot(36987) << '\n';
    for (int i = 0; i < 100000; ++i) {
        if (NumberUtil::isFactorian(i)) {
            std::cout << i << " ";
        }
    }
    for (int i = 0; i < 14; ++i) {
        std::cout << NumberUtil::calculateFactorial(i) << '\n';
    }
    NumberUtil::isSuperPrimeTest();
    return 0;
}
