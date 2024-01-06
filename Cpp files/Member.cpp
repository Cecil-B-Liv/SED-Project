//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/INCLUDEHEADERS.h"

Member::Member(string fullName, string email, string homeAddress,
               int phoneNumber, double ratingScore,
               double supporterRating, double hostRating, string username,
               string password, string memberID, vector<string> skillInfo) {
    this->fullName = fullName;
    this->email = email;
    this->homeAddress = homeAddress;
    this->phoneNumber = phoneNumber;
    this->ratingScore = ratingScore;
    this->supporterRating = supporterRating;
    this->hostRating = hostRating;
    this->skillInfoList = skillInfo;
    this->username = username;
    this->password = password;
    this->memberID = memberID;
}
//     setter for these vectors
//     this->transactionList = transactionList;
//     this->hostList = hostList;
//     this->supporterList = supporterList;
//     this->ratingList = ratingList;
//     this->requestList = requestList;

void Member::showInfo() const {
    cout << "Full Name: " << fullName << endl;
    cout << "Email: " << email << endl;
    cout << "Home Address: " << homeAddress << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Rating Score: " << ratingScore << endl;
    cout << "Supporter Rating: " << supporterRating << endl;
    cout << "Host Rating: " << hostRating << endl;

    cout << "Member ID: " << memberID << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;

    cout << "Skill Info: ";

    for (const string &skill: skillInfoList) {
        cout << skill << " ";
    }

    cout << endl;

    // cout << "Host List: ";
    // for (Member host : hostList) {
    //     cout << "MemberID: " << host.getMemberID
    //          << ", Name: " << host.getFullName;
    // }
    // cout << endl;

    // cout << "Supporter List: ";
    // for (Member supporter : supporterList) {
    //     cout << "MemberID: " << supporter.getMemberID
    //          << ", Name: " << supporter.getFullName;
    // }
    // cout << endl;

    // cout << "Rating List: ";
    // for (auto rating : ratingList) {
    //     rating.showInfo();
    // }
    // cout << endl;

    // cout << "Request List: ";
    // for (auto request : requestList) {
    //     request.showInfo();
    // }
    // cout << endl;
}
