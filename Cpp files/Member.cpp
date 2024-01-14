//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/Member.h"

#include "../Header files/INCLUDEHEADERS.h"

Member::Member(string fullName, string email, string homeAddress,
               int phoneNumber, double ratingScore, double supporterRating,
               double hostRating, string username, string password,
               string memberID, bool available_status,
               vector<string *> skillInfo, vector<Rating> ratingList,
               vector<Request> requestList, Member *hostMember,
               Member *supportMember) {
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
    // this->availableStatus = available_status;
    // this->hostMember = hostMember;
    // this->supporterMember = supporterMember;
}

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
    cout << "Available Status: " << availableStatus << endl;

    // if (this->hostMember != nullptr)
    //     cout << "Host List: " << hostMember->getFullName() << endl;
    // if (this->supporterMember != nullptr)
    //     cout << "Supporter List: " << supporterMember->getFullName() << endl;

    cout << "Skill Info: ";
    for (string *skill : skillInfoList) {
        cout << *skill << " ";
    }
    cout << endl;

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
