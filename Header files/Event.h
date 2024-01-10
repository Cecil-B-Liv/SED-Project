//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_EVENT_H
#define SED_PROJECT_EVENT_H

#include "BasicSTDLIB.h"

class Event {
   public:
    static void initialize();

    static void startScreen();

    static void getMemberInfoScreen(const string &);

    static void guestScreen();
    static void memberScreen(const string &);
    static void adminScreen();

    static void registerLoginScreen();
    static void loginScreen();
    static void resetMemberPwd();

    static void registerScreen();

    // static void
};

#endif  // SED_PROJECT_EVENT_H
