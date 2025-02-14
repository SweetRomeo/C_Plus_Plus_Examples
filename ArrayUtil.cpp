//
// Created by berke on 2/10/2025.
//
#include "ArrayUtil.h"
#include <iostream>
#include <random>

void ArrayUtil::printArray(const int* arr, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void ArrayUtil::setRandomArray(int *arr, size_t size) {
    std::random_device rd;
    std::mt19937 generator{rd()};
    std::uniform_int_distribution<int> distribution{0,20};
    for (int i = 0; i < size; i++) {
        arr[i] = distribution(generator);
    }
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

void ArrayUtil::reverseArray(int *arr, const size_t size) {
    const auto halfSize = size / 2;
    for (int i = 0; i < halfSize; i++) {
        swap(arr[i], arr[size - i - 1]);
    }
}

bool ArrayUtil::isSorted(const int *arr, const size_t size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != arr[size - i - 1]) {
            return false;
        }
    }
    return true;
}

int ArrayUtil::getMax(const int *arr, const size_t size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int ArrayUtil::getMin(const int *arr, const size_t size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int ArrayUtil::getSum(const int *arr, const size_t size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int ArrayUtil::getMode(const int *arr, size_t size) {
    int mode = 0;
    int modeCount = 0;
    int modeCountTemp = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
             if (arr[i] == arr[j] && i != j) {
                 modeCountTemp++;
             }
        }
        if (modeCountTemp > modeCount) {
            mode = arr[i];
            modeCount = modeCountTemp;
        }
        modeCountTemp = 0;
    }
    return mode;
}


void ArrayUtil::bubbleSort(int *arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int k = 0 ; k < size - i - 1; k++) {
            if (arr[k] > arr[k + 1]) {
                swap(arr[k], arr[k + 1]);
            }
        }
    }
}

void ArrayUtil::selectionSort(int *arr, const size_t size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void ArrayUtil::insertionSort(int *arr, const size_t size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void ArrayUtil::quickSort(int *arr, const size_t size) {
    for (int i = 0; i < size; i++) {
        arr[i] = getMax(arr, size);
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[getMax(arr, size)]) {
                swap(arr[j], arr[getMax(arr, size)]);
            }
        }
    }
}

int ArrayUtil::LinearSearch(const int *arr, const int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int ArrayUtil::BinarySearch(const int *arr, const int size, int value) {
    int low = 0;
    int high = size - 1;
    int mid = (low + high) / 2;
    while (low <= high) {
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] < value) {
            low = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        }
    }
    return -1;
}

int ArrayUtil::BinarySearchTest() {
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;
    int *arr = new int[size];
    bool isSorted = isSorted();
    int searchValue;
    std::cout << "Enter searching element:\n";
    std::cin >> searchValue;
    if (isSorted) {
        int index = BinarySearch(arr, size, searchValue);
        if (index == -1) {
            std::cout << "Element not found\n";
        } else {
            std::cout << "Element found at index " << index << "\n";
        }
    }
    else {
        int index = LinearSearch(arr, size, searchValue);
        if (index == -1) {
            std::cout << "Element not found\n";
        }
        else {
            std::cout << "Element found at index " << index << "\n";
        }
    }
}

