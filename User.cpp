#include<iostream>
#include "User.h"

#define MAX_NUM_OF_SKILL 20

using std::string;
using std::cout;

    //Constructor code
    User::User (string fullName = "",
            string userName = "",
            string email = "",
            string homeAddress = "",
            int phoneNumber = 0,
            string skillInfo[] = nullptr)
                :   fullName(fullName), 
                    userName(userName),
                    email(email),
                    homeAddress(homeAddress),
                    phoneNumber(phoneNumber) 
                    
                    {   for (int i = 0; i < MAX_NUM_OF_SKILL; i++) {
                            if (skillInfo == nullptr) {
                                    skillInfo[i] = "NA"; // default value
                            } else {
                                skillInfo[i] = skillInfo[i];
                            }
                        }       
                    }

    
    //Function code
    void User::listAvailability(){};
    void User::searchSupporter(){};
    bool User::bookSupporter(){};
    void User::rateSupporter(){};
    void User::rateHost(){};
    void User::blockMember(){};
    void User::viewRequest(){};
    void User::AcceptRejectRequest(){};     