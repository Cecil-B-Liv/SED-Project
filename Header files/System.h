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

    // Data for the system
    vector<Member> MemberList;
    vector<Rating> userRating;
    vector<Rating> motorRating;
    vector<Rating> RatingList;
    vector<Request> RequestList;

public:
    static System &getInstance();

    vector<Member> &getMemberList() { return this->MemberList; }

    vector<Rating> &getRatingList() { return this->RatingList; }

    vector<Request> &getRequestList() { return this->RequestList; }

    void memberReader();

    void memberWriter();

    void RatingReader();

    void RatingWriter();

    void RequestReader();

    void RequestWriter();

    string loginCheck(const string &, const string &);

    void getMemberInformation(const string &);

    int memberInputCheck(const string &);

    void addRating(string ratingID, string memberID, string hostID,
                   double skillRating, double supporterRating,
                   double hostRating, string comments);

    void removeRating(string ratingID);
};

#endif  // SED_PROJECT_SYSTEM_H
