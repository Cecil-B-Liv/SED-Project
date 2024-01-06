//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/INCLUDEHEADERS.h"
#include "../Header files/System.h"


#define EMPTY ""

// static vector<Rating> RatingList;
// vector<Rating> System::getRatingList() { return RatingList; }

// Default constructor
System::System() = default;

System &System::getInstance() {
    static System System;
    return System;
}

// Reader functions
void System::memberFileReader() {
    string fullname;
    string email;
    string address;
    string phoneNumber;
    string username;
    string password;
    string ID;
    Member member;

    // Check if file exist
    ifstream file("../Database/MemberData.csv");
    if (!file.is_open()) {
        cerr << "Error opening file " << endl;
        return;
    }

    // Read each line and split ","
    string line;
    MemberList.clear();
    while (getline(file, line)) {
        istringstream iss(line);
        getline(iss, fullname, ',');
        getline(iss, email, ',');
        getline(iss, address, ',');
        getline(iss, phoneNumber, ',');
        getline(iss, username, ',');
        getline(iss, password, ',');
        getline(iss, ID, ',');

        member.setFullName(fullname);
        member.setEmail(email);
        member.setHomeAddress(address);
        member.setPhoneNumber(stoi(phoneNumber));
        member.setUsername(username);
        member.setPassword(password);
        member.setMemberID(ID);

        MemberList.push_back(member);
    }

    file.close();
}

void System::ratingFileReader() {

}

void System::requestFileReader() {

}

void System::hostFileReader() {

}

void System::supporterFileReader() {

}

// Writer functions
void System::memberFileWriter(const Member &newMember) {
    // Open file
    ofstream file("../Database/MemberData.csv", std::ios::app);
    if (!file.is_open()) {  // Check if file opened successfully
        cerr << "Error opening file " << endl;
        return;
    }

    file << newMember.getFullName() << "," << newMember.getEmail() << "," << newMember.getHomeAddress() << ","
         << newMember.getPhoneNumber() << "," << newMember.getUsername() << "," << newMember.getPassword() << ","
         << newMember.getMemberID() << endl;

    file.close();
}

string System::loginCheck(const string &memberName, const string &password) {
    string memberID;

    for (const Member &member: getMemberList()) {
        if (!(memberName == member.getUsername() &&
              password == member.getPassword())) {
            return EMPTY;
        }
        // If found, store the member ID and break the loop
        memberID = member.getMemberID();
        break;
    }
    // Return the member ID
    return memberID;
}

void System::getMemberInformation(const string &ID) {

    // Loop through each member
    for (const Member &member: getMemberList()) {
        // If the ID doesn't match, exit the loop
        if (!(ID == member.getMemberID())) {
            cout << "Member not found";
            return;
        }
        // Display member information
        member.showInfo();
    }
}

int System::checkIfInputIsInteger(const string &input) {
    try {
        return stoi(input);
    } catch (std::invalid_argument &) {
        return -1;
    }
}

void System::addRating(string ratingID, string memberID, string hostID, double skillRating, double supporterRating,
                       double hostRating, string comments) {
    Rating rating(ratingID, memberID, hostID, skillRating,
                  supporterRating, hostRating, comments);
    RatingList.push_back(rating);
}

void System::removeRating(const string &ratingID) {
    int idx = 0;
    for (const Rating &ratingToRemove: RatingList) {
        if (ratingID == ratingToRemove.getRatingID()) {
            RatingList.erase(RatingList.cbegin() + idx);
            return;
        }
        idx++;
    }
}

string System::generateMemberID() {
    int memberID = 300000; // default ID value
    char IDSuffix = 'S'; // suffix of ID
    int totalMemberAmount = (int) MemberList.size();

    int currentID = memberID + totalMemberAmount;

    return IDSuffix + std::to_string(currentID);
}

void System::registerNewMember(const string &fullName, const string &email, const string &homeAddress,
                               int phoneNumber, const string &username, const string &password) {
    Member newMember;
    newMember.setFullName(fullName);
    newMember.setEmail(email);
    newMember.setHomeAddress(homeAddress);
    newMember.setPhoneNumber(phoneNumber);
    newMember.setUsername(username);
    newMember.setPassword(password);
    newMember.setMemberID(generateMemberID());

    memberFileWriter(newMember);
    MemberList.push_back(newMember);
}


