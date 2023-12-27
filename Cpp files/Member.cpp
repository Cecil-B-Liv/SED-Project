#include "../Header/StandardLib.h"
#include "../Header/Member.h"
#include "User.cpp"

// constructor code
Member::Member(string username = "username", string password = "pass")
    : username(username), password(password){};

void Member::showInfo()
{
    cout << "Username : " << username << endl;
    cout << "Password : " << password << endl;
}

// setter function
void Member::setFullName(string fullName)
{
    this->fullName = fullName;
}

// getter function
string Member::getFullName() { return this->fullName; }

// setter function
void Member::setEmail(string email) { this->email = email; }

// getter function
string Member::getEmail() { return this->email; }

// setter function
void Member::setHomeAddress(string homeAddress)
{
    this->homeAddress = homeAddress;
}

// getter function
string Member::getHomeAddress() { return this->homeAddress; }

// setter function
void Member::setPhoneNumber(int phoneNumber) { this->phoneNumber = phoneNumber; }

// getter function
int Member::getPhoneNumber() { return this->phoneNumber; }

// setter function
void Member::setCreditPoint(int creditPoint) { this->creditPoint = creditPoint; }

// getter function
int Member::getCreditPoint() { return this->creditPoint; }

// setter function
void Member::setRatingScore(double ratingScore)
{
    this->ratingScore = ratingScore;
}

// getter function
double Member::getRatingScore() { return this->ratingScore; }

// setter function
void Member::setPosition(int position) { this->position = position; }

// getter function
int Member::getPosition() { return this->position; }

// setter function
void Member::setSkillInfo(vector<string> skillInfo)
{
    this->skillInfo = skillInfo;
}

// getter function
vector<string> Member::getSkillInfo() { return this->skillInfo; };
