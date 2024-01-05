//
// Created by Nick Anderson on 28/12/2023.
//

#ifndef SED_PROJECT_UI_H
#define SED_PROJECT_UI_H

#include <utility>

#include "BasicSTDLIB.h"
#include "Event.h"

class UI {
public:
    static void Start() { Event::StartScreen(); }

    static void Member(const string &ID = "") { Event::MemberScreen(ID); }

    static void Information(const string &ID = "") { Event::InformationScreen(ID); }

    static void RegisterLogin(int choice) { Event::RegisterLoginScreen(choice); }

    static void Login() { Event::LoginScreen(); }

    static void Register() { Event::RegisterScreen(); }
};

#endif //SED_PROJECT_UI_H
