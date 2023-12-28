//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_MEMBER_H
#define SED_PROJECT_MEMBER_H

#include "BasicSTDLIB.h"
#include "Transaction.h"

class Member {
private:
    string fullName;
    string email;
    string homeAddress;

    int phoneNumber;
    int position;

    double ratingScore;
    double supporterRating;
    double hostRating;

    vector<string> skillInfo;
    vector<Transaction> transaction;
    vector<Member> hostList;
    vector<Member> supporterList;

public:
    Member(string, string, string, int, int, double, double, double, vector<string>);

    void showInfo();
};

#endif //SED_PROJECT_MEMBER_H
