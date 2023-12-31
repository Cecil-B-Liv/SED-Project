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

    // Member value
    double ratingScore{};
    double supporterRating{};
    double hostRating{};

    // Member account
    string username;
    string password;
    string memberID;
    vector<string> skillInfoList;

   public:
    // System based member info

    vector<Transaction> transactionList;
    // static vector<Member> hostList;
    // static vector<Member> supporterList;
    // static vector<Rating> RatingList;
    // static vector<Request> RequestList;

    // constructor
    explicit Member(string = "", string = "", string = "", int = 0,
                    double = 0.0, double = 0.0, double = 0.0, string = "",
                    string = "", string = "", vector<string> = {});

    // toString
    void showInfo() const;

    // accessor methods
    // getter
    string getUsername() const { return username; }

    string getPassword() const { return password; }

    string getFullName() const { return fullName; }

    string getEmail() const { return email; }

    string getHomeAddress() const { return homeAddress; }

    int getPhoneNumber() const { return phoneNumber; }

    double getRatingScore() const { return ratingScore; }

    double getSupporterRating() const { return supporterRating; }

    double getHostRating() const { return hostRating; }

    string getMemberID() const { return memberID; }

    vector<string> getSkillInfo() { return skillInfoList; }

    // vector<Transaction*> getTransactionList() const;

    // vector<Rating*> getRatingList() const;

    // vector<Request*> getRequestList() const;

    // vector<Member*> getHostList() const;

    // vector<Member*> getSupporterList() const;

    // setter
    void setFullName(const string &fullNameVal) {
        this->fullName = fullNameVal;
    }

    void setEmail(const string &emailVal) { this->email = emailVal; }

    void setHomeAddress(const string &homeAddressVal) {
        this->homeAddress = homeAddressVal;
    }

    void setPhoneNumber(const int &phoneNumberVal) {
        this->phoneNumber = phoneNumberVal;
    }

    void setRatingScore(const double &ratingScoreVal) {
        this->ratingScore = ratingScoreVal;
    }

    void setSupporterRating(const double &supporterRatingVal) {
        this->supporterRating = supporterRatingVal;
    }

    void setHostRating(const double &hostRatingVal) {
        this->hostRating = hostRatingVal;
    }

    void setPassword(const string &passwordVal) {
        this->password = passwordVal;
    }

    void setUsername(const string &usernameVal) {
        this->username = usernameVal;
    }

    void setMemberID(const string &memberIDVal) {
        this->memberID = memberIDVal;
    }

    void setSkillInfo(const vector<string> skillInfoListVal) {
        skillInfoList = skillInfoListVal;
    }
    // dont need lol

    // void setTransactionList(vector<Transaction> transactionListVal) {
    //     transactionList = transactionListVal;
    // }

    // void setRatingList(vector<Rating> ratingList) { RatingList = ratingList;
    // }

    // void setRequestList(vector<Request> requestList) {
    //     RequestList = requestList;
    // }

    // void setHostList(vector<Member> hostListVal) { hostList = hostListVal; }

    // void setSupporterList(vector<Member> supporterListVal) {
    //     supporterList = supporterListVal;
    // }
};

#endif  // SED_PROJECT_MEMBER_H
