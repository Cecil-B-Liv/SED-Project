#include <cstring>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

#define MAX_NUM_OF_SKILL 20

class User {
   private:
    string fullName;
    string userName;
    string email;
    string homeAddress;
    int phoneNumber;
    string skillInfo[MAX_NUM_OF_SKILL];

   public:
    // Constructor code
    User(string fullName = "", string userName = "", string email = "",
         string homeAddress = "", int phoneNumber = 0,
         string skillInfo[] = nullptr)
        : fullName(fullName),
          userName(userName),
          email(email),
          homeAddress(homeAddress),
          phoneNumber(phoneNumber) {
        for (int i = 0; i < MAX_NUM_OF_SKILL; i++) {
            if (skillInfo == nullptr) {
                skillInfo[i] = "NA";  // default value
            } else {
                skillInfo[i] = skillInfo[i];
            }
        }
    }

    // Function code
    void listAvailability() {}
    void searchSupporter() {}
    bool bookSupporter() {}
    void rateSupporter() {}
    void rateHost() {}
    void blockMember() {}
    void viewRequest() {}
    void AcceptRejectRequest() {}

    // Testing code
    void showInfo() {
        cout << "Full Name : " << fullName << endl;
        cout << "User Name : " << userName << endl;
        cout << "Email : " << email << endl;
        cout << "Home Address : " << homeAddress << endl;
        cout << "Phone Number : " << phoneNumber << "\n" << std::flush;
        for (int i = 0; i < MAX_NUM_OF_SKILL; i++) {
            if (!skillInfo[i].empty())
                cout << "Skills : " << skillInfo[i] << '\n';
        }
    }
};