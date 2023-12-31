//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_TRANSACTION_H
#define SED_PROJECT_TRANSACTION_H

#include "BasicSTDLIB.h"

class Transaction {
   private:
    double amount;
    string transactionType;
    string memberID;
    string time; // in dd/mm/yyyy format

   public:
    // constructor
    Transaction();
    // function code
    static bool processTransaction(int);
    void showInfo();
    // accessor methods
    //  getter and setter methods for amount attribute
    double getAmount() { return amount; }

    void setAmount(double amount) { this->amount = amount; }

    // getter and setter methods for transactionType attribute
    string getTransactionType() { return transactionType; }

    void setTransactionType(string transactionType) {
        this->transactionType = transactionType;
    }

    // getter and setter methods for memberID attribute
    string getMemberID() { return memberID; }

    void setMemberID(string memberID) { this->memberID = memberID; }

    // getter and setter methods for time attribute
    string getTime() { return time; }

    void setTime(string time) { this->time = time; }
};

#endif  // SED_PROJECT_TRANSACTION_H
