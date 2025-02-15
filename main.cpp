#include <iostream>

#include "Date.h"
#include "NumberUtil.h"
#include "ArrayUtil.h"

#define SIZE 30

int main() {
    //NumberUtil::Operation();
    // Date d1{12,2,2019};
    // Date d2{11,2,2019};
    // std::cout << d1-d2 << std::endl;
    int arr[SIZE];
    ArrayUtil::setRandomArray(arr, SIZE);
    ArrayUtil::printArray(arr, SIZE);
    auto mode = ArrayUtil::getMode(arr, SIZE);
    std::cout << mode << std::endl;
    return 0;
}
