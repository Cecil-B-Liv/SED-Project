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

//    static void InformationScreen(int, int);

//    static void MemberScreen(string);

    static void MemberScreen(string ID);
};

#endif //SED_PROJECT_EVENT_H
