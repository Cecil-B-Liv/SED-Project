#ifndef SED_PROJECT_REQUEST_H
#define SED_PROJECT_REQUEST_H

#include "BasicSTDLIB.h"
#include "Time.h"

class Request {
private:
    string bookingID;
    string memberID;
    vector<string *> skillRequired;
    tm creationTime;
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

    void setSkillRequired(vector<string *> skillRequiredVal) {
        this->skillRequired = skillRequiredVal;
    }

    void setStatus(string statusVal) { this->status = statusVal; }

    void setCreationTime(const std::tm &time) {
        this->creationTime = time;
    }

    // Getter methods
    string getBookingID() const { return bookingID; }

    vector<string *> getSkillRequired() const { return skillRequired; }

    string getFormattedCreationTime() const {
        char buffer[20];  // Buffer to hold the formatted time
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &creationTime);
        return {buffer};
    }

    string getStatus() const { return status; }
};

#endif