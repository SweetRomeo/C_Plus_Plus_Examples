//
// Created by berke on 2/1/2025.
//

#ifndef DATEUTIL_H
#define DATEUTIL_H
#include <vector>
#include <string>

class Date {
    int day, month, year;
    const std::vector<int> dayOfMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const std::vector<std::string> monthNames = { "", "January", "February", "March", "April", "May",
        "June", "July", "August", "September", "October", "November", "December"};
public:
    Date() = default;
    Date(const int& day, const int& month, const int& year);
    void setDate(int day, int month, int year);

    Date &operator=(const Date &other);

    int operator-(const Date &other) const;
    void setDay(int day);
    [[nodiscard]] int getDay() const;
    void setMonth(int month);
    [[nodiscard]] int getMonth() const;
    void setYear(int year);
    int getYear() const;
    void displayDate()const;
    static bool isLeapYear(int year) ;
    [[nodiscard]] bool isValidDate() const;

    int getDayOfYear() const;

    int getDayOfWeek() const;

    void printDayOfWeek() const;

    int getDayOfYear();
    int getDayOfWeek();
    void printDayOfWeek();
    int getTotalDaysFromDate(const Date &date) const;
};
#endif //DATEUTIL_H
