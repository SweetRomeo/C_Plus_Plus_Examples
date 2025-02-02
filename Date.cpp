//
// Created by berke on 2/1/2025.
//
#include "Date.h"

#include <iostream>

Date::Date(const int &day, const int &month, const int &year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::setDate(const int day,const int month,const int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

Date& Date::operator=(const Date &other) {
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
    return *this;
}

bool Date::isLeapYear(const int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

void Date::setDay(int day) {
    this->day = day;
}

int Date::getDay() const {
    return this->day;
}

void Date::setMonth(int month) {
    this->month = month;
}

int Date::getMonth() const {
    return this->month;
}

void Date::setYear(int year) {
    this->year = year;
}

int Date::getYear() const {
    return this->year;
}

void Date::displayDate() const {
    std::cout << this->day << "." << this->month << "." << this->year << '\n';
}

bool Date::isValidDate() const {
    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 0 || year > 9999) {
        return false;
    }
    int days = isLeapYear(year) && month == 2 ? 29 : dayOfMonth[month];
    return day <= days;
}


int Date::getDayOfYear() {
    if (!isValidDate()) {
        throw std::invalid_argument("Invalid Date");
    }
    int daysOfMonths = this->day;
    switch (month - 1) {
        case 11:
            daysOfMonths += dayOfMonth[11];
        case 10:
            daysOfMonths += dayOfMonth[10];
        case 9:
            daysOfMonths += dayOfMonth[9];
        case 8:
            daysOfMonths += dayOfMonth[8];
        case 7:
            daysOfMonths += dayOfMonth[7];
        case 6:
            daysOfMonths += dayOfMonth[6];
        case 5:
            daysOfMonths += dayOfMonth[5];
        case 4:
            daysOfMonths += dayOfMonth[4];
        case 3:
            daysOfMonths += dayOfMonth[3];
        case 2:
            daysOfMonths += isLeapYear(year) ? 29 : dayOfMonth[2];
        case 1:
            daysOfMonths += dayOfMonth[1];
    }
    return daysOfMonths;
}

int Date::getDayOfWeek() {
    if (this->year < 1900 || !isValidDate()) {
        throw std::invalid_argument("Invalid Date");
    }
    int totalDays = getDayOfYear();
    for (int year = 1900; year <= this->year; year++) {
        totalDays += isLeapYear(year) ? 366 : 365;
    }
    return totalDays % 7;
}

void Date::printDayOfWeek() {
    displayDate();
    switch (getDayOfWeek()) {
        case 0:
            std::cout << "Saturday" << '\n';
            break;
        case 1:
            std::cout << "Sunday" << '\n';
            break;
        case 2:
            std::cout << "Monday" << '\n';
            break;
        case 3:
            std::cout << "Tuesday" << '\n';
            break;
        case 4:
            std::cout << "Wednesday" << '\n';
            break;
        case 5:
            std::cout << "Thursday" << '\n';
            break;
        case 6:
            std::cout << "Friday" << '\n';
    }
}

