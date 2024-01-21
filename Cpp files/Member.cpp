//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/Member.h"

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
    cout << "Full Name: " << fullName << endl;
    cout << "Email: " << email << endl;
    cout << "Home Address: " << homeAddress << endl;
    cout << "Phone Number: " << phoneNumber << endl;

    cout << "Rating Score: " << skillRating << endl;
    cout << "Supporter Rating: " << supportRating << endl;
    cout << "Host Rating: " << hostRating << endl;

    cout << "Member ID: " << memberID << endl;
    cout << "Username: " << username << endl;
    // cout << "Password: " << password << endl;
    // cout << "Credit Points: " << creditPoints << endl;

    cout << "Available Status: "
         << (availableStatus ? "Available" : "Unavailable") << endl;
    cout << "Host member: " << hostMemberID << endl;
    cout << "Supporter member: " << supporterMemberID << endl;

    cout << "Skill Info: ";
    for (string *skill : skillInfoList) {
        cout << *skill << " ";
    }
    cout << endl;
}

void Member::showFullInfo() const {
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
    cout << "Credit Points: " << creditPoints << endl;

    cout << "Available Status: " << (availableStatus ? "Available" :
    "Unavailable") << endl; cout << "Host member: " << hostMemberID << endl;
    cout << "Supporter member: " << supporterMemberID << endl;

    // std::cout << std::setw(20) << "Full Name: " << std::setw(20) << fullName
    //           << std::setw(20) << "Email: " << std::setw(20) << email
    //           << std::setw(20) << "Home Address: " << std::setw(20)
    //           << homeAddress << std::setw(20)
    //           << "Phone Number: " << std::setw(20) << phoneNumber
    //           << std::setw(20) << "Rating Score: " << std::setw(20)
    //           << skillRating << std::setw(20)
    //           << "Supporter Rating: " << std::setw(20) << supportRating
    //           << std::setw(20) << "Host Rating: " << std::setw(20) << hostRating
    //           << std::setw(20) << "Member ID: " << std::setw(20) << memberID
    //           << std::setw(20) << "Username: " << std::setw(20) << username
    //           << std::endl;

    // std::cout << std::setw(20) << "Password: " << std::setw(20) << password
    //           << std::setw(20) << "Credit Points: " << std::setw(20)
    //           << creditPoints << std::setw(20)
    //           << "Available Status: " << std::setw(20)
    //           << (availableStatus ? "Available" : "Unavailable")
    //           << std::setw(20) << "Host member: " << std::setw(20)
    //           << hostMemberID << std::setw(20)
    //           << "Supporter member: " << std::setw(20) << supporterMemberID
    //           << std::endl;

    cout << "Skill Info: ";
    for (string *skill : skillInfoList) {
        cout << *skill << " ";
    }
    cout << endl;
}
