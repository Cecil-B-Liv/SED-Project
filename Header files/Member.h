//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_MEMBER_H
#define SED_PROJECT_MEMBER_H

#include <utility>

#include "BasicSTDLIB.h"
#include "Booking.h"
#include "Rating.h"

class Member {
   private:
    // showMemberScreen Info
    string fullName;
    string email;
    string homeAddress;
    string phoneNumber;

    // showMemberScreen value
    double totalRating;
    double skillRating;
    double supportRating;
    double hostRating;

    // showMemberScreen account
    string username;
    string password;
    string memberID;

    double creditPoints;
    double consumingPoints;

    bool availableStatus;

    vector<string *> skillInfoList;
    vector<string *> blockList = {};

    // System based member info
    string hostMemberID;
    string supporterMemberID;

   public:
    explicit Member(string fullName = "", string email = "",
                    string homeAddress = "", string phoneNumber = "",
                    double ratingScore = 0.0, double supporterRating = 0.0,
                    double hostRating = 0.0, string username = "",
                    string password = "", string memberID = "",
                    double creditPoints = 20, double consumingPoints = 0.0,
                    double totalRating = 0.0, int available_status = 0,
                    vector<string *> skillInfo = {}, string hostMemberID = "",
                    string supporterMemberID = "");

    // toString
    void showInfo() const;
    void showFullInfo() const;

    // accessor methods
    // getter
    string getUsername() const { return username; }

    string getPassword() const { return password; }

    string getFullName() const { return fullName; }

    string getEmail() const { return email; }

    string getHomeAddress() const { return homeAddress; }

    string getPhoneNumber() const { return phoneNumber; }

    double getSkillRating() const { return skillRating; }

    double getSupporterRating() const { return supportRating; }

    double getHostRating() const { return hostRating; }

    string getMemberID() const { return memberID; }

    double getCreditPoints() const { return creditPoints; }

    bool getMemberAvailableStatus() const { return availableStatus; }

    vector<string *> getSkillInfo() { return skillInfoList; }

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

    void setSkillRating(const double &ratingScoreVal) {
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

    void setCreditPoints(const double &creditPointsVal) {
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

    double getConsumingPoints() const { return consumingPoints; }

    void setConsumingPoints(const double &consumingPointsVal) {
        this->consumingPoints = consumingPointsVal;
    }

    double getTotalRating() const { return totalRating; }

    void setTotalRating(const double totalRatingVal) {
        this->totalRating = totalRatingVal;
    }

    vector<string *> getBlockList() { return blockList; }

    void setBlockList(vector<string *> blockListVal) {
        this->blockList = blockListVal;
    }
};

#endif  // SED_PROJECT_MEMBER_H
