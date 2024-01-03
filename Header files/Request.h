#ifndef SED_PROJECT_REQUEST_H
#define SED_PROJECT_REQUEST_H

#include "BasicSTDLIB.h"
#include "Time.h"

class Request {
private:
    string bookingID;
    string memberID;
    Time startTime;
    Time endTime;
    vector<string> skillRequired;
    string status;

public:
    // constructor code
    Request();

    // function code
    bool answerRequest();

    void showInfo();

    // Setter methods
    void setBookingID(string bookingIDVal) { this->bookingID = bookingIDVal; }

    void setMemberID(string memberIDVal) { this->memberID = memberIDVal; }

    void setStartTime(Time startTimeVal) { this->startTime = startTimeVal; }

    void setEndTime(Time endTimeVal) { this->endTime = endTimeVal; }

    void setSkillRequired(vector<string> skillRequiredVal) {
        this->skillRequired = skillRequiredVal;
    }

    void setStatus(string statusVal) { this->status = statusVal; }

    // Getter methods
    string getBookingID() const { return bookingID; }

    Time getStartTime() const { return startTime; }

    Time getEndTime() const { return endTime; }

    vector<string> getSkillRequired() const { return skillRequired; }

    string getStatus() const { return status; }
};

#endif