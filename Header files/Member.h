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

    // System based member info
    vector<string> skillInfoList;
    vector<Transaction> transactionList;
    vector<Member> hostList;
    vector<Member> supporterList;
    // vector<Rating> ratingList;
    // vector<Request> requestList;

public:
    explicit Member(string = "", string = "", string = "",
                    int  = 0, int  = 0, double  = 0.0,
                    double = 0.0, double  = 0.0, vector<string> = {},
                    string = "", string = "", string = "");

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

    vector<string> getSkillInfo() { return skillInfoList; }

    vector<Transaction> getTransactionList() { return transactionList; }

    // vector<Rating> getRatingList() const { return ratingList; }

    // vector<Request> getRequestList() const { return requestList; }

    vector<Member> getHostList() { return hostList; }

    vector<Member> getSupporterList() { return supporterList; }

    // setter
    void setFullName(string fullNameVal) { this->fullName = fullNameVal; }

    void setEmail(string emailVal) { this->email = emailVal; }

    void setHomeAddress(string homeAddressVal) { this->homeAddress = homeAddressVal; }

    void setPhoneNumber(int phoneNumberVal) { this->phoneNumber = phoneNumberVal; }

    void setPosition(int positionVal) { this->position = positionVal; }

    void setRatingScore(double ratingScoreVal) { this->ratingScore = ratingScoreVal; }

    void setSupporterRating(double supporterRatingVal) { this->supporterRating = supporterRatingVal; }

    void setHostRating(double hostRatingVal) { this->hostRating = hostRatingVal; }

    void setPassword(string passwordVal) { this->password = passwordVal; }

    void setUsername(string usernameVal) { this->username = usernameVal; }

    void setMemberID(string memberIDVal) { this->memberID = memberIDVal; }

    void setSkillInfo(vector<string> skillInfoListVal) { this->skillInfoList = skillInfoListVal; }

    void setTransactionList(vector<Transaction> transactionListVal) { this->transactionList = transactionListVal; }

    // void setRatingList(vector<Rating> ratingList) {
    //     this->ratingList = ratingList;
    // }

    // void setRequestList(vector<Request> requestList) {
    //     this->requestList = requestList;
    // }

    void setHostList(vector<Member> hostListVal) { this->hostList = hostListVal; }

    void setSupporterList(vector<Member> supporterListVal) { this->supporterList = supporterListVal; }
};

#endif  // SED_PROJECT_MEMBER_H
