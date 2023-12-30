//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_EVENT_H
#define SED_PROJECT_EVENT_H

#include "BasicSTDLIB.h"

class Event {
public:
    static void LoginScreen();

    static void StartScreen();

    static void RegisterScreen();

    static void InformationScreen(const string &ID);

    static void MemberScreen(const string &ID);
};

#endif //SED_PROJECT_EVENT_H
