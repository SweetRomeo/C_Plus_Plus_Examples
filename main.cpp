#include <iostream>

#include "BallGame.h"
#include "Date.h"

int main() {
    try {
        BallGame::run();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}