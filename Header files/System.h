//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_SYSTEM_H
#define SED_PROJECT_SYSTEM_H

#include "BasicSTDLIB.h"
#include "Member.h"

// Data path
const string MEMBER_PATH = "./Database/MemberData.csv";
const string REQUEST_PATH = "./Database/RequestData.csv";
const string RATING_PATH = "./Database/RatingData.csv";

class System {
   private:
    // private constructor
    System();

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

    // File Writer
    void memberFileWriter(const Member &newMember);
    void ratingFileWriter();
    void requestFileWriter();

    // check if there is a member with that ID
    int checkMemberExist(const string &);
    // Check if valid information was input
    string getID_with_username_password(const string &, const string &);
    // Get information of showMemberScreen
    void getMemberInformation(const string &);

    // Admin function
    void resetPassword(const string &, const string &);

    // System function
    void addRating(string ratingID, string memberID, string hostID,
                   double skillRating, double supporterRating,
                   double hostRating, string comments);

    void removeRating(const string &ratingID);

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
};

#endif  // SED_PROJECT_SYSTEM_H
