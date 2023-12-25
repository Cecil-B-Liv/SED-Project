#include<iostream>
#include "User.h"

using std::string;
using std::cout;

User::User (string fullNameVal = "",
            string userNameVal = "",
            string emailVal = "",
            string homeAddressVal = "",
            int phoneNumberVal = "",
            string skillInfoVal[] = nullptr)
        :   fullName(fullNameVal), 
            userName(userNameVal),
            