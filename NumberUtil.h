//
// Created by berke on 2/3/2025.
//

#ifndef NUMBERUTIL_H
#define NUMBERUTIL_H
class NumberUtil {
public:
    static int signum(int val) ;
    static int calculateFactorial(int val);
    static int getDigitsCount(int val);
    static int getDigitsSum(int val);
    static int power(int base, int exp);
    static bool isArmstrong(int val);
    static bool isPowerOfTwo(int val);
    static bool isPrime(int val);
    static bool isPrimeX(int val);
    static double getENumber();
};
#endif //NUMBERUTIL_H
