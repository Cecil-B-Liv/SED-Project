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
    // this->memberID = memberID;

    // this->transactionList = transactionList;
    // this->hostList = hostList;
    // this->supporterList = supporterList;
    // this->ratingList = ratingList;
    // this->requestList = requestList;
}

void Member::showInfo() {
    cout << "Full Name: " << fullName << endl;
    cout << "Email: " << email << endl;
    cout << "Home Address: " << homeAddress << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Position: " << position << endl;
    cout << "Rating Score: " << ratingScore << endl;
    cout << "Supporter Rating: " << supporterRating << endl;
    cout << "Host Rating: " << hostRating << endl;
    // cout << "Skill Info: ";
    // for (auto &skill : skillInfo) {
    //     cout <<  skill << " ";
    // } Has yet to implemented
    cout << endl;
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


