//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/INCLUDEHEADERS.h"

static vector<Member> MemberList;
vector<Member> System::getMemberList() { return MemberList; }
//call to prevent undefined static variable
// Returns a copy of the MemberList

void System::MemberReader() {
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

    MemberList.clear();
    MemberList.push_back(test);
    file.close();
}

void System::MemberWriter() {
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

// static vector<Rating> RatingList;
// vector<Rating> System::getRatingList() { return RatingList; }

// static vector<Rating> RatingList;
// vector<Rating> System::getRatingList() { return RatingList; }

string System::LoginCheck(const string &username, const string &password) {
    // Call the user reader function
    MemberReader();
    // Variable to store the member ID
    string memberID;

    // Iterate through the member list
    for (Member member : getMemberList()) {
        // Check if the entered username and password match any member in the
        // list
        if (!(username == member.getUsername() &&
              password == member.getPassword())) {
            return "false";  // If not, return "false"
        }
        // If found, store the member ID and break the loop
        memberID = member.getMemberID();
        break;
    }
    // Return the member ID
    return memberID;
}

void System::getMemberInformation(const string &ID) {
    // Create user reader
    MemberReader();

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
