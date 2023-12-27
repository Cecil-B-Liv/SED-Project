#include "../Header/User.h"

// Constructor code
User::User(string fullName = "", string email = "", string homeAddress = "",
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

void User::showInfo()
{
    cout << "Full Name : " << User::fullName << endl;
    cout << "Email : " << email << endl;
    cout << "Home Address : " << homeAddress << endl;
    cout << "Phone Number : " << phoneNumber << endl;
    cout << "Credit Points : " << creditPoint << endl;
    cout << "Rating Score : " << ratingScore << endl;
    cout << "Position : ";
    (position == 0) ? cout << "Admin" : cout << "Member" << endl;
    for (auto i : skillInfo)
    {
        cout << "Skills : " << i << "\t";
    }
};