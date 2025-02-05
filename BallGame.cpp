//
// Created by berke on 2/5/2025.
//
#include "BallGame.h"

void BallGame::run() {
    int width;
    int height;
    std::cout << "Please enter the width of your ball" << std::endl;
    std::cin >> width;
    std::cout << "Please enter the height of your ball" << std::endl;
    std::cin >> height;
    if (width < 1 || height < 1) {
        throw std::invalid_argument("Invalid width or height");
    }
    BallShape(width, height);
}

void BallGame::BallShape(int width, int height) {
    int BallIndex = 0;
    bool directionFlag = true;
    while (height--) {
        std::cout << "|";
        for (int i = 0; i < BallIndex; i++) {
            std::cout << " ";
        }
        std::cout << "*";
        for (int i = BallIndex; i < width - 1; i++) {
            std::cout << " ";
        }
        std::cout << "|\n";
        if (directionFlag) {
            BallIndex++;
        } else {
            BallIndex--;
        }
        if (directionFlag && BallIndex == width - 1) {
            directionFlag = false;
        } else if (!directionFlag && BallIndex == 0) {
            directionFlag = true;
        }
    }
}