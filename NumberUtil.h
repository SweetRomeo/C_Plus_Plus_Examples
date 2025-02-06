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
    static void printDiamond(int n);
    static void printFactors(int val);
    static int sumFactors(int val);
    static bool isPerfect(int val);
    static int reverse(int val);
    static bool isValid(int val);
    static int getOnes(int val);
    static int getTens(int val);
    static int getHundreds(int val);
    static int calculateDigitalRoot(int val);
    static bool isFactorian(int val);
    static bool isSuperPrime(int val);
    static void isSuperPrimeTest();
};
#endif //NUMBERUTIL_H
