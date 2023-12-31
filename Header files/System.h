//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_SYSTEM_H
#define SED_PROJECT_SYSTEM_H

#include "BasicSTDLIB.h"
#include "Member.h"

class System {
public:

    static void userReader();

    static void userWriter();

    static string loginCheck(const string &, const string &);

    static vector<Member> getMemberList();

    static void getMemberInformation(const string &);

    static int userInputCheck(const string &);
};

#endif //SED_PROJECT_SYSTEM_H
