//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_SYSTEM_H
#define SED_PROJECT_SYSTEM_H

#include "BasicSTDLIB.h"
#include "Member.h"

class System {
public:

    static void UserReader();

    static void UserWriter();

    static string LoginCheck(const string &, const string &);

    static vector<Member> getMemberList();

    static void getMemberInformation(const string &);
};

#endif //SED_PROJECT_SYSTEM_H
