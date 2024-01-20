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
    // start the intialize that run all of the reader file to get data for the
    // program start the home screen
    static void start() {
        Event::initialize();
        Event::startScreen();
    }

    static void end() { Event::endScreen(); }

    static void showGuestScreen() { Event::guestScreen(); }

    static void showMemberScreen(const string &ID = "") {
        Event::memberScreen(ID);
    }

    static void showAdminScreen() { Event::adminScreen(); }

    static void showMemberInformationScreen(const string &ID = "") {
        Event::getMemberInfoScreen(ID);
    }

    static void showAllSupporterInformationScreen() {
        Event::getAllSupporterInformationScreen();
    }

    static void showAllRatingScreen() {
        Event::showAllRatingList();
    }

    static void showAllBookingScreen() {
        Event::showAllBookingList();
    }

    static void bookSupporter(const string &ID) { Event::bookSupporter(ID); }

    static void resetMemberPwdScreen() { Event::resetMemberPwd(); };

    static void showRegisterLoginScreen() { Event::registerLoginScreen(); }

    static void showLoginScreen() { Event::loginScreen(); }

    static void showRegisterScreen() { Event::registerScreen(); }

    static void showPendingBooking() { Event::PendingScreen(); }

    static void showAddSKill() { Event::addSkill(); }

    static void showRemoveSkill() { Event::removeSkill(); }

    static void showBookingStatus() { Event::bookingStatus(); }

    static void showCompleteBooking() { Event::completeBookingForHost(); }

    static void showCompleteBookingForSupporter() { Event::completeBookingForSupporter(); }

    static void showTopUpScreen(const string &memberID) { Event::topUpScreen(memberID); }

    static void showBlockScreen() { Event::blockUserScreen(); }

    static void showUnBlockScreen() { Event::unBlockUserScreen(); }

};

#endif  // SED_PROJECT_UI_H
