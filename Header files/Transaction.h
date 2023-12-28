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

public:
    static bool processTransaction(int);
};

#endif //SED_PROJECT_TRANSACTION_H
