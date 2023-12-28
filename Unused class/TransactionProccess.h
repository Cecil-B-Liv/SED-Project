//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_TRANSACTIONPROCCESS_H
#define SED_PROJECT_TRANSACTIONPROCCESS_H

#include "BasicSTDLIB.h"

class TransactionProccess {
private:
    double amount;
    string transactionType;

public:
    static bool processTransaction(int);
};

#endif //SED_PROJECT_TRANSACTIONPROCCESS_H
