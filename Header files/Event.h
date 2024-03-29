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

    static void endScreen();

    static void getMemberInfoScreen(const string &);

     static void getMemberFullInfoScreen(const string &);

    static void getAllSupporterInformationScreen();

    static void showAllRatingList();

    static void showAllBookingList();

    static void guestScreen();

    static void memberScreen(const string &);

    static void adminScreen();

    static void registerLoginScreen();

    static void loginScreen();

    static void resetMemberPwd();

    static void bookSupporter(const string &);

    static void registerScreen();

    static void topUpScreen(const string &);

    static void showAllMemberInfo();
    // static void
    static void PendingScreen();

    static void addSkill();

    static void removeSkill();

    static void bookingStatus();

    static void completeBookingForHost();

    static void completeBookingForSupporter();

    static void blockUserScreen();

    static void unBlockUserScreen();

    static void membersBookingScreen(const string &memberID);
};

#endif  // SED_PROJECT_EVENT_H
