//
// Created by berke on 2/3/2025.
//

#include "NumberUtil.h"

#include <iostream>
#include <random>
#include <climits>

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

void NumberUtil::printDiamond(const int n) {
    bool directionFlag = true;
    int index = 0;
    while (true) {
        for (int i = 0; i < n - index; ++i) {
            std::cout << " ";
        }
        for (int i = 0; i < 2 * index + 1; ++i) {
            std::cout << "*";
        }
        if (directionFlag) {
            index++;
        }
        else {
            index--;
        }
        if (index == n) {
            directionFlag = false;
        }
        if (index < 0) {
            break;
        }
        std::cout << "\n";
    }
}

void NumberUtil::printFactors(int val) {
    int factor = 2;
    while (val != 1) {
        if (val % factor == 0) {
            std::cout << factor << " ";
            val /= factor;
        }
        else {
            factor++;
        }
    }
}

int NumberUtil::sumFactors(const int val) {
    int sum = 0;
    int factor = 1;
    while (factor <= val / 2) {
        if (val % factor == 0) {
            sum += factor;
        }
        factor++;
    }
    return sum;
}

bool NumberUtil::isPerfect(const int val) {
    return sumFactors(val) == val;
}

int NumberUtil::reverse(int val) {
    int reversed = 0;
    while (val != 0) {
        reversed = reversed * 10 + val % 10;
        val = val / 10;
    }
    return reversed;
}

bool NumberUtil::isValid(int val) {
    int a = getHundreds(val);
    int b = getTens(val);
    int c = getOnes(val);
    const int rev = reverse(b);
    return rev > val && isPrime(rev) && isPrime(val) && isPrime(10 * a + b) && isPrime(10 * b + c) &&
        isPrime(10 * c + b) && isPrime(10 * b + a);
}

int NumberUtil::getOnes(const int val) {
    return val % 10;
}

int NumberUtil::getTens(const int val) {
    return val % 100 / 10;
}

int NumberUtil::getHundreds(const int val) {
    return val / 100;
}

int NumberUtil::calculateDigitalRoot(int val) {
    while (val / 10 != 0) {
        val = getDigitsSum(val);
    }
    return val;
}

bool NumberUtil::isFactorian(const int val) {
    int result = 0;
    int temp = val;
    do {
        result += calculateFactorial(temp % 10);
        temp /= 10;
    } while (temp);
    return result == val;
}

bool NumberUtil::isSuperPrime(int val) {
    int index = 0;
    for (int i = 2; i <= val; ++i) {
        if (isPrime(i)) {
            ++index;
        }
    }
    return isPrime(index) && isPrime(val);
}

void NumberUtil::isSuperPrimeTest() {
    for (int i = 2; i <= 1000; ++i) {
        if (isSuperPrime(i)) {
            std::cout << i << std::endl;
        }
    }
}

double NumberUtil::crapsGame(int numberOfPlays) {
    std::random_device rd;
    std::mt19937 diceFirst(rd());
    std::mt19937 diceSecond(rd());
    std::uniform_int_distribution<int> distributionFirst(1, 6);
    std::uniform_int_distribution<int> distributionSecond(1, 6);
    int numberOfWins = 0;
    for (int i = 0; i < numberOfPlays; ++i) {
        int dice1 = distributionFirst(diceFirst);
        int dice2 = distributionSecond(diceSecond);
        if (dice1 + dice2 == 7 || dice1 + dice2 == 11) {
            ++numberOfWins;
        }
        else if (dice1 + dice2 == 2 || dice1 + dice2 == 3 || dice1 + dice2 == 12)
            ;
        else {
            int tempDice = dice1 + dice2;
            while (true) {
                dice1 = distributionFirst(diceFirst);
                dice2 = distributionSecond(diceSecond);
                if (dice1 + dice2 == 7) {
                    break;
                }
                if (dice1 + dice2 == tempDice) {
                    ++numberOfWins;
                    break;
                }
            }
        }
    }
    return static_cast<double>(numberOfWins) / numberOfPlays;
}

void NumberUtil::crapsGameTest() {
    int numberOfPlays;
    std::cout << "Enter number of plays: ";
    std::cin >> numberOfPlays;
    std::cout << "Chance to win to the craps game: " << crapsGame(numberOfPlays) << std::endl;
}

void NumberUtil::displayCollatz(int val) {
    if (val == 1)
        return;
    std::cout << val << " ";
    while (true) {
        if (val == 1) {
            break;
        }
        val = val % 2 == 0 ? val / 2 : 3 * val + 1;
        std::cout << val << " ";
    }
}

void NumberUtil::Operation() {
    int count = 0;
    int sum = 0;
    int max = INT_MIN;
    int min = INT_MAX;
    while (true) {
        char ch;
        std::cout << "Yeni bir deger girmek istiyor musunuz?\n";
        while ((ch = getchar()) != '1' && ch != '0')
            ;
        if (ch == '1') {
            int val;
            std::cout << "Bir tamsayi giriniz:";
            jump:
            std::cin >> val;
            if (val < 0 || val > 100) {
                std::cout << "Gecersiz giris\n";
                std::cout << "Yeni bir deger giriniz:";
                goto jump;
            }
            if (val > max) {
                max = val;
            }
            if (val < min) {
                min = val;
            }
            sum += val;
            count++;
        }
        else {
            break;
        }
    }
    std::cout << "Toplam " << count << " deger girildi.\n";
    std::cout << "Max = " << max << "\n";
    std::cout << "Min = " << min << "\n";
    std::cout << "Ortalama = " << static_cast<double>(sum) / count << "\n";
    std::cout << "Program sonlandi\n";
}