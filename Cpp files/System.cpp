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

    // Check if file exist
    ifstream file("../Database/MemberData.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file " << std::endl;
        return;
    }

    // Read each line and split ","
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::getline(iss, username, ',');
        std::getline(iss, password, ',');
    }
    Member test;
    test.setPassword(password);
    test.setUsername(username);

    MemberList.push_back(test);
    file.close();
}

void System::UserWriter() {
    string username;
    string password;

    ifstream file("../Database/MemberData.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file " << std::endl;
        return;
    }

    for (Member member: MemberList) {

    }
}


