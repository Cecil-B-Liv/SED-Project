#include "../Header files/INCLUDEHEADERS.h"


Time::Time(int date, int month, int year)
        : date(date), month(month), year(year) {}

void Time::showInfo() const {
    cout << "Date: " << date << "/" << month << "/" << year << endl;
}

// method
int Time::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : -1;
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
            int dayEnd = (year == endYear && month == endMonth) ? endDay : daysInMonth[month];

            if (month == 2 && isLeapYear(year) == 1) {
                dayEnd++;  // February has an extra day in a leap year
            }
            duration += dayEnd - dayStart + 1;
        }
    }
    return duration;
}

bool Time::compareTime(const Time &startDate, const Time &endDate) {
    int startDay = startDate.getDate();
    int startMonth = startDate.getMonth();
    int startYear = startDate.getYear();
    int endDay = endDate.getDate();
    int endMonth = endDate.getMonth();
    int endYear = endDate.getYear();

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

Time Time::stringToTime(string &dateString) {
    stringstream ss(dateString);
    string item;
    vector<string> tokens;

    // split to get the date
    while (getline(ss, item, '/')) {
        tokens.push_back(item);
    }

    // check
    // the date is valid
    if (tokens.size() != 3) {
        cout << tokens.size() << endl;
    }

    // set the date
    int day = stoi(tokens[0]);
    int month = stoi(tokens[1]);
    int year = stoi(tokens[2]);

    return Time(day, month, year);
}




// Might need later

// ostream &operator<<(ostream &cout, const Time &date) {
//     cout << date.date << '/' << date.month << '/' << date.year;
//     return cout;
// }

//     Time

// Time Time::getCurrentDate() {
//     auto now = chrono::system_clock::now();
//     time_t currentTime = chrono::system_clock::to_time_t(now);

//     // Convert currentTime to a Time object
//     struct tm *timeInfo = localtime(&currentTime);
//     Time currentDate;
//     currentDate.setDate(timeInfo->tm_mday);
//     currentDate.setMonth(timeInfo->tm_mon + 1);     // Month is zero-based
//     currentDate.setYear(timeInfo->tm_year + 1900);  // Years since 1900

//     return currentDate;
// }