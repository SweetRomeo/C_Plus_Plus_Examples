#include <iostream>

#include "Date.h"
#include "NumberUtil.h"
#include "ArrayUtil.h"
#include "StringUtil.h"

#define SIZE 30

struct ListNode {
    int val;
    ListNode *next;
};

int main() {
    //NumberUtil::Operation();
    // Date d1{12,2,2019};
    // Date d2{11,2,2019};
    // std::cout << d1-d2 << std::endl;
    // int arr[SIZE];
    // ArrayUtil::setRandomArray(arr, SIZE);
    // ArrayUtil::printArray(arr, SIZE);
    // auto mode = ArrayUtil::getMode(arr, SIZE);
    // std::cout << mode << std::endl;
    /*int arr[SIZE] = {65, 75, 15, 62, 12, 34, 55, 37, 67, 78};

    auto secMax = ArrayUtil::getSecondMax(arr, SIZE);
    std::cout << secMax << std::endl;*/
    std::string text{"Berke"};
    StringUtil::printText(text);
    StringUtil::printText("Berke");
    StringUtil::textInnerParenthesisTest();
    ListNode *head = nullptr;
    ListNode *current = nullptr;

    // Bağlı listeyi oluştur
    for (int i = 0; i < 3; ++i) {
        ListNode *newNode = new ListNode;
        newNode->val = (i + 1) * 10; // 10, 20, 30 değerlerini atayalım
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }

    // Bağlı listeyi yazdır
    current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }

    // Belleği temizle
    current = head;
    while (current != nullptr) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

class SolutionIsValid {
public:
    bool isValid(const std::string& s) {
        int countFirst = 0;
        int countSecond = 0;
        int countThird = 0;
        for (char ch : s) {
            switch (ch) {
                case '(':
                    countFirst++;
                break;
                case '[':
                    countSecond++;
                break;
                case '{':
                    countThird++;
                break;
                case ')':
                    countFirst--;
                break;
                case ']':
                    countSecond--;
                break;
                case '}':
                    countThird--;
            }
            if (countFirst < 0 || countSecond < 0 || countThird < 0) {
                return false;
            }
        }
        //std::cout << countFirst << " " << countSecond << " " << countThird << '\n';
        return countFirst == 0 && countSecond == 0 && countThird == 0;
    }
};