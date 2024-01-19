//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/System.h"

const string EMPTY;
static Member nullMember;
enum Status {
    UNAVAILABLE, AVAILABLE
};

const vector<string> skillStrings = {
        "Unknown skill", "Car Mechanic",
        "Teaching", "Tutoring",
        "Plumbing Repair", "Writing",
        "Photography", "Cooking",
        "Gardening", "House Cleaning",
        "Laundry", "Sewing",
        "First Aid", "Time Management",
        "Public Speaking", "Basic Computer Skills",
        "Money Management", "Communication",
        "Problem Solving", "Teamwork",
        "Stress Management"};

// static vector<Rating> ratingList;
// vector<Rating> System::getRatingList() { return ratingList; }

// Default constructor
System::System() = default;

System &System::getInstance() {
    static System System;
    return System;
}

// parse the time in csv and return
tm System::parseCSVTime(const std::string &timeStr) {
    tm timeStruct = {};
    istringstream iss(timeStr);
    iss >> std::get_time(&timeStruct, "%Y-%m-%d %H:%M");
    return timeStruct;
}

void System::clearTerminal() {
#ifdef _WIN32
    // For Windows
    std::system("cls");
#elif __APPLE__
    // For macOS
    std::system("clear");
#else
    // For other platforms (assuming UNIX-like behavior)
    std::system("clear");
#endif
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
        string credit;

        string skillRating;
        string supporterRating;
        string hostRating;
        string totalRating;

        string status;
        string hostID;
        string supporterID;

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
        getline(iss, status, ',');
        getline(iss, hostID, ',');
        getline(iss, supporterID, ',');
        getline(iss, credit, ',');
        getline(iss, totalRating, ',');
        getline(iss, skillRating, ',');
        getline(iss, hostRating, ',');
        getline(iss, supporterRating, ',');
        getline(iss, skills, ',');

        stringstream getSkill(skills);
        string skill;
        while (getline(getSkill, skill, '-')) {
            newSkillsList.push_back(new string(skill));
        }

        member.setFullName(fullname);
        member.setEmail(email);
        member.setHomeAddress(address);
        member.setPhoneNumber(phoneNumber);
        member.setUsername(username);
        member.setPassword(password);
        member.setMemberID(ID);
        member.setTotalRating(std::stod(totalRating));
        member.setSkillRating(std::stod(skillRating));
        member.setSupporterRating(std::stod(supporterRating));
        member.setHostRating(std::stod(hostRating));
        member.setHostMember(hostID);
        member.setSupporterMember(supporterID);
        member.setAvailableStatus(stoi(status));
        member.setCreditPoints(stoi(credit));
        member.setSkillInfo(newSkillsList);

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

        rating.setRatingID(ratingID);
        rating.setMemberID(memberID);
        rating.setHostID(hostID);
        rating.setSkillRating(std::stod(skillRating));
        rating.setHostRating(std::stod(hostRating));
        rating.setSupporterRating(std::stod(supporterRating));
        rating.setComments(comments);

        ratingList.push_back(rating);
    }
    file.close();
}

void System::bookingFileReader() {
    // Check if file exist
    ifstream file(BOOKING_PATH);
    if (!file.is_open()) {
        cerr << "Error opening file " << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        string bookingID;
        string hostMemberID;
        string supporterMemberID;
        string rentingTime;
        string creationTime;
        string startTime;

        string status;
        Booking request;

        istringstream iss(line);
        getline(iss, bookingID, ',');
        getline(iss, hostMemberID, ',');
        getline(iss, supporterMemberID, ',');

        getline(iss, status, ',');
        getline(iss, rentingTime, ',');

        getline(iss, creationTime, ',');
        getline(iss, startTime, ',');


        request.setCreationTime(parseCSVTime(creationTime));
        request.setStartTime(parseCSVTime(startTime));
        request.setBookingID(bookingID);
        request.setTimeRenting(std::stod(rentingTime));
        request.setHostMemberID(hostMemberID);
        request.setSupporterMemberID(supporterMemberID);
        request.setStatus(status);

        bookingList.push_back(request);
    }
    file.close();
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
        string skillList1;
        for (auto &skill: members.getSkillInfo()) {
            skillList1 += *skill;
            if (skill != members.getSkillInfo().back()) {
                skillList1 += "-";
            }
        }

        file << members.getFullName() << "," << members.getEmail()
             << "," << members.getHomeAddress() << "," << members.getPhoneNumber()
             << "," << members.getUsername() << "," << members.getPassword()
             << "," << members.getMemberID() << "," << members.getMemberAvailableStatus()
             << "," << members.getHostMember() << "," << members.getSupporterMember()
             << "," << members.getCreditPoints() << "," << members.getTotalRating()
             << "," << members.getSkillRating() << "," << members.getHostRating()
             << "," << members.getSupporterRating() << "," << skillList1 << endl;
    }

    // add member available status
    file.close();
}

void System::ratingFileWriter() {
    // Open file
    ofstream file(RATING_PATH);
    if (!file.is_open()) {  // Check if file opened successfully
        cerr << "Error opening file rating data in rating writer" << endl;
        return;
    }

    for (const auto &rating: ratingList) {
        file << rating.getRatingID() << "," << rating.getHostID()
             << "," << rating.getMemberID() << "," << rating.getSkillRating()
             << "," << rating.getSupporterRating() << "," << rating.getHostRating()
             << "," << rating.getComments() << endl;
    }

    file.close();
}

void System::bookingFileWriter() {
    // Open file
    ofstream file(BOOKING_PATH);
    if (!file.is_open()) {  // Check if file opened successfully
        cerr << "Error opening file request data in request writer" << endl;
        return;
    }

    for (const auto &booking: bookingList) {
        file << booking.getBookingID() << "," << booking.getHostMemberID()
             << "," << booking.getSupporterMemberID() << "," << booking.getStatus()
             << "," << booking.getTimeRenting()
             << "," << booking.getFormattedCreationTime()
             << "," << booking.getFormattedStartRentingTime() << endl;
    }
    // add member available status
    file.close();
}

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

string System::getIDWithUsernamePassword(const string &username, const string &password) {
    for (auto &member: memberList) {
        if (username == member.getUsername() && password == member.getPassword()) {
            return member.getMemberID();
        }
    }
    return EMPTY;
}

Member &System::getMemberObject(const string &ID) {
    for (Member &mem: getMemberList()) {
        if (mem.getMemberID() == ID) {
            return mem;
        }
    }
    cout << "No data of member with that ID";
    return nullMember;
}

void System::displayMemberInformation(const string &ID) {
    // Loop through each showMemberScreen

    for (auto &member: memberList) {
        // If the ID doesn't match, exit the loop
        if (ID == member.getMemberID()) {
            member.showInfo();
            return;
        }
        // Display showMemberScreen information
    }
    cout << "Member not found";
}

int System::checkIfInputIsInteger(const string &input) {
    try {
        return stoi(input);
    } catch (std::invalid_argument &) {
        return -1;
    }
}

void System::addNewRating(string &memberID, string &hostID,
                          double skillRating, double supporterRating,
                          double hostRating, string &comments) {
    Rating rating(generateRatingID(), memberID, hostID, skillRating, supporterRating,
                  hostRating, comments);
    ratingList.push_back(rating);
}

void System::addNewBooking(string hostMemberID,
                           string supporterMemberID, string status, double timeRenting,
                           tm startTime) {
    Booking booking;
    booking.setBookingID(generateBookingID());
    booking.setHostMemberID(hostMemberID);
    booking.setSupporterMemberID(supporterMemberID);
    booking.setStatus(status);
    booking.setTimeRenting(timeRenting);
    booking.setStartTime(startTime);

    bookingList.push_back(booking);
}

string System::generateMemberID() {
    int memberID = 300000;  // default ID value
    char IDSuffix = 'S';    // suffix of ID

    int totalMemberAmount = (int) memberList.size(); // type cast unsigned long into int


    int currentID = memberID + totalMemberAmount;

    return IDSuffix + std::to_string(currentID);
}

string System::generateRatingID() {

    int ratingID = 0;  // default ID value
    string IDSuffix = "RA";    // suffix of ID
    int totalRatingAmount = (int) ratingList.size(); // type cast unsigned long into int


    int currentID = ratingID + totalRatingAmount;

    return IDSuffix + std::to_string(currentID);
}


string System::generateBookingID() {
    int bookingID = 0;  // default ID value
    string IDSuffix = "B";  // suffix of ID
    int totalRequestAmount = (int) bookingList.size();


    int currentID = bookingID + totalRequestAmount;

    return IDSuffix + std::to_string(currentID);
}

void System::registerNewMember(const string &fullName, const string &email,
                               const string &homeAddress, const string &phoneNumber,
                               const string &username, const string &password) {
    Member newMember;
    newMember.setFullName(fullName);
    newMember.setEmail(email);
    newMember.setHomeAddress(homeAddress);
    newMember.setPhoneNumber(phoneNumber);
    newMember.setUsername(username);
    newMember.setPassword(password);

    newMember.setMemberID(generateMemberID());

    memberList.push_back(newMember);
    memberFileWriter();
}

void System::addNewSkill(int &newSkill, const string &memberID) {

    Member &temp = getMemberObject(memberID);

    for (auto &it2: temp.getSkillInfo()) {
        if (skillStrings[newSkill] == *it2) {
            cout << "You have this already" << endl;
            return;
        }
    }

    int idx = 0;
    for (auto it = skillStrings.begin(); it != skillStrings.end(); it++, idx++) {
        if (newSkill == idx) {
            temp.addSkill(new string(*it));
            cout << "Skill added" << endl;
        }
    }
    memberFileWriter();
}

void System::removeSkill(int &removeSkill, const string &memberID) {
    Member &temp = getMemberObject(memberID);
    vector<string *> tempList = temp.getSkillInfo();

    int idx = 0;
    for (auto it = tempList.begin(); it != tempList.end();) {
        if (removeSkill - 1 == idx) {
            it = tempList.erase(it);
            temp.setSkillInfo(tempList);
            cout << "Skill removed" << endl;
        } else {
            ++it;
            ++idx;
        }
    }
    memberFileWriter();
}

bool System::topUpCredits(const string &memberID, int topUpAmount, const string &passwordInput) {
    for (Member &member: memberList) {
        if (member.getMemberID() == memberID && member.getPassword() == passwordInput) {
            member.setCreditPoints(member.getCreditPoints() + topUpAmount);
            return true;
        }
    }
    return false;
}

double System::calculateSupporterRating(const string &supporterID, int &newRating) {
    double finalRating = newRating;
    double temp = 0;
    int idxToDivide = 1;

    for (auto &it: ratingList) {
        if (supporterID == it.getMemberID()) {
            temp += it.getSupporterRating();
            idxToDivide++;
        }
    }

    finalRating = (temp + finalRating) / idxToDivide;
    return finalRating;
}

double System::calculateSupporterSkillRating(const string &supporterID, int &newRating) {
    double finalRating = newRating;
    double temp = 0;
    int idxToDivide = 1;

    for (auto &it: ratingList) {
        if (supporterID == it.getMemberID()) {
            temp += it.getSkillRating();
            idxToDivide++;
        }
    }

    finalRating = (temp + finalRating) / idxToDivide;
    return finalRating;
}


double System::calculateHostRating(const string &hostID, int &newRating) {
    double finalRating = newRating;
    double temp = 0;
    int idxToDivide = 1;

    for (auto &it: ratingList) {
        if (hostID == it.getHostID()) {
            temp += it.getSupporterRating();
            idxToDivide++;
        }
    }

    finalRating = (temp + finalRating) / idxToDivide;
    return finalRating;
}

double System::calculateTotalRating(const string &ID) {
    double finalRating = 0;
    double temp = 0;
    int idxToDivide = 4;

    for (auto &it: memberList) {
        if (ID == it.getMemberID()) {
            temp += it.getSkillRating() + it.getHostRating() + it.getSupporterRating();
        }
    }

    finalRating = (temp + finalRating) / idxToDivide;
    return finalRating;
}
