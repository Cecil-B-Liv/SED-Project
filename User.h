#include <iostream>
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
    // Constructor
    User(string fullName, string userName, string email, string homeAddress,
         int phoneNumber, string skillInfo[]);

    // Function code
    void listAvailability();
    void searchSupporter();
    bool bookSupporter();
    void rateSupporter();
    void rateHost();
    void blockMember();
    void viewRequest();
    void AcceptRejectRequest();

    // Testing code
    void showInfo();
};