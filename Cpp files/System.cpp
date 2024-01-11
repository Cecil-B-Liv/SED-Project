//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/INCLUDEHEADERS.h"

#define EMPTY ""

enum hardSkill {
    CAR_MECHANIC,
    TEACHING,
    TUTORING,
    PLUMBING_REPAIR,
    WRITING,
    PHOTOGRAPHY,
    COOKING,
    GARDENING,
    HOUSE_CLEANING,
    LAUNDRY,
    SEWING,
    FIRST_AID,
    TIME_MANAGEMENT,
    PUBLIC_SPEAKING,
    BASIC_COMPUTER_SKILLS,
    MONEY_MANAGEMENT,
    COMMUNICATION,
    PROBLEM_SOLVING,
    TEAMWORK,
    STRESS_MANAGEMENT
};

// static vector<Rating> ratingList;
// vector<Rating> System::getRatingList() { return ratingList; }

// Default constructor
System::System() = default;

System &System::getInstance() {
    static System System;
    return System;
}

// parse the time in csv and return
tm parseCSVTime(const std::string &timeStr) {
    tm timeStruct = {};
    istringstream iss(timeStr);
    iss >> std::get_time(&timeStruct, "%Y-%m-%d %H:%M");
    return timeStruct;
}

// Reader functions
void System::memberFileReader() {
    // Check if file exist
    ifstream file("../Database/MemberData.csv");
    if (!file.is_open()) {
        cerr << "Error opening file " << endl;
        return;
    }

    // Read each line and split ","
    string line;
    vector<string *> testList = {new string("help"), new string("me")};
    while (getline(file, line)) {
        string fullname;
        string email;
        string address;
        string phoneNumber;
        string username;
        string password;
        string ID;
        Member member;

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
        member.setSkillInfo(testList);

        memberList.push_back(member);
        addNewSkill("no", ID);
    }

    file.close();
}

void System::ratingFileReader() {
    // Check if file exist
    ifstream file("../Database/RatingData.csv");
    if (!file.is_open()) {
        cerr << "Error opening file " << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        string ratingID;
        string memberID;
        string hostID;
        string skillRating;
        string supporterRating;
        string hostRating;
        string comments;

        Rating rating;

        istringstream iss(line);
        getline(iss, ratingID, ',');
        getline(iss, memberID, ',');
        getline(iss, hostID, ',');
        getline(iss, skillRating, ',');
        getline(iss, supporterRating, ',');
        getline(iss, hostRating, ',');
        getline(iss, comments, ',');

    }
}

void System::requestFileReader() {
    // Check if file exist
    ifstream file("../Database/RequestData.csv");
    if (!file.is_open()) {
        cerr << "Error opening file " << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        string bookingID;
        string memberID;
        vector<string> skillRequired;
        string time;
        tm creationTime{};
        string status;
        Request request;

        istringstream iss(line);
        getline(iss, bookingID, ',');
        getline(iss, memberID, ',');
        getline(iss, status, ',');
        getline(iss, time, ',');

        request.setCreationTime(parseCSVTime(time));
        request.setMemberID(memberID);
        request.setBookingID(bookingID);
        request.setStatus(status);
    }
}

void System::hostFileReader() {}

void System::supporterFileReader() {}

// Writer functions
void System::memberFileWriter(const Member &newMember) {
    // Open file
    ofstream file("../Database/MemberData.csv", std::ios::app);
    if (!file.is_open()) {  // Check if file opened successfully
        cerr << "Error opening file " << endl;
        return;
    }

    file << newMember.getFullName() << "," << newMember.getEmail() << ","
         << newMember.getHomeAddress() << "," << newMember.getPhoneNumber()
         << "," << newMember.getUsername() << "," << newMember.getPassword()
         << "," << newMember.getMemberID() << endl;

    file.close();
}

string System::loginCheck(const string &memberName, const string &password) {
    string memberID;

    for (auto &member: memberList) {
        if (!(memberName == member.getUsername() &&
              password == member.getPassword())) {
            return EMPTY;
        }
        // If found, store the showMemberScreen ID and break the loop
        memberID = member.getMemberID();
        break;
    }
    // Return the showMemberScreen ID
    return memberID;
}

void System::displayMemberInformation(const string &ID) {
    // Loop through each showMemberScreen
    for (auto &it: memberList) {
        // If the ID doesn't match, exit the loop
        if (!(ID == it.getMemberID())) {
            cout << "showMemberScreen not found";
            return;
        }
        // Display showMemberScreen information
        it.showInfo();
    }
}

int System::checkIfInputIsInteger(const string &input) {
    try {
        return stoi(input);
    } catch (std::invalid_argument &) {
        cout << "Invalid input";
        return -1;
    }
}

void System::addNewRating(string ratingID, string memberID, string hostID,
                          double skillRating, double supporterRating,
                          double hostRating, string comments) {
    Rating rating(ratingID, memberID, hostID, skillRating, supporterRating,
                  hostRating, comments);
    ratingList.push_back(rating);
}

void System::removeRating(const string &ratingID) {
    int idx = 0;
    for (Rating &ratingToRemove: ratingList) {
        if (ratingID == ratingToRemove.getRatingID()) {
            ratingList.erase(ratingList.begin() + idx);
            return;
        }
        idx++;
    }
}

string System::generateMemberID() {
    int memberID = 300000;  // default ID value
    char IDSuffix = 'S';    // suffix of ID
    int totalMemberAmount = (int) memberList.size();

    int currentID = memberID + totalMemberAmount;

    return IDSuffix + std::to_string(currentID);
}

void System::registerNewMember(const string &fullName, const string &email,
                               const string &homeAddress, int phoneNumber,
                               const string &username, const string &password) {
    Member newMember;
    newMember.setFullName(fullName);
    newMember.setEmail(email);
    newMember.setHomeAddress(homeAddress);
    newMember.setPhoneNumber(phoneNumber);
    newMember.setUsername(username);
    newMember.setPassword(password);
    newMember.setMemberID(generateMemberID());

    memberFileWriter(newMember);
    memberList.push_back(newMember);
}

void System::addNewSkill(const string &newSkill, const string &memberID) {
    for (Member &iter: memberList) {
        if (iter.getMemberID() == memberID) {
            iter.addSkill(new string(newSkill));
        }
    }
}

