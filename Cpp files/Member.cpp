//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/Member.h"


Member::Member(string fullName, string email, string homeAddress,
               string phoneNumber, double ratingScore, double supporterRating,
               double hostRating, string username, string password,
               string memberID, int creditPoints, int available_status,
               vector<string *> skillInfo,
               string hostMemberID, string supporterMemberID) {
    this->fullName = fullName;
    this->email = email;
    this->homeAddress = homeAddress;
    this->phoneNumber = phoneNumber;
    this->skillRating = ratingScore;
    this->supportRating = supporterRating;
    this->hostRating = hostRating;
    this->skillInfoList = skillInfo;
    this->username = username;
    this->password = password;
    this->memberID = memberID;
    this->creditPoints = creditPoints;
    this->availableStatus = available_status;
    this->hostMemberID = hostMemberID;
    this->supporterMemberID = supporterMemberID;
}

void Member::showInfo() const {
    cout << "Full Name: " << fullName << endl;
    cout << "Email: " << email << endl;
    cout << "Home Address: " << homeAddress << endl;
    cout << "Phone Number: " << phoneNumber << endl;

    cout << "Rating Score: " << skillRating << endl;
    cout << "Supporter Rating: " << supportRating << endl;
    cout << "Host Rating: " << hostRating << endl;

    cout << "Member ID: " << memberID << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "Credit Points:" << creditPoints << endl;

    cout << "Available Status: " << (availableStatus ? "Available" : "Unavailable") << endl;
    cout << "Host member: " << hostMemberID << endl;
    cout << "Supporter member: " << supporterMemberID << endl;


    cout << "Skill Info: ";
    for (string *skill: skillInfoList) {
        cout << *skill << " ";
    }
    cout << endl;

    // cout << "Rating List: ";
    // for (auto rating : ratingList) {
    //     rating.showInfo();
    // }
    // cout << endl;

    // cout << "Booking List: ";
    // for (auto request : requestList) {
    //     request.showInfo();
    // }
    // cout << endl;
}
