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
    void setBookingID(std::string bookingID) { this->bookingID = bookingID; }
    void setMemberID(std::string MemberID) { this->memberID = memberID; }

    void setStartTime(Time startTime) { this->startTime = startTime; }

    void setEndTime(Time endTime) { this->endTime = endTime; }

    void setSkillRequired(std::vector<std::string> skillRequired) {
        this->skillRequired = skillRequired;
    }

    void setStatus(std::string status) { this->status = status; }

    // Getter methods
    std::string getBookingID() const { return bookingID; }

    Time getStartTime() const { return startTime; }

    Time getEndTime() const { return endTime; }

    std::vector<std::string> getSkillRequired() const { return skillRequired; }

    std::string getStatus() const { return status; }
};

#endif