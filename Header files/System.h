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
    vector<Request> requestList;

public:
    static System &getInstance();

    vector<Member> getMemberList() { return memberList; }

    vector<Rating> getRatingList() { return ratingList; }

    vector<Request> &getRequestList() { return requestList; }

    // File Reader
    void memberFileReader();

    void ratingFileReader();

    void requestFileReader();

    // File Writer
    void memberFileWriter();

    void ratingFileWriter();

    void requestFileWriter();

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
    Member getMemberObject(const string &ID);

    //    int changePasswordWithID(const string &, const string &);

    void registerNewMember(const string &fullName = "",
                           const string &email = "",
                           const string &homeAddress = "", int phoneNumber = 0,
                           const string &username = "",
                           const string &password = "");

    void addSkill(const string &, const string &);

    // Helper Function
    // check input is integer when choosing option
    int checkIfInputIsInteger(const string &input);

    // generate member ID when register
    string generateMemberID();

    string generateRatingID();

    string generateRequestID();

    void addNewSkill(const string &, const string &);

    void addNewRating(string ratingID, string memberID, string hostID,
                      double skillRating, double supporterRating,
                      double hostRating, string comments);

    void addNewRequest();

    void requestToBookAvailableSupporter(const string &, const string &D);
};

#endif  // SED_PROJECT_SYSTEM_H
