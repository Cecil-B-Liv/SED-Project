//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/Member.h"

Member::Member(string fullName, string email, string homeAddress, int phoneNumber, int position, double ratingScore,
               double supporterRating, double hostRating, vector<string> skillInfo, string username, string password) {
    this->fullName = fullName;
    this->email = email;
    this->homeAddress = homeAddress;
    this->phoneNumber = phoneNumber;
    this->position = position;
    this->ratingScore = ratingScore;
    this->supporterRating = supporterRating;
    this->hostRating = hostRating;
    this->skillInfo = skillInfo;
    this->username = username;
    this->password = password;
}

void Member::showInfo() {
    cout << fullName;
}

string Member::getUserName() {
    return username;
}

string Member::getPassword() {
    return password;
}

void Member::setPassword(string passwordVal) {
    this->password = passwordVal;
}

void Member::setUserName(string usernameVal) {
    this->username = usernameVal;
}

