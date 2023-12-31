#include "../Header files/INCLUDEHEADERS.h"

Time::Time() {}
Time::Time(int date = 0, int month = 0, int year = 0)
    : date(date), month(month), year(year){};

void Time::showInfo() {
    std::cout << "Date: " << date << "/" << month << "/" << year << std::endl;
}

// method
bool Time::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

string Time::formatConverter() {
    return "Dumb";
}

int Time::getDuration(const Time &startDate, const Time &endDate) {
    int startDay = startDate.getDate();
    int startMonth = startDate.getMonth();
    int startYear = startDate.getYear();
    int endDay = endDate.getDate();
    int endMonth = endDate.getMonth();
    int endYear = endDate.getYear();

    // Get duration
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Calculate the number of days in each year from startYear to endYear
    int duration = 0;

    for (int year = startYear; year <= endYear; year++) {
        int monthStart = (year == startYear) ? startMonth : 1;
        int monthEnd = (year == endYear) ? endMonth : 12;

        for (int month = monthStart; month <= monthEnd; month++) {
            int dayStart = (year == startYear && month == startMonth) ? startDay : 1;
            int dayEnd = (year == endYear && month == endMonth)? endDay: daysInMonth[month];

            if (month == 2 && isLeapYear(year)) {
                dayEnd++;  // February has an extra day in a leap year
            }
            duration += dayEnd - dayStart + 1;
        }
    }
    return duration;
}

bool Time::compareTime(const Time &startd, const Time &endd) {
    int startDay = startd.getDate();
    int startMonth = startd.getMonth();
    int startYear = startd.getYear();
    int endDay = endd.getDate();
    int endMonth = endd.getMonth();
    int endYear = endd.getYear();

    if (startYear < endYear) {
        return true;
    } else if (startYear == endYear) {
        if (startMonth < endMonth) {
            return true;
        } else if (startMonth == endMonth) {
            if (startDay <= endDay) {
                return true;
            }
        }
    }

    return false;
}

// Might need later

// std::ostream &operator<<(std::ostream &cout, const Time &date) {
//     cout << date.date << '/' << date.month << '/' << date.year;
//     return cout;
// }

//     Time
//     Time::stringToTime(string &dateString) {
//     std::stringstream ss(dateString);
//     string item;

//     vector<string> tokens;

//     // split to get the date
//     while (getline(ss, item, '/')) {
//         tokens.push_back(item);
//     }

//     // check
//     // the date is valid
//     if (tokens.size() != 3) {
//         cout << tokens.size() << endl;
//     }

//     // set the date
//     int day = stoi(tokens[0]);
//     int month = stoi(tokens[1]);
//     int year = stoi(tokens[2]);

//     return Time(day, month, year);
// }

// Time Time::getCurrentDate() {
//     auto now = std::chrono::system_clock::now();
//     std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

//     // Convert currentTime to a Time object
//     struct tm *timeInfo = std::localtime(&currentTime);
//     Time currentDate;
//     currentDate.setDate(timeInfo->tm_mday);
//     currentDate.setMonth(timeInfo->tm_mon + 1);     // Month is zero-based
//     currentDate.setYear(timeInfo->tm_year + 1900);  // Years since 1900

//     return currentDate;
// }