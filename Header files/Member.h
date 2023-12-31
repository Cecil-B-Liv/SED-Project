//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_MEMBER_H
#define SED_PROJECT_MEMBER_H

#include "BasicSTDLIB.h"
#include "Transaction.h"

class Member {
   private:
    // Member Info
    string fullName;
    string email;
    string homeAddress;
    int phoneNumber{};
    int position{};

    // Member value
    double ratingScore{};
    double supporterRating{};
    double hostRating{};

    // Member account
    string username;
    string password;
    string memberID;

   public:
    // System based member info
    static vector<string> skillInfoList;
    static vector<Transaction*> transactionList;
    static vector<Member*> hostList;
    static vector<Member*> supporterList;
    static vector<Rating*> RatingList;
    static vector<Request*> RequestList;

    // constructor
    explicit Member();

    // toString
    void showInfo() const;

    // accessor methods
    // getter

    string getUsername() { return username; }

    string getPassword() { return password; }

    string getFullName() { return fullName; }

    string getEmail() { return email; }

    string getHomeAddress() { return homeAddress; }

    int getPhoneNumber() const { return phoneNumber; }

    int getPosition() const { return position; }

    double getRatingScore() const { return ratingScore; }

    double getSupporterRating() const { return supporterRating; }

    double getHostRating() const { return hostRating; }

    string getMemberID() const { return memberID; }

    static vector<string> getSkillInfo() { return skillInfoList; }

    static vector<Transaction*> getTransactionList() { return transactionList; }

    static vector<Rating*> getRatingList() { return RatingList; }

    static vector<Request*> getRequestList() { return RequestList; }

    static vector<Member*> getHostList() { return hostList; }

    static vector<Member*> getSupporterList() { return supporterList; }

    // setter
    void setFullName(string fullNameVal) { this->fullName = fullNameVal; }

    void setEmail(string emailVal) { this->email = emailVal; }

    void setHomeAddress(string homeAddressVal) {
        this->homeAddress = homeAddressVal;
    }

    void setPhoneNumber(int phoneNumberVal) {
        this->phoneNumber = phoneNumberVal;
    }

    void setPosition(int positionVal) { this->position = positionVal; }

    void setRatingScore(double ratingScoreVal) {
        this->ratingScore = ratingScoreVal;
    }

    void setSupporterRating(double supporterRatingVal) {
        this->supporterRating = supporterRatingVal;
    }

    void setHostRating(double hostRatingVal) {
        this->hostRating = hostRatingVal;
    }

    void setPassword(string passwordVal) { this->password = passwordVal; }

    void setUsername(string usernameVal) { this->username = usernameVal; }

    void setMemberID(string memberIDVal) { this->memberID = memberIDVal; }

    static void setSkillInfo(vector<string> skillInfoListVal) {
        skillInfoList = skillInfoListVal;
    }

    static void setTransactionList(vector<Transaction*> transactionListVal) {
        transactionList = transactionListVal;
    }

    static void setRatingList(vector<Rating*> ratingList) {
        RatingList = ratingList;
    }

    static void setRequestList(vector<Request*> requestList) {
        RequestList = requestList;
    }

    static void setHostList(vector<Member*> hostListVal) {
        hostList = hostListVal;
    }

    static void setSupporterList(vector<Member*> supporterListVal) {
        supporterList = supporterListVal;
    }
};

#endif  // SED_PROJECT_MEMBER_H
