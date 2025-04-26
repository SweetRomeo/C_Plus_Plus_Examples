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

bool StringUtil::isValidUsername(std::string str) {
    int len = Length(str);
    if (len < 4 || len > 25 || !isalpha(str[0]) || str[len - 1] == '_') {
        return false;
    }
    for (char ch : str) {
        if (!isalnum(ch) && ch != '_') {
            return false;
        }
    }
    return true;
}

std::vector<int> StringUtil::stringToVec(const std::string &str)
{
    std::vector<int> iVec;
    std::string temp;
    for (char i : str) {
        if (i != ',' && i != ' ') {
            temp += i;
        }
        else if (!temp.empty()) {
            int val = std::stoi(temp);
            iVec.emplace_back(val);
            temp = "";
        }
    }
    if (!temp.empty()) {
        int val = std::stoi(temp);
        iVec.emplace_back(val);
    }
    return iVec;
}

std::string StringUtil::FindIntersection(std::string strArr[]) {

    std::vector<int> vecFirst = stringToVec(strArr[0]);
    std::vector<int> vecSecond = stringToVec(strArr[1]);
    std::string resText;
    for (int i = 0; i < vecFirst.size(); ++i) {
        for (int j = 0; j < vecSecond.size(); ++j) {
            if (vecFirst[i] == vecSecond[j]) {
                resText += std::to_string(vecFirst[i]);
                resText += ',';
            }
        }
    }
    if (resText.empty()) {
        return "false";
    }
    return resText.substr(0, resText.size() - 1);
}

void StringUtil::findIntersectionTest() {
    std::string sArr1 []{"1, 3, 4, 7, 13", "1, 2, 4, 13, 15"};
    std::string sArr2 []{"1, 3, 9, 10, 17, 18", "1, 4, 9, 10"};
    std::string sArr3 []{"1, 2, 3, 4, 5", "6, 7, 8, 9, 10"};
    auto first = FindIntersection(sArr1);
    auto second = FindIntersection(sArr2);
    auto third = FindIntersection(sArr3);
    std::cout << "First Test Case: " << first << '\n';
    std::cout << "Second Test Case: "<<second << '\n';
    std::cout << "Third Test Case: " << third << '\n';
}

std::string StringUtil::LongestWord(const std::string& str) {
    std::string temp;
    std::string resText;
    for (const char ch : str) {
        if (isalnum(ch)) {
            temp += ch;
        }
        else {
            if (temp.size() > resText.size()) {
                resText = temp;
            }
            temp = "";
        }
    }
    if (temp.size() > resText.size()) {
        resText = temp;
    }
    return resText;
}

bool StringUtil::QuestionMarks(const std::string &str) {
    int prevNum = -1;
    int questionMarksCount = 0;
    bool foundPair = false;
    for (const char ch : str) {
        if (isdigit(ch)) {
            const int currentNum = ch - '0';
            if (prevNum != -1 && prevNum + currentNum == 10) {
                if (questionMarksCount == 3) {
                    foundPair = true;
                }
                else {
                    return false;
                }
            }
            prevNum = currentNum;
            questionMarksCount = 0;
        }
        else if (ch == '?') {
            questionMarksCount++;
        }
    }
    return foundPair;
}

void StringUtil::QuestionMarksTest() {
    std::string testCaseFirst = "arrb6???4xxbl5???eee5";
    std::string testCaseSecond = "asjk1?4";
    std::string testCaseThird = "asj2?";
    std::string testCaseFourth = "asj3???7ajal";
    std::cout << QuestionMarks(testCaseFirst) << '\n';
    std::cout << QuestionMarks(testCaseSecond) << '\n';
    std::cout << QuestionMarks(testCaseThird) << '\n';
    std::cout << QuestionMarks(testCaseFourth) << '\n';
}

std::vector<std::string> StringUtil::getWords(const std::string &str) {
    using namespace std;
    vector<string> words;
    string temp;
    for (const char ch : str) {
        if (ch != ' ') {
            words.emplace_back(temp);
            temp = "";
        }
        else {
            temp += ch;
        }
    }
    words.emplace_back(temp);
    return words;
}

int StringUtil::countRepeatingLetters(const std::string &word) {
    int count = 0;
    for (int i = 0; i < word.size(); ++i) {
        if (word.find(word[i]) != word.rfind(word[i]))
        {
            count++;
        }
    }
    return count;
}

std::string StringUtil::LetterCount(std::string str) {
    using namespace std;
    vector<string> wordVec = getWords(str);
    int greatestRepeatingLetter = -1;
    string greatestRepeatingText;
    for (auto& word : wordVec) {
        if (countRepeatingLetters(word) > greatestRepeatingLetter) {
            greatestRepeatingLetter = countRepeatingLetters(word);
            greatestRepeatingText = word;
        }
    }
    return greatestRepeatingLetter == 0 ? "-1" : greatestRepeatingText;
}

