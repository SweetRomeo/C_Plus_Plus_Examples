//
// Created by berke on 3/2/2025.
//

#ifndef STRINGUTIL_H
#define STRINGUTIL_H
#include <string>

class StringUtil {
public:
    static decltype(auto) Length(const char* str);
    static decltype(auto) Length(const std::string& str);
    static void reverseString(char * str);
    static void reverseString(std::string& str);
    static char* textInnerParenthesis(const char* str);
    static decltype(auto) textInnerParenthesis(const std::string& str);
    static void textInnerParenthesisTest();
    static void printText(const char* str);
    static void printText(std::string& str);
    static bool isValidUsername(std::string str);
};
#endif //STRINGUTIL_H
