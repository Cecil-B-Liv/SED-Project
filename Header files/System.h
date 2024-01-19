//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_SYSTEM_H
#define SED_PROJECT_SYSTEM_H

#include "BasicSTDLIB.h"
#include "Member.h"

// Data path
const string MEMBER_PATH = "../Database/MemberData.csv";
const string BOOKING_PATH = "../Database/BookingData.csv";
const string RATING_PATH = "../Database/RatingData.csv";

class System {
private:
    // private constructor
    System();

    // Data for the systemInstance
    vector<Member> memberList;
    vector<Rating> ratingList;
    vector<Booking> bookingList;

public:


    void clearTerminal();


    static System &getInstance();

    vector<Member> &getMemberList() { return memberList; }

    vector<Rating> &getRatingList() { return ratingList; }

    vector<Booking> &getBookingList() { return bookingList; }

    // File Reader
    void memberFileReader();

    void ratingFileReader();

    void bookingFileReader();

    // File Writer
    void memberFileWriter();

    void ratingFileWriter();


    tm parseCSVTime(const std::string &timeStr);

    void bookingFileWriter();


    // check if there is a member with that ID
    int checkMemberExist(const string &);

    // Check if valid information was input
    string getIDWithUsernamePassword(const string &username,
                                     const string &password);

    // Get information of showMemberScreen
    void displayMemberInformation(const string &ID);

    // Admin function
    void resetPassword(const string &ID, const string &newPwd);

    // System function
    Member &getMemberObject(const string &ID);

    //    int changePasswordWithID(const string &, const string &);

    void registerNewMember(const string &fullName = "",
                           const string &email = "",
                           const string &homeAddress = "",
                           const string &phoneNumber = "",
                           const string &username = "",
                           const string &password = "");

    // Helper Function
    // check input is integer when choosing option
    int checkIfInputIsInteger(const string &input);

    // generate member ID when register
    string generateMemberID();

    string generateRatingID();

    string generateBookingID();

    void addNewSkill(int &, const string &);

    void removeSkill(int &, const string &);

    void addNewBooking(string hostMemberID, string supporterMemberID,
                       string status, double timeRenting, tm startTime);

    void addNewRequest();

    void requestToBookAvailableSupporter(const string &, const string &);

    bool topUpCredits(const string &memberID, int topUpAmount, const string &passwordInput);

    double calculateSupporterRating(const string &supporterID, int &);

    void addNewRating(string &memberID, string &hostID, double skillRating,
                      double supporterRating, double hostRating, string &comments);

    double calculateHostRating(const string &hostID, int &newRating);

    double calculateSupporterSkillRating(const string &supporterID, int &newRating);

    double calculateTotalRating(const string &ID);
};

#endif  // SED_PROJECT_SYSTEM_H
