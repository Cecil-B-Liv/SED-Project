//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/TransactionProccess.h"

#define DEPOSITE 1
#define WITHDRAW 2

bool TransactionProccess::processTransaction(int type) {
    switch (type) {
        case DEPOSITE:
            cout << "you have deposited\n";
            return true;
        case WITHDRAW:
            cout << "you have withdrew\n";
            return true;
        default:
            return false;
    }
}
