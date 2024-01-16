//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/System.h"

const string EMPTY;

enum Status {
    UNAVAILABLE, AVAILABLE
};

const vector<string> skillStrings = {
        "Unknown skill",
        "Car Mechanic",
        "Teaching",
        "Tutoring",
        "Plumbing Repair",
        "Writing",
        "Photography",
        "Cooking",
        "Gardening",
        "House Cleaning",
        "Laundry",
        "Sewing",
        "First Aid",
        "Time Management",
        "Public Speaking",
        "Basic Computer Skills",
        "Money Management",
        "Communication",
        "Problem Solving",
        "Teamwork",
        "Stress Management"
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

string toLowerString(string &input) {
    for (unsigned char c: input) {
        tolower(c);
    }
    return input;
}

// Reader functions
void System::memberFileReader() {
    // Check if file exist
    ifstream file(MEMBER_PATH);
    if (!file.is_open()) {
        cerr << "Error opening file memberdata in member reader" << endl;
        return;
    }

    // Read each line and split ","
    string line;
    while (getline(file, line)) {
        string fullname;
        string email;
        string address;
        string phoneNumber;
        string username;
        string password;
        string ID;
        string skills;
        vector<string *> newSkillsList;
        Member member;

        // vector<Rating> ratingList;
        // vector<Booking> requestList;
        // Member *hostMember;
        // Member *supporterMember;

        istringstream iss(line);
        getline(iss, fullname, ',');
        getline(iss, email, ',');
        getline(iss, address, ',');
        getline(iss, phoneNumber, ',');
        getline(iss, username, ',');
        getline(iss, password, ',');
        getline(iss, ID, ',');
        getline(iss, skills, ',');

        stringstream getSkill(skills);
        string skill;
        while (getline(getSkill, skill, '-')) {
            newSkillsList.push_back(new string(skill));
        }

        member.setFullName(fullname);
        member.setEmail(email);
        member.setHomeAddress(address);
        member.setPhoneNumber(stoi(phoneNumber));
        member.setUsername(username);
        member.setPassword(password);
        member.setMemberID(ID);
        member.setSkillInfo(newSkillsList);
        // member.setAvailableStatus();

        memberList.push_back(member);
    }

    file.close();
}

void System::ratingFileReader() {
    // Check if file exist
    ifstream file(RATING_PATH);
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
    ifstream file(REQUEST_PATH);
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
        Booking request;

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

// Writer functions
void System::memberFileWriter() {
    // Open file
    ofstream file(MEMBER_PATH);
    if (!file.is_open()) {  // Check if file opened successfully
        cerr << "Error opening file member data in member writer" << endl;
        return;
    }

    for (Member &members: memberList) {
        string skillList;
        for (auto &skill: members.getSkillInfo()) {
            skillList = *skill;

            if (&skill != &members.getSkillInfo().back()) {
                skillList += "-";
            }
        }
        file << members.getFullName() << "," << members.getEmail() << ","
             << members.getHomeAddress() << "," << members.getPhoneNumber()
             << "," << members.getUsername() << "," << members.getPassword()
             << "," << members.getMemberID() << "," << skillList;
    }

    //add member available status
    file.close();
}

void System::ratingFileWriter() {}

void System::requestFileWriter() {}

int System::checkMemberExist(const string &ID) {
    // check if there is a member with that ID
    for (const Member &member: memberList) {
        if ((ID == member.getMemberID())) return Status::AVAILABLE;
    }
    return Status::UNAVAILABLE;
}

void System::resetPassword(const string &ID, const string &newPwd) {
    for (Member &member: memberList) {
        if (ID == member.getMemberID()) {
            member.setPassword(newPwd);
            memberFileWriter();
            cout << "\nSuccessfully changed the password!" << endl;
        }
    }
}

string System::getIDWithUsernamePassword(const string &username,
                                         const string &password) {
    string memberID;

    for (const Member &member: getMemberList()) {
        if (!(username == member.getUsername() &&
              password == member.getPassword())) {
            return EMPTY;
        }
        // If found, store the showMemberScreen ID and break the loop
        memberID = member.getMemberID();
        break;
    }
    // Return the showMemberScreen ID
    return memberID;
}  // Check if valid information was input

Member System::getMemberObject(const string &ID) {
    Member temp;
    for (const Member &mem: getMemberList()) {
        if (mem.getMemberID() == ID) {
            return mem;
        }
    }
    cout << "No data of member with that ID";
    return temp;
}

void System::displayMemberInformation(const string &ID) {
    // Loop through each showMemberScreen

    for (Member &member: getMemberList()) {
        // If the ID doesn't match, exit the loop
        if (!(ID == member.getMemberID())) {
            cout << "showMemberScreen not found";
            return;
        }
        // Display showMemberScreen information
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

void System::addNewRating(string ratingID, string memberID, string hostID,
                          double skillRating, double supporterRating,
                          double hostRating, string comments) {
    Rating rating(ratingID, memberID, hostID, skillRating, supporterRating,
                  hostRating, comments);
    ratingList.push_back(rating);
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

    // Already being set when default constructor
    // newMember.setAvailableStatus(false);
    // newMember.setHostMember()
    // newMember.setSupporterMember()

    memberList.push_back(newMember);
    memberFileWriter();
}

void System::addNewSkill(const string &newSkill, const string &memberID) {
    Member temp = getMemberObject(memberID);

    int tempSkill = checkIfInputIsInteger(newSkill);
    if (!tempSkill) {
        cout << "fuck you";
        return;
    }

    for (auto it = skillStrings.begin(); it != skillStrings.end(); it++) {
        if (tempSkill == (it - skillStrings.begin())) {
            temp.addSkill(new string(*it));
        }
    }
}
