//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/INCLUDEHEADERS.h"
#include "../Header files/System.h"


#define EMPTY ""

// static vector<Rating> RatingList;
// vector<Rating> System::getRatingList() { return RatingList; }

// static vector<Rating> RatingList;
// vector<Rating> System::getRatingList() { return RatingList; }

static vector<Member> MemberList;


void System::memberReader() {
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

void System::memberWriter() {
    string username;
    string password;
    // Open file
    ifstream file("../Database/MemberData.csv");
    if (!file.is_open()) {  // Check if file opened successfully
        cerr << "Error opening file " << endl;
        return;
    }
    for (Member member: MemberList) {
    }
}

string System::loginCheck(const string &membername, const string &password) {
    memberReader();
    string memberID;

    for (Member member: getMemberList()) {
        if (!(membername == member.getUsername() &&
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
    memberReader();

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

int System::memberInputCheck(const string &input) {
    try {
        return stoi(input);
    } catch (std::invalid_argument &) {
        return -1;
    }
}

vector<Member> System::getMemberList() {
    return MemberList;
}

void System::addRating(string ratingID, string memberID, string hostID, double skillRating, double supporterRating,
                       double hostRating, string comments) {


}
