#include "StandardLib.h"
#include "User.cpp"
#include <Member.h>

class Member : public User
{
protected:
    string username;
    string password;

public:
    // constructor code
    Member(string username = "username", string password = "pass")
        : username(username), password(password){};

    void showInfo()
    {
        cout << "Username : " << username << endl;
        cout << "Password : " << password << endl;
    }

    // setter function
    void setFullName(string fullName) { this->fullName = fullName; }

    // getter function
    string getFullName() { return this->fullName; }

    // setter function
    void setEmail(string email) { this->email = email; }

    // getter function
    string getEmail() { return this->email; }

    // setter function
    void setHomeAddress(string homeAddress)
    {
        this->homeAddress = homeAddress;
    }

    // getter function
    string getHomeAddress() { return this->homeAddress; }

    // setter function
    void setPhoneNumber(int phoneNumber) { this->phoneNumber = phoneNumber; }

    // getter function
    int getPhoneNumber() { return this->phoneNumber; }

    // setter function
    void setCreditPoint(int creditPoint) { this->creditPoint = creditPoint; }

    // getter function
    int getCreditPoint() { return this->creditPoint; }

    // setter function
    void setRatingScore(double ratingScore)
    {
        this->ratingScore = ratingScore;
    }

    // getter function
    double getRatingScore() { return this->ratingScore; }

    // setter function
    void setPosition(int position) { this->position = position; }

    // getter function
    int getPosition() { return this->position; }

    // setter function
    void setSkillInfo(vector<string> skillInfo)
    {
        this->skillInfo = skillInfo;
    }

    // getter function
    vector<string> getSkillInfo() { return this->skillInfo; }
};