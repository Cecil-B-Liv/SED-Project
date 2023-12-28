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
    string username;
    string password;

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
    explicit Member(string= "", string= "", string= "", int= 0, int= 0, double= 0.0, double= 0.0, double= 0.0,
                    vector<string> = {}, string= "", string= "");

    void showInfo();

    string getUserName();

    string getPassword();

    void setPassword(string);

    void setUserName(string);
};

#endif //SED_PROJECT_MEMBER_H
