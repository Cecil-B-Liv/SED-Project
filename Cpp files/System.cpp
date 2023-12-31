//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/BasicSTDLIB.h"
#include "../Header files/Member.h"
#include "../Header files/System.h"

static vector<Member> MemberList;

vector<Member> System::getMemberList() {
    return MemberList;
}

void System::UserReader() {
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

void System::UserWriter() {
    string username;
    string password;

    ifstream file("../Database/MemberData.csv");
    if (!file.is_open()) {
        cerr << "Error opening file " << endl;
        return;
    }

    for (Member member: MemberList) {

    }
}

string System::LoginCheck(const string &username, const string &password) {
    UserReader();
    string memberID;

    for (Member member: getMemberList()) {
        if (!(username == member.getUsername() && password == member.getPassword())) {
            return "false";
        }
        memberID = member.getMemberID();
    }
    return memberID;
}

void System::getMemberInformation(const string &ID) {
    UserReader();

    for (const Member &member: getMemberList()) {
        if (!(ID == member.getMemberID())) {
            return;
        }
        member.showInfo();
    }
}

