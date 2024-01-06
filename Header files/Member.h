//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_MEMBER_H
#define SED_PROJECT_MEMBER_H

#include "BasicSTDLIB.h"

class Member {
private:
    // showMemberScreen Info
    string fullName;
    string email;
    string homeAddress;
    int phoneNumber;

    // showMemberScreen value
    double ratingScore;
    double supporterRating;
    double hostRating;

    // showMemberScreen account
    string username;
    string password;
    string memberID;
    vector<string> skillInfoList;

public:
    // System based showMemberScreen info
    // static vector<showMemberScreen> hostList;
    // static vector<showMemberScreen> supporterList;
    // static vector<Rating> ratingList;
    // static vector<Request> requestList;

    explicit Member(string fullName = "", string email = "",
                    string homeAddress = "", int phoneNumber = 0,
                    double ratingScore = 0.0, double supporterRating = 0.0,
                    double hostRating = 0.0, string username = "",
                    string password = "", string memberID = "",
                    vector<string> skillInfoList = {});

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

    // vector<showMemberScreen*> getHostList() const;

    // vector<showMemberScreen*> getSupporterList() const;

    // setter
    void setFullName(const string &fullNameVal) {
        this->fullName = fullNameVal;
    }

    void setEmail(const string &emailVal) { this->email = emailVal; }

    void setHomeAddress(const string &homeAddressVal) {
        this->homeAddress = homeAddressVal;
    }

    void setPhoneNumber(int phoneNumberVal) {
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

    // void setRatingList(vector<Rating> ratingList) { ratingList = ratingList;
    // }

    // void setRequestList(vector<Request> requestList) {
    //     requestList = requestList;
    // }

    // void setHostList(vector<showMemberScreen> hostListVal) { hostList = hostListVal; }

    // void setSupporterList(vector<showMemberScreen> supporterListVal) {
    //     supporterList = supporterListVal;
    // }
};

#endif  // SED_PROJECT_MEMBER_H
