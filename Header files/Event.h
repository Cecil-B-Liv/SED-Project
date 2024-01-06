//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_EVENT_H
#define SED_PROJECT_EVENT_H

#include "BasicSTDLIB.h"

class Event {
public:
    static void StartScreen();

    static void InformationScreen(const string &);

    static void MemberScreen(const string &);

    static void RegisterLoginScreen(int);

    static void LoginScreen();

    static void RegisterScreen();

    static void Initialize();
};

#endif //SED_PROJECT_EVENT_H
