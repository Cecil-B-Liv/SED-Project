//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_MEMBER_H
#define SED_PROJECT_MEMBER_H

#include <utility>

#include "BasicSTDLIB.h"
#include "Rating.h"
#include "Booking.h"

class Member {
private:
    // showMemberScreen Info
    string fullName;
    string email;
    string homeAddress;
    string phoneNumber;

    // showMemberScreen value
    double skillRating;
    double supportRating;
    double hostRating;

    // showMemberScreen account
    string username;
    string password;
    string memberID;
    int creditPoints;
    bool availableStatus;
    vector<string *> skillInfoList;

    // System based member info
    vector<double *> avgRatingScore;
    string hostMemberID;
    string supporterMemberID;

public:
    explicit Member(
            string fullName = "", string email = "", string homeAddress = "",
            string phoneNumber = "", double ratingScore = 0.0,
            double supporterRating = 0.0, double hostRating = 0.0,
            string username = "", string password = "", string memberID = "", int creditPoints = 20,
            int available_status = 0, vector<string *> skillInfo = {},
            string hostMemberID = "", string supporterMemberID = "");

    // toString
    void showInfo() const;

    // accessor methods
    // getter
    string getUsername() const { return username; }

    string getPassword() const { return password; }

    string getFullName() const { return fullName; }

    string getEmail() const { return email; }

    string getHomeAddress() const { return homeAddress; }

    string getPhoneNumber() const { return phoneNumber; }

    double getRatingScore() const { return skillRating; }

    double getSupporterRating() const { return supportRating; }

    double getHostRating() const { return hostRating; }

    string getMemberID() const { return memberID; }

    int getCreditPoints() const { return creditPoints; }

    bool getMemberAvailableStatus() const { return availableStatus; }

    vector<string *> getSkillInfo() { return skillInfoList; }

    vector<double *> getRatingList() { return avgRatingScore; }

    string getHostMember() const { return hostMemberID; }

    string getSupporterMember() const { return supporterMemberID; }

    // setter
    void setFullName(const string &fullNameVal) {
        this->fullName = fullNameVal;
    }

    void setEmail(const string &emailVal) { this->email = emailVal; }

    void setHomeAddress(const string &homeAddressVal) {
        this->homeAddress = homeAddressVal;
    }

    void setPhoneNumber(const string &phoneNumberVal) {
        this->phoneNumber = phoneNumberVal;
    }

    void setRatingScore(const double &ratingScoreVal) {
        this->skillRating = ratingScoreVal;
    }

    void setSupporterRating(const double &supporterRatingVal) {
        this->supportRating = supporterRatingVal;
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

    void setCreditPoints(const int &creditPointsVal) {
        this->creditPoints = creditPointsVal;
    }

    void setAvailableStatus(const bool &availableStatusVal) {
        this->availableStatus = availableStatusVal;
    }

    void setSkillInfo(vector<string *> skillInfoListVal) {
        this->skillInfoList = skillInfoListVal;
    }

    void setHostMember(string newHost) { this->hostMemberID = newHost; }

    void setSupporterMember(string newSupporter) {
        this->supporterMemberID = newSupporter;
    }

    void addSkill(string *newSkill) { this->skillInfoList.push_back(newSkill); }

    void addRating(double *newRating) { this->avgRatingScore.push_back(newRating); }

};

#endif  // SED_PROJECT_MEMBER_H
