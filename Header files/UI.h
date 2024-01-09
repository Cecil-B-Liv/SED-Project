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
    static void start() {
        Event::initialize();
        Event::startScreen();
    }

    static void showGuestScreen(){
        Event::guestScreen();
    }
    static void showMemberScreen(const string &ID = "") {
        Event::memberScreen(ID);
    }
    static void showAdminScreen(){
        Event::adminScreen();
    }

    static void showMemberInformationScreen(const string &ID = "") {
        Event::informationScreen(ID);
    }
    static void resetMemberPwdScreen(){
        Event::resetMemberPwd();
    };
    static void showRegisterLoginScreen() {
        Event::registerLoginScreen();
    }

    static void showLoginScreen() { Event::loginScreen(); }

    static void showRegisterScreen() { Event::registerScreen(); }
};

#endif  // SED_PROJECT_UI_H
