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
    string email;
    string homeAddress;
    int phoneNumber;
    int creditPoint;
    double ratingScore;
    int position;
    vector<string> skillInfo;

   public:
    // Constructor code
    User(string fullName = "", string email = "", string homeAddress = "",
         int phoneNumber = 0, int creditPoint = 0, double ratingScore = 0.0,
         int postion = 1, vector<string> skillInfo = {})
        : fullName(fullName),
          email(email),
          homeAddress(homeAddress),
          phoneNumber(phoneNumber),
          creditPoint(creditPoint),
          ratingScore(ratingScore),
          position(position),
          skillInfo(skillInfo.empty() ? vector<string>(1, "NA") : skillInfo) {}

    //     //     Function code
    //     void listAvailability() {}
    //     void searchSupporter() {}
    //     bool bookSupporter() {}
    //     void rateSupporter() {}
    //     void rateHost() {}
    //     void blockMember() {}
    //     void viewRequest() {}
    //     void AcceptRejectRequest() {}

    // Testing code
    virtual void showInfo() {
        cout << "Full Name : " << fullName << endl;
        cout << "Email : " << email << endl;
        cout << "Home Address : " << homeAddress << endl;
        cout << "Phone Number : " << phoneNumber << endl;
        cout << "Credit Points : " << creditPoint << endl;
        cout << "Rating Score : " << ratingScore << endl;
        cout << "Position : ";
        (position == 0) ? cout << "Admin" : cout << "Member" << endl;
        for (auto i : skillInfo) {
            cout << "Skills : " << i << "\t";
        }
    }
};

// Test in main
// vector<string> skillExist{"Teaching","Eating"};

//     User Liv("Liv","Liv","discord",12345,100,100,skillExist);
//     Liv.showInfo();

// vector<string> skillExist{};

//     User Liv("Liv", "Liv", "discord", 12345, 100, 100, 1, skillExist);
//     Liv.showInfo();