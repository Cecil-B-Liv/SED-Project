#ifndef SED_PROJECT_REQUEST_H
#define SED_PROJECT_REQUEST_H

#include "BasicSTDLIB.h"
#include "Time.h"

class Request {
   private:
    string bookingID;
    string hostMemberID;
    string supporterMemberID;
    string status;

    double timeRenting;
    tm startTime;
    tm creationTime;

    // vector<string *> skillRequired;
   public:
    // constructor code
    Request();

    // function code
    void showInfo();

    // Setter methods
    void setBookingID(string bookingIDVal) { this->bookingID = bookingIDVal; }
    void setHostMemberID(string hostMemberIDVal) {
        this->hostMemberID = hostMemberIDVal;
    }
    void setSupporterMemberID(string supporterMemberIDVal) {
        this->supporterMemberID = supporterMemberIDVal;
    }
    // PENDING, COMPLETED, DENIED
    void setStatus(string statusVal) { this->status = statusVal; }
    void setCreationTime(const std::tm &time) { this->creationTime = time; }

    // Getter methods
    string getBookingID() const { return bookingID; }
    string getHostMemberID() const { return hostMemberID; }
    string getSupporterMemberID() const { return supporterMemberID; }
    string getStatus() const { return status; }

    string getFormattedCreationTime() const {
        char buffer[20];  // Buffer to hold the formatted time
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &creationTime);
        return {buffer};
    }


};

#endif