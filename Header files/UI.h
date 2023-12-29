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

    static void Login() { Event::LoginScreen(); }

    static void Register() { Event::RegisterScreen(); }

    static void Member(string ID = "") { Event::MemberScreen(ID); }

//    static void Information(int position = 0, int ID = 0) { Event::InformationScreen(ID, position); }
};

#endif //SED_PROJECT_UI_H
