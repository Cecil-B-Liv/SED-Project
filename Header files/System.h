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

    static vector<Member> getMemberList();
};

#endif //SED_PROJECT_SYSTEM_H
