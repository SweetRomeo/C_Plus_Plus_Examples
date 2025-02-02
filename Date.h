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

    int operator-(const Date& date) const;
    void setDay(int day);
    int getDay() const;
    void setMonth(int month);
    int getMonth() const;
    void setYear(int year);
    int getYear() const;
    void displayDate()const;
    static bool isLeapYear(int year) ;
    bool isValidDate() const;

    int getDayOfYear();
    int getDayOfWeek();
    void printDayOfWeek();
};
#endif //DATEUTIL_H
