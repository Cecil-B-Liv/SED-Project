//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_SYSTEM_H
#define SED_PROJECT_SYSTEM_H

#include "BasicSTDLIB.h"
#include "Member.h"

// Data path
const string USER_PATH = "../Database/MemberData.csv";
const string TRANSACTION_PATH = "../Database/TransactionData.csv";
const string REQUEST_PATH = "../Database/RequestData.csv";
const string RATING_PATH = "../Database/RatingData.csv";

class System {
   public:


    static void MemberReader();
    static void MemberWriter();
    static vector<Member> getMemberList();

    // static void RatingReader();
    // static void RatingWriter();
    // static vector<Rating> getRatingList();

    // static void RequestReader();
    // static void RequestWriter();
    // static vector<Request> getRequestList();

    static void TransactionReader();
    static void TransactionWriter();
    static vector<Transaction> getTransactionList();

    static string LoginCheck(const string &, const string &);
    static void getMemberInformation(const string &);
};

#endif  // SED_PROJECT_SYSTEM_H
