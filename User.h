#include<iostream>
using std::string;
using std::cout;

#define MAX_NUM_OF_SKILL 20

class User{
private:
    string fullName;
    string userName;
    string email;
    string homeAddress;
    int phoneNumber;
    string skillInfo[MAX_NUM_OF_SKILL];
    
public:
    User (  string fullName,
            string userName,
            string email,
            string homeAddress,
            int phoneNumber,
            string skillInfo[]);

    void listAvailability();
    void searchSupporter();
    bool bookSupporter();
    void rateSupporter();
    void rateHost();
    void blockMember();
    void viewRequest();
    void AcceptRejectRequest();

};