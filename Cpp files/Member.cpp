//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/Member.h"

Member::Member(string fullName, string email, string homeAddress, int phoneNumber, int position, double ratingScore,
               double supporterRating, double hostRating, vector<string> skillInfo) {
    this->fullName = fullName;
    this->email = email;
    this->homeAddress = homeAddress;
    this->phoneNumber = phoneNumber;
    this->position = position;
    this->ratingScore = ratingScore;
    this->supporterRating = supporterRating;
    this->hostRating = hostRating;
    this->skillInfo = skillInfo;
}

void Member::showInfo() {
    cout << fullName;
}

