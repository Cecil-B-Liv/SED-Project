//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/INCLUDEHEADERS.h"

static int counter;

Member::Member() {}

void Member::showInfo() const {
    cout << "Full Name: " << fullName << endl;
    cout << "Email: " << email << endl;
    cout << "Home Address: " << homeAddress << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Position: " << position << endl;
    cout << "Rating Score: " << ratingScore << endl;
    cout << "Supporter Rating: " << supporterRating << endl;
    cout << "Host Rating: " << hostRating << endl;

    cout << "Member ID: " << memberID << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;

    cout << "Skill Info: ";
    for (auto skill : skillInfoList) {
        cout << skill << " ";
    }
    cout << endl;

    // cout << "TransactionList: ";
    // for (Transaction transaction : transactionList) {
    //     transaction.showInfo();
    // }
    // cout << endl;

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
    // for (auto rating : RatingList) {
    //     rating.showInfo();
    // }
    // cout << endl;

    // cout << "Request List: ";
    // for (auto request : RequestList) {
    //     request.showInfo();
    // }
    // cout << endl;
}
