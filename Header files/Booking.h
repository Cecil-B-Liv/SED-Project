#ifndef SED_PROJECT_BOOKING_H
#define SED_PROJECT_BOOKING_H

#include "BasicSTDLIB.h"




class Booking {
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
    Booking();

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
    void setStartTime(const std::tm &time) { this->startTime = time; }
    void setTimeRenting(double timeRenting) { this->timeRenting = timeRenting; }

    // Getter methods
    double getTimeRenting() const { return timeRenting; }
    string getBookingID() const { return bookingID; }

    string getHostMemberID() const { return hostMemberID; }

    string getSupporterMemberID() const { return supporterMemberID; }

    string getStatus() const { return status; }

    string getFormattedCreationTime() const {
        char buffer[20];  // Buffer to hold the formatted time
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &creationTime);
        return {buffer};
    }

    string getFormattedStartRentingTime() const{
        char buffer[20];  // Buffer to hold the formatted time
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &startTime);
        return {buffer};
    }
};

#endif