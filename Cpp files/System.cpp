//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/BasicSTDLIB.h"
#include "../Header files/Member.h"
#include "../Header files/System.h"

static vector<Member> MemberList;

void System::UserReader() {
    string username;
    string password;

    ifstream file("../Database/MemberData.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file " << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::getline(iss, username, ',');
        std::getline(iss, password, ',');
    }
    Member test;
    test.setPassword(password);
    test.setUserName(username);

    MemberList.push_back(test);
    file.close();
}

vector<Member> System::getMemberList() {
    return MemberList;
}
