#include <iostream>
#include <string>
#include <tuple>

class Solution {
    std::tuple<int, int, int> extractDateParts(const std::string& date) {
        int year = std::stoi(date.substr(0, 4));   // First 4 characters
        int month = std::stoi(date.substr(5, 2));  // Next 2 characters after the hyphen
        int day = std::stoi(date.substr(8, 2));    // Last 2 characters

        return std::make_tuple(year, month, day);
    }

    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInMonth(int year, int month) {
        static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && isLeapYear(year)) {
            return 29;
        }
        return days_in_month[month - 1];
    }

    int daysFromStart(int year, int month, int day) {
        int days = 0;

        // Count full years from 1970 to the given year
        for (int y = 1970; y < year; ++y) {
            days += isLeapYear(y) ? 366 : 365;
        }

        // Count full months in the current year
        for (int m = 1; m < month; ++m) {
            days += daysInMonth(year, m);
        }

        // Add the days in the current month
        days += day;

        return days;
    }

public:
    int daysBetweenDates(std::string date1, std::string date2) {
        // Extract the year, month, and day for both dates
        int year1, month1, day1;
        std::tie(year1, month1, day1) = extractDateParts(date1);
        int year2, month2, day2;
        std::tie(year2, month2, day2) = extractDateParts(date2);

        // Convert both dates to the total number of days since 1970-01-01
        int days1 = daysFromStart(year1, month1, day1);
        int days2 = daysFromStart(year2, month2, day2);

        // Return the absolute difference between the two dates
        return std::abs(days1 - days2);
    }
};

int main() {
    Solution solution;
    std::string date1 = "2024-11-08";
    std::string date2 = "2023-11-08";

    int result = solution.daysBetweenDates(date1, date2);
    std::cout << "Days between dates: " << result << std::endl;

    return 0;
}