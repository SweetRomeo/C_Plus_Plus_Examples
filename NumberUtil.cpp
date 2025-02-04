//
// Created by berke on 2/3/2025.
//

#include "NumberUtil.h"

int NumberUtil::signum(int val)
{
    if (val < 0)
        return -1;
    if (val == 0)
        return 0;
    return 1;
}


int NumberUtil::calculateFactorial(const int number)
{
    return number <= 1 ? 1 : number * calculateFactorial(number - 1);
}

int NumberUtil::getDigitsCount(int val) {
    int count = 0;
    do {
        count++;
        val /= 10;
    } while (val);
    return count;
}

int NumberUtil::getDigitsSum(int val) {
    int sum = 0;
    while (val) {
        sum += val % 10;
        val /= 10;
    }
    return sum;
}

int NumberUtil::power(const int base, const int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

bool NumberUtil::isArmstrong(const int val) {
    int result = 0;
    int count = getDigitsCount(val);
    int temp = val;
    while (temp) {
        result += power(count, temp % 10);
        temp /= 10;
    }
    return result == val;
}


bool NumberUtil::isPowerOfTwo(const int val) {
    return (val & (val - 1)) == 0 && val != 0;
}


bool NumberUtil::isPrime(const int val) {
    if (val <= 1) {
        return false;
    }
    if (val % 2 == 0) {
        return val == 2;
    }
    if (val % 3 == 0) {
        return val == 3;
    }
    if (val % 5 == 0) {
        return val == 5;
    }
    if (val % 7 == 0) {
        return val == 7;
    }
    if (val % 11 == 0) {
        return val == 11;
    }
    for (int i = 13; i * i <= val; i+=2) {
        if (val % i == 0) {
            return false;
        }
    }
    return true;
}

bool NumberUtil::isPrimeX(int val) {
    do {
        if (!isPrime(val)) {
            return false;
        }
        val = getDigitsCount(val);
    } while (val);
    return true;
}

double NumberUtil::getENumber() {
    double e = 1.0;
    for (int i = 0; i < 13; ++i) {
        e += static_cast<double>(1) / calculateFactorial(i);
    }
    return e;
}



