//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_MEMBER_H
#define SED_PROJECT_MEMBER_H

#include <utility>
#include "Rating.h"
#include "Request.h"
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
    vector<string *> skillInfoList;

    // // System based member info
    vector<Member *> hostList;
    vector<Member *> supporterList;
    vector<Rating *> ratingList;
    vector<Request *> requestList;

public:
    explicit Member(string fullName = "", string email = "",
                    string homeAddress = "", int phoneNumber = 0,
                    double ratingScore = 0.0, double supporterRating = 0.0,
                    double hostRating = 0.0, string username = "",
                    string password = "", string memberID = "",
                    vector<string *> skillInfoList = {});

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

    vector<string *> getSkillInfo() { return skillInfoList; }

    // vector<Rating *> getRatingList() const;

    // vector<Request *> getRequestList() const;

    // vector<Member *> getHostList() const;

    // vector<Member *> getSupporterList() const;

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

    void setSkillInfo(vector<string *> skillInfoListVal) {
        this->skillInfoList = skillInfoListVal;
    }

    void addSkill(string *newSkill) {
        this->skillInfoList.push_back(newSkill);
    }

    // // dont need lol

    void addRating(Rating *newRating) {
        this->ratingList.push_back(newRating);
    }

    void addRequest(Request *newRequest) {
        this->requestList.push_back(newRequest);
    }

    void addHost(Member *newHost) {
        this->hostList.push_back(newHost);
    }

    void addSupporter(Member *newSupporter) {
        this->supporterList.push_back(newSupporter);
    }
};

#endif  // SED_PROJECT_MEMBER_H
