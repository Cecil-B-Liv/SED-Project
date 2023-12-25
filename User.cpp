#include "User.h"

#include <iostream>

#define MAX_NUM_OF_SKILL 20

using std::cout;
using std::endl;
using std::string;

// Constructor code
User::User(string fullName = "", string userName = "", string email = "",
           string homeAddress = "", int phoneNumber = 0,
           string skillInfo[] = nullptr)
    : fullName(fullName),
      userName(userName),
      email(email),
      homeAddress(homeAddress),
      phoneNumber(phoneNumber)

{
    for (int i = 0; i < MAX_NUM_OF_SKILL; i++) {
        if (skillInfo == nullptr) {
            skillInfo[i] = "NA";  // default value
        } else {
            skillInfo[i] = skillInfo[i];
        }
    }
}

// Function code
void User::listAvailability(){};
void User::searchSupporter(){};
bool User::bookSupporter(){};
void User::rateSupporter(){};
void User::rateHost(){};
void User::blockMember(){};
void User::viewRequest(){};
void User::AcceptRejectRequest(){};

// Testing Code
void User::showInfo() {
    cout << "Full Name : " << fullName << endl;
    cout << "User Name : " << userName << endl;
    cout << "Email : " << email << endl;
    cout << "Home Address : " << homeAddress << endl;
    cout << "Phone Number : " << phoneNumber << "\n" << std::flush;
    for (int i = 0; i < MAX_NUM_OF_SKILL; i++) {
        if (!skillInfo[i].empty()) cout << "Skills : " << skillInfo[i] << '\n';
    }
}
