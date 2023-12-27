#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "../Header/Member.h"

// setter function
void User::setFullName(string fullName) { this->fullName = fullName; }

// getter function
string User::getFullName() { return this->fullName; }

// setter function
void User::setEmail(string email) { this->email = email; }

// getter function
string User::getEmail() { return this->email; }

// setter function
void User::setHomeAddress(string homeAddress) {
    this->homeAddress = homeAddress;
}

// getter function
string User::getHomeAddress() { return this->homeAddress; }

// setter function
void User::setPhoneNumber(int phoneNumber) { this->phoneNumber = phoneNumber; }

// getter function
int User::getPhoneNumber() { return this->phoneNumber; }

// setter function
void User::setCreditPoint(int creditPoint) { this->creditPoint = creditPoint; }

// getter function
int User::getCreditPoint() { return this->creditPoint; }

// setter function
void User::setRatingScore(double ratingScore) {
    this->ratingScore = ratingScore;
}

// getter function
double User::getRatingScore() { return this->ratingScore; }

// setter function
void User::setPosition(int position) { this->position = position; }

// getter function
int User::getPosition() { return this->position; }

// setter function
void User::setSkillInfo(vector<string> skillInfo) {
    this->skillInfo = skillInfo;
}

// getter function
vector<string> User::getSkillInfo() { return this->skillInfo; }