//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/INCLUDEHEADERS.h"

#define EMPTY ""

static vector<Member> MemberList;
static vector<Transaction> TransactionList;
vector<Member> System::getMemberList() { return MemberList; }
vector<Transaction> getTransactionList() { return TransactionList; }

// static vector<Rating> RatingList;
// vector<Rating> System::getRatingList() { return RatingList; }

// static vector<Rating> RatingList;
// vector<Rating> System::getRatingList() { return RatingList; }

void System::userReader() {
    string username;
    string password;
    string ID;

    // Check if file exist
    ifstream file("../Database/MemberData.csv");
    if (!file.is_open()) {
        cerr << "Error opening file " << endl;
        return;
    }

    // Read each line and split ","
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        getline(iss, username, ',');
        getline(iss, password, ',');
        getline(iss, ID, ',');
    }
    Member test;
    test.setPassword(password);
    test.setUsername(username);
    test.setMemberID(ID);

    test.setFullName("Huynh Ngoc Tai");
    test.setEmail("lmao@gay.com");
    test.setHomeAddress("League of Legend");

    vector<string> skillList = {"lmao1", "lmao2", "lmao3"};
    test.setSkillInfo(skillList);

    MemberList.clear();
    MemberList.push_back(test);
    file.close();
}


void System::userWriter() {

    string username;
    string password;
    // Open file
    ifstream file("../Database/MemberData.csv");
    if (!file.is_open()) {  // Check if file opened successfully
        cerr << "Error opening file " << endl;
        return;
    }
    for (Member member : MemberList) {
    }
}


string System::loginCheck(const string &username, const string &password) {
    userReader();
    string memberID;

    for (Member member: getMemberList()) {
        if (!(username == member.getUsername() && password == member.getPassword())) {
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
    userReader();

    // Loop through each member
    for (const Member &member : getMemberList()) {
        // If the ID doesn't match, exit the loop
        if (!(ID == member.getMemberID())) {
            cout << "Member not found";
            return;
        }
        // Display member information
        member.showInfo();
    }
}


int System::userInputCheck(const string &input) {
    try {
        return stoi(input);
    } catch (std::invalid_argument &) {
        return -1;
    }
}


