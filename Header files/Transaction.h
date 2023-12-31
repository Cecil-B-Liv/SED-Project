//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_TRANSACTION_H
#define SED_PROJECT_TRANSACTION_H

#include "BasicSTDLIB.h"

class Transaction {
   private:
    string transactionID;
    string transactionType;
    string memberID;
    double amount;
    string time;  // in dd/mm/yyyy format

   public:
    // constructor
    Transaction();
    // function code
    static bool processTransaction(int);
    void showInfo();

    // accessor methods
    string getTransactionID() { return transactionID; }
    void setTransactionID(string ID) { transactionID = ID; }

    double getAmount() { return amount; }
    void setAmount(double amount) { this->amount = amount; }

    string getTransactionType() { return transactionType; }
    void setTransactionType(string transactionType) {
        this->transactionType = transactionType;
    }

    string getMemberID() { return memberID; }
    void setMemberID(string memberID) { this->memberID = memberID; }

    string getTime() { return time; }
    void setTime(string time) { this->time = time; }
};

#endif  // SED_PROJECT_TRANSACTION_H
