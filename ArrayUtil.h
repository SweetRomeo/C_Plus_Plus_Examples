//
// Created by berke on 2/10/2025.
//

#ifndef ARRAYUTIL_H
#define ARRAYUTIL_H
class ArrayUtil {
public:
    static void swap(int &a, int &b);
    static void genericSwap(void *a, void *b, size_t size);
    static void printArray(const int* arr, size_t size);
    static void reverseArray(int* arr, size_t size);
};
#endif //ARRAYUTIL_H
