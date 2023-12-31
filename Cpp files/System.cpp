//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/BasicSTDLIB.h"
#include "../Header files/Member.h"
#include "../Header files/System.h"

#define EMPTY ""

static vector<Member> MemberList;

vector<Member> System::getMemberList() {
    return MemberList;
}

void System::userReader() {
    string username;
    string password;
    string ID;

    // Check if file exist
    ifstream file("../Database/MemberData.txt");
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

    ifstream file("../Database/MemberData.txt");
    if (!file.is_open()) {
        cerr << "Error opening file " << endl;
        return;
    }

    for (Member member: MemberList) {

    }
}

string System::loginCheck(const string &username, const string &password) {
    userReader();
    string memberID;

    for (Member member: getMemberList()) {
        if (!(username == member.getUsername() && password == member.getPassword())) {
            return EMPTY;
        }
        memberID = member.getMemberID();
    }
    return memberID;
}

void System::getMemberInformation(const string &ID) {
    userReader();

    for (const Member &member: getMemberList()) {
        if (!(ID == member.getMemberID())) {
            return;
        }
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

