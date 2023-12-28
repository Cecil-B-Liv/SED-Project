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
    vector<Transaction> transaction;
    vector<Member> hostList;
    vector<Member> supporterList;

public:
    explicit Member(string= "", string= "", string= "", int= 0, int= 0, double= 0.0, double= 0.0, double= 0.0,
                    vector<string> = {}, string= "", string= "");
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
    string Member::getFullName() const { return fullName; }

    string Member::getEmail() const { return email; }

    string Member::getHomeAddress() const { return homeAddress; }

    int Member::getPhoneNumber() const { return phoneNumber; }

    int Member::getPosition() const { return position; }

    double Member::getRatingScore() const { return ratingScore; }

    double Member::getSupporterRating() const { return supporterRating; }

    double Member::getHostRating() const { return hostRating; }

     string Member::getUsername() const { return username; }

    string Member::getPassword() const { return password; }

    // string Member::getMemberID() const { return memberID; }

    vector<string> Member::getSkillInfo() const { return skillInfo; }

    vector<Transaction> Member::getTransactionList() const {
        return transactionList;
    }

    // vector<Rating> Member::getRatingList() const { return ratingList; }

    // vector<Request> Member::getRequestList() const { return requestList; }

    vector<Member> Member::getHostList() const { return hostList; }

    vector<Member> Member::getSupporterList() const { return supporterList; }
    // setter
    void Member::setFullName(string fullName) { this->fullName = fullName; }

    void Member::setEmail(string email) { this->email = email; }

    void Member::setHomeAddress(string homeAddress) {
        this->homeAddress = homeAddress;
    }

    void Member::setPhoneNumber(int phoneNumber) {
        this->phoneNumber = phoneNumber;
    }

    void Member::setPosition(int position) { this->position = position; }

    void Member::setRatingScore(double ratingScore) {
        this->ratingScore = ratingScore;
    }

    void Member::setSupporterRating(double supporterRating) {
        this->supporterRating = supporterRating;
    }

    void Member::setHostRating(double hostRating) {
        this->hostRating = hostRating;
    }

    void Member::setUsername(string username) { this->username = username; }

    void Member::setPassword(string password) { this->password = password; }

    // void Member::setMemberID(string memberID) { this->memberID = memberID; }

    void Member::setSkillInfo(vector<string> skillInfo) {
        this->skillInfo = skillInfo;
    }

    void Member::setTransactionList(vector<Transaction> transactionList) {
        this->transactionList = transactionList;
    }

    // void Member::setRatingList(vector<Rating> ratingList) {
    //     this->ratingList = ratingList;
    // }

    // void Member::setRequestList(vector<Request> requestList) {
    //     this->requestList = requestList;
    // }

    void Member::setHostList(vector<Member> hostList) {
        this->hostList = hostList;
    }

    void Member::setSupporterList(vector<Member> supporterList) {
        this->supporterList = supporterList;
    }

};

#endif  // SED_PROJECT_MEMBER_H
