//
// Created by berke on 3/2/2025.
//
#include "StringUtil.h"
#include <iostream>

decltype(auto) StringUtil::Length(const char *str) {
    auto len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

decltype(auto) StringUtil::Length(const std::string &str) {
    auto len = 0;
    for (auto it = str.begin(); it != str.end(); ++it) {
        len++;
    }
    return len;
}



void StringUtil::reverseString(char *str) {
    const auto len = Length(str);
    for (auto i = 0; i < len / 2; i++) {
        std::swap(str[i], str[len - i - 1]);
    }
}

void StringUtil::reverseString(std::string &str) {
    const auto len = Length(str);
    for (auto i = 0; i < len / 2; i++) {
        std::swap(str[i], str[len - i - 1]);
    }
}

char* StringUtil::textInnerParenthesis(const char *str) {
    int inner_start = -1;
    int inner_end = -1;
    for (int i = Length(str) - 1; i >= 0; i--) {
        if (str[i] == '}') {
            inner_end = i;
        }
    }

    for (int i = inner_end; 0 <= i; i--) {
        if (str[i] == '{') {
            inner_start = i;
            break;
        }
    }
    if (inner_start == -1 || inner_end == -1) {
        return const_cast<char*>("Invalid Test");
    }
    char* result = static_cast<char*> (malloc(sizeof(char) * (inner_end - inner_start)));
    if (result == nullptr) {
        return nullptr;
    }
    int index = 0;
    for (int i = inner_start + 1; i < inner_end; i++) {
        result[index++] = str[i];
    }
    result[index] = '\0';
    return result;
}

decltype(auto) StringUtil::textInnerParenthesis(const std::string &str) {
    int inner_start = str.rfind('{');
    int inner_end = str.find('}');
    if (inner_start == std::string::npos || inner_end == std::string::npos) {
        return std::string("Invalid Enter");
    }
    return str.substr(inner_start + 1, inner_end - inner_start - 1);
}

void StringUtil::textInnerParenthesisTest() {
    std::string test1 {"This question {is {not hard}} actually"};
    std::string test2 {"This {question {is {not hard actually}. We} will do} harder ones."};
    std::string test3 {"This question {is not hard."};
    std::cout << "std::string Overload:" << '\n';
    std::cout << textInnerParenthesis(test1) << '\n';
    std::cout << textInnerParenthesis(test2) << '\n';
    std::cout << textInnerParenthesis(test3) << '\n';
    std::cout << "c_str Overload:" << '\n';
    std::cout << textInnerParenthesis(test1.c_str()) << '\n';
    std::cout << textInnerParenthesis(test2.c_str()) << '\n';
    std::cout << textInnerParenthesis(test3.c_str()) << '\n';
}

void StringUtil::printText(const char *str) {
    int len = Length(str);
    char* temp = new char[len + 1];

    for (int i = 0; i < len; i++) {
        temp[i] = str[i];
        temp[i + 1] = '\0';
        std::cout << temp << '\n';
    }
    delete[] temp;
}


void StringUtil::printText(std::string &str) {
    std::string temp;
    for (auto it = str.begin(); it != str.end(); ++it) {
        temp += *it;
        std::cout << temp << '\n';
    }
}

