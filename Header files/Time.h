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
    Time();
    Time(int Time, int month, int year);

    // Getter
    int getDate() const { return date; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDate(const int day) { this->date = date; }
    void setMonth(const int month) { this->month = month; }
    void setYear(const int year) { this->year = year; }

    // method
    void showInfo();

    static string formatConverter();
    static int getDuration(const Time &startd, const Time &endd);
    static bool compareTime(const Time &startd, const Time &endd);
    static bool isLeapYear(int year);
};

// static Time getCurrentTime();
// convert string to Time
// static Time stringToTime(string &TimeString);
// friend std::ostream &operator<<(std::ostream &cout, const Time &Time);

#endif