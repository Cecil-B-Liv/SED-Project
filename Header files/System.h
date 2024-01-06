//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_SYSTEM_H
#define SED_PROJECT_SYSTEM_H

#include "BasicSTDLIB.h"
#include "Member.h"

// Data path
const string USER_PATH = "../Database/MemberData.csv";
const string TRANSACTION_PATH = "../Database/TransactionData.csv";
const string REQUEST_PATH = "../Database/RequestData.csv";
const string RATING_PATH = "../Database/RatingData.csv";

class System {
private:
    // private constructor
    System();

    // user name and password for admin
    string const adminUsername = "admin";
    string const adminPassword = "admin";

    // Data for the systemInstance
    vector<Member> memberList;
    vector<Rating> userRating;
    vector<Rating *> ratingList;
    vector<Request> requestList;

public:
    static System &getInstance();

    vector<Member> &getMemberList() { return this->memberList; }

    vector<Rating *> &getRatingList() { return this->ratingList; }

    vector<Request> &getRequestList() { return this->requestList; }

    // File Reader
    void memberFileReader();

    void ratingFileReader();

    void requestFileReader();

    void hostFileReader();

    void supporterFileReader();

    // File Writer
    void memberFileWriter(const Member &newMember);

    void ratingFileWriter();

    void requestFileWriter();

    // Check if valid information was input
    string loginCheck(const string &, const string &);

    int checkIfInputIsInteger(const string &input);

    // Get information of showMemberScreen
    void getMemberInformation(const string &);

    string generateMemberID();

    void addRating(string ratingID, string memberID, string hostID,
                   double skillRating, double supporterRating,
                   double hostRating, string comments);

    void removeRating(const string &ratingID);

    void registerNewMember(const string &fullName = "", const string &email = "",
                           const string &homeAddress = "", int phoneNumber = 0, const string &username = "",
                           const string &password = "");
};

#endif  // SED_PROJECT_SYSTEM_H
