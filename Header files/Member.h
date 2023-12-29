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

//   public:
//    // constructor
//    Member(string, string, string, int, int, double, double, double,
//           vector<string>);
    // toString
    void showInfo();

    // accessor methods
    // getter
    string getFullName();

    string getEmail();

    string getHomeAddress();

    int getPhoneNumber();

    int getPosition();

    double getRatingScore();

    double getSupporterRating();

    double getHostRating();

    string getUsername();

    string getPassword();
    // string getMemberID() const { return memberID; }

    vector<string> getSkillInfo();

    vector<Transaction> getTransactionList();

    // vector<Rating> getRatingList() const { return ratingList; }

    // vector<Request> getRequestList() const { return requestList; }

    vector<Member> getHostList();

    vector<Member> getSupporterList();

    // setter
    void setFullName(string fullName);

    void setEmail(string email);

    void setHomeAddress(string homeAddress);

    void setPhoneNumber(int phoneNumber);

    void setPosition(int position);

    void setRatingScore(double ratingScore);

    void setSupporterRating(double supporterRating);

    void setHostRating(double hostRating);

    void setUsername(string username);

    void setPassword(string password);
    // void setMemberID(string memberID) { this->memberID = memberID; }

    void setSkillInfo(vector<string> skillInfo);

    void setTransactionList(vector<Transaction> transactionList);

    // void setRatingList(vector<Rating> ratingList) {
    //     this->ratingList = ratingList;
    // }

    // void setRequestList(vector<Request> requestList) {
    //     this->requestList = requestList;
    // }

    void setHostList(vector<Member> hostList);

    void setSupporterList(vector<Member> supporterList);
};

#endif  // SED_PROJECT_MEMBER_H
