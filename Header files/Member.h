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
    int phoneNumber;
    int position;

    // Member value
    double ratingScore;
    double supporterRating;
    double hostRating;

    // Member account
    string username;
    string password;
    //  string memberID;

    // System based member info
    vector<string> skillInfo;
    vector<Transaction> transactionList;
    vector<Member> hostList;
    vector<Member> supporterList;

   public:
    explicit Member(string = "", string = "", string = "", int = 0, int = 0,
                    double = 0.0, double = 0.0, double = 0.0,
                    vector<string> = {}, string = "", string = "");
    // vector<Rating> ratingList;
    // vector<Request> requestList;

   public:
    // constructor
    Member(string, string, string, int, int, double, double, double,
           vector<string>);
    // toString
    void showInfo();

    // accessor methods
    // getter
    string getFullName() const { return fullName; }

    string getEmail() const { return email; }

    string getHomeAddress() const { return homeAddress; }

    int getPhoneNumber() const { return phoneNumber; }

    int getPosition() const { return position; }

    double getRatingScore() const { return ratingScore; }

    double getSupporterRating() const { return supporterRating; }

    double getHostRating() const { return hostRating; }

    string getUsername() const { return username; }

    string getPassword() const { return password; }

    // string getMemberID() const { return memberID; }

    vector<string> getSkillInfo() const { return skillInfo; }

    vector<Transaction> getTransactionList() const { return transactionList; }

    // vector<Rating> getRatingList() const { return ratingList; }

    // vector<Request> getRequestList() const { return requestList; }

    vector<Member> getHostList() const { return hostList; }

    vector<Member> getSupporterList() const { return supporterList; }
    // setter
    void setFullName(string fullName) { this->fullName = fullName; }

    void setEmail(string email) { this->email = email; }

    void setHomeAddress(string homeAddress) { this->homeAddress = homeAddress; }

    void setPhoneNumber(int phoneNumber) { this->phoneNumber = phoneNumber; }

    void setPosition(int position) { this->position = position; }

    void setRatingScore(double ratingScore) { this->ratingScore = ratingScore; }

    void setSupporterRating(double supporterRating) {
        this->supporterRating = supporterRating;
    }

    void setHostRating(double hostRating) { this->hostRating = hostRating; }

    void setUsername(string username) { this->username = username; }

    void setPassword(string password) { this->password = password; }

    // void setMemberID(string memberID) { this->memberID = memberID; }

    void setSkillInfo(vector<string> skillInfo) { this->skillInfo = skillInfo; }

    void setTransactionList(vector<Transaction> transactionList) {
        this->transactionList = transactionList;
    }

    // void setRatingList(vector<Rating> ratingList) {
    //     this->ratingList = ratingList;
    // }

    // void setRequestList(vector<Request> requestList) {
    //     this->requestList = requestList;
    // }

    void setHostList(vector<Member> hostList) { this->hostList = hostList; }

    void setSupporterList(vector<Member> supporterList) {
        this->supporterList = supporterList;
    }
};

#endif  // SED_PROJECT_MEMBER_H
