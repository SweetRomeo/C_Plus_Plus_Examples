//
// Created by berke on 2/10/2025.
//

#ifndef ARRAYUTIL_H
#define ARRAYUTIL_H
#include <corecrt.h>

class ArrayUtil {
public:
    static void swap(int &a, int &b);
    static void genericSwap(void *a, void *b, size_t size);
    static void setRandomArray(int *arr, size_t size);
    static void printArray(const int* arr, size_t size);
    static void reverseArray(int* arr, size_t size);
    static bool isSorted(const int* arr, size_t size);
    static int getMax(const int* arr, size_t size);
    static int getMin(const int* arr, size_t size);
    static int getSum(const int* arr, size_t size);
    static int getMode(const int* arr, size_t size);
    static void bubbleSort(int* arr, size_t size);
    static void selectionSort(int* arr, size_t size);
    static void insertionSort(int* arr, size_t size);
    static void quickSort(int* arr, size_t size);

};
#endif //ARRAYUTIL_H
