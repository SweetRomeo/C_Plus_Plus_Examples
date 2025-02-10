//
// Created by berke on 2/10/2025.
//
#include "ArrayUtil.h"
#include <iostream>

void ArrayUtil::printArray(const int* arr, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void ArrayUtil::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void ArrayUtil::genericSwap(void *a, void *b, size_t size) {
    auto cp1 = static_cast<char*>(a);
    auto cp2 = static_cast<char*>(b);
    while (size--)
    {
        const char temp = *cp1;
        *cp1 = *cp2;
        *cp2 = temp;
        cp1++;
        cp2++;
    }
}

