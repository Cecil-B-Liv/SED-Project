//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/Member.h"

#include "../Header files/INCLUDEHEADERS.h"

Member::Member(string fullName, string email, string homeAddress,
               string phoneNumber, double ratingScore, double supporterRating,
               double hostRating, string username, string password,
               string memberID, double creditPoints, double consumingPoints,
               double totalRating, int available_status,
               vector<string *> skillInfo, string hostMemberID,
               string supporterMemberID) {
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
    this->totalRating = totalRating;
    this->creditPoints = creditPoints;
    this->consumingPoints = consumingPoints;
    this->availableStatus = available_status;
    this->hostMemberID = hostMemberID;
    this->supporterMemberID = supporterMemberID;
}

void Member::showInfo() const {
    cout << COLOR_GREEN << "Full Name: " << COLOR_RESET << fullName << endl;
    cout << COLOR_GREEN << "Email: " << COLOR_RESET << email << endl;
    cout << COLOR_GREEN << "Home Address: " << COLOR_RESET << homeAddress
         << endl;
    cout << COLOR_GREEN << "Phone Number: " << COLOR_RESET << phoneNumber
         << endl;

    cout << COLOR_CYAN << "Rating Score: " << COLOR_RESET << skillRating
         << endl;
    cout << COLOR_CYAN << "Supporter Rating: " << COLOR_RESET << supportRating
         << endl;
    cout << COLOR_CYAN << "Host Rating: " << COLOR_RESET << hostRating << endl;

    cout << COLOR_CYAN << "Member ID: " << COLOR_RESET << memberID << endl;
    cout << COLOR_CYAN << "Username: " << COLOR_RESET << username << endl;
    // cout << "Password: " << password << endl;
    // cout << "Credit Points: " << creditPoints << endl;

    cout << COLOR_BLUE << "Available Status: " << COLOR_RESET
         << (availableStatus ? "Available" : "Unavailable") << endl;
    cout << COLOR_BLUE << "Host member: " << COLOR_RESET << hostMemberID
         << endl;
    cout << COLOR_BLUE << "Supporter member: " << COLOR_RESET
         << supporterMemberID << endl;

    cout << COLOR_BLUE << "Skill Info: " << COLOR_RESET;
    for (string *skill : skillInfoList) {
        cout << *skill << " ";
    }
    cout << endl;
}

void Member::showFullInfo() const {
    cout << COLOR_GREEN << "Full Name: " << COLOR_RESET << fullName << endl;
    cout << COLOR_GREEN << "Email: " << COLOR_RESET << email << endl;
    cout << COLOR_GREEN << "Home Address: " << COLOR_RESET << homeAddress
         << endl;
    cout << COLOR_GREEN << "Phone Number: " << COLOR_RESET << phoneNumber
         << endl;

    cout << COLOR_CYAN << "Rating Score: " << COLOR_RESET << skillRating
         << endl;
    cout << COLOR_CYAN << "Supporter Rating: " << COLOR_RESET << supportRating
         << endl;
    cout << COLOR_CYAN << "Host Rating: " << COLOR_RESET << hostRating << endl;

    cout << COLOR_CYAN << "Member ID: " << COLOR_RESET << memberID << endl;
    cout << COLOR_CYAN << "Username: " << COLOR_RESET << username << endl;
    cout << COLOR_CYAN << "Password: " << COLOR_RESET << password << endl;
    cout << COLOR_CYAN << "Credit Points: " << COLOR_RESET << creditPoints
         << endl;

    cout << COLOR_BLUE << "Available Status: " << COLOR_RESET
         << (availableStatus ? "Available" : "Unavailable") << endl;
    cout << COLOR_BLUE << "Host member: " << COLOR_RESET << hostMemberID
         << endl;
    cout << COLOR_BLUE << "Supporter member: " << COLOR_RESET
         << supporterMemberID << endl;

    cout << COLOR_BLUE << "Skill Info: " << COLOR_RESET;
    for (string *skill : skillInfoList) {
        cout << *skill << " ";
    }
    cout << endl;
}
