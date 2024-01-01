//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/INCLUDEHEADERS.h"

//constructor
Transaction::Transaction() {
}

void Transaction::showInfo(){
    cout << "Transaction Info:\n";
    cout << "Transaction ID: " << transactionID << "\n";
    cout << "Transaction Type: " << transactionType << "\n";
    cout << "Member ID: " << memberID << "\n";
    cout << "Amount: " << amount << "\n";
    // cout << "Time: " << time->getDate() << time->getMonth() << time->getYear() <<"\n";
}