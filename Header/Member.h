#pragma once
#include "User.h"

class Member: public User
{
private:
    string username;
    string password;

public:
    Member(string, string);
    void showInfo();
    void setFullName(string);
    string getFullName();
    void setEmail(string);
    ;

    // getter function
    string getEmail();

    // setter function
    void setHomeAddress(string);
    // getter function
    string getHomeAddress();

    // setter function
    void setPhoneNumber(int);

    // getter function
    int getPhoneNumber();

    // setter function
    void setCreditPoint(int);

    // getter function
    int getCreditPoint();
    // setter function
    void setRatingScore(double);
    // getter function
    double getRatingScore();
    // setter function
    void setPosition(int);

    // getter function
    int getPosition();

    // setter function
    void setSkillInfo(vector<string>);

    // getter function
    vector<string> getSkillInfo();
};
