#pragma once
#include "StandardLib.h"
class User
{
protected:
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
    User(string, string, string, int, int, double, int, vector<string>);
    // : fullName(fullName),
    //   email(email),
    //   homeAddress(homeAddress),
    //   phoneNumber(phoneNumber),
    //   creditPoint(creditPoint),
    //   ratingScore(ratingScore),
    //   position(position),
    //   skillInfo(skillInfo.empty() ? vector<string>(1, "NA") : skillInfo) {}

    void showInfo();
    // {
    //     cout << "Full Name : " << User::fullName << endl;
    //     cout << "Email : " << email << endl;
    //     cout << "Home Address : " << homeAddress << endl;
    //     cout << "Phone Number : " << phoneNumber << endl;
    //     cout << "Credit Points : " << creditPoint << endl;
    //     cout << "Rating Score : " << ratingScore << endl;
    //     cout << "Position : ";
    //     (position == 0) ? cout << "Admin" : cout << "Member" << endl;
    //     for (auto i : skillInfo)
    //     {
    //         cout << "Skills : " << i << "\t";
    //     }
    // }
};
// Testing code

// Test in main
// vector<string> skillExist{"Teaching","Eating"};

//     User Liv("Liv","Liv","discord",12345,100,100,skillExist);
//     Liv.showInfo();

// vector<string> skillExist{};

//     User Liv("Liv", "Liv", "discord", 12345, 100, 100, 1, skillExist);
//     Liv.showInfo();