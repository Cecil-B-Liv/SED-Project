#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class User {
   private:
    string fullName;
    string userName;
    string email;
    string homeAddress;
    int phoneNumber;
    int creditPoint;
    double ratingScore;

    vector<string> skillInfo;

   public:
    // Constructor code
    User(string fullName = "", string userName = "", string email = "",
         string homeAddress = "", int phoneNumber = 0, int creditPoint = 0,
         double ratingScore = 0.0, vector<string> skillInfo = {})
        : fullName(fullName),
          userName(userName),
          email(email),
          homeAddress(homeAddress),
          phoneNumber(phoneNumber),
          creditPoint(creditPoint),
          ratingScore(ratingScore),
          skillInfo(skillInfo.empty() ? vector<string>(1, "NA") : skillInfo) {}

    // Function code
    //     void listAvailability() {}
    //     void searchSupporter() {}
    //     bool bookSupporter() {}
    //     void rateSupporter() {}
    //     void rateHost() {}
    //     void blockMember() {}
    //     void viewRequest() {}
    //     void AcceptRejectRequest() {}

    // Testing code
    void showInfo() {
        cout << "Full Name : " << fullName << endl;
        cout << "User Name : " << userName << endl;
        cout << "Email : " << email << endl;
        cout << "Home Address : " << homeAddress << endl;
        cout << "Phone Number : " << phoneNumber << endl;
        cout << "Credit Points : " << creditPoint << endl;
        cout << "Rating Score : " << ratingScore << endl;
        for (auto i : skillInfo) {
            cout << "Skills : " << i << "\t";
        }
    }
};

// Test in main
// vector<string> skillExist{"Teaching","Eating"};

//     User Liv("Liv","Liv","Liv","discord",12345,100,100,skillExist);
//     Liv.showInfo();