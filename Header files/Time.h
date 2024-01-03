#ifndef SED_PROJECT_TIME_H
#define SED_PROJECT_TIME_H

#include "BasicSTDLIB.h"

class Time {
private:
    int date;
    int month;
    int year;

public:
    // constructor
    explicit Time(int Time = 0, int month = 0, int year = 0);


    // Getter
    int getDate() const { return date; }

    int getMonth() const { return month; }

    int getYear() const { return year; }

    void setDate(const int dateVal) { this->date = dateVal; }

    void setMonth(const int monthVal) { this->month = monthVal; }

    void setYear(const int yearVal) { this->year = yearVal; }

    // method
    void showInfo() const;

    static string formatConverter();

    static int getDuration(const Time &startDate, const Time &endDate);

    static bool compareTime(const Time &startDate, const Time &endDate);

    static int isLeapYear(int year);

    static Time stringToTime(string &TimeString);
};

// static Time getCurrentTime();
// convert string to Time
// friend std::ostream &operator<<(std::ostream &cout, const Time &Time);

#endif