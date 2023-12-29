//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/Event.h"
#include "../Header files/BasicSTDLIB.h"
#include "../Header files/System.h"
#include "../Header files/UI.h"

#define LOGIN '1'
#define REGISTER '2'

void Event::Menu() {
    char input;

    cout << "What do you want" << endl;
    cout << "1. Login\n2. Register" << endl;
    cout << "Choice: ";

    cin >> input;

    if (!isdigit(input)) {
        cout << "Not an option" << endl;
        UI::Start();
    }

    switch (input) {
        case LOGIN:
            UI::Login();
            break;
        case REGISTER:
            UI::Register();
            break;
        default:
            cout << "Not an option" << endl;
            UI::Start();
            break;
    }

//    if (choice == LOGIN) {
//        UI::Login();
//        return;
//    }
//
//    if (choice == REGISTER) {
//        UI::Register();
//        return;
//    }
}

void Event::Login() {
    string username;
    string password;

    cout << "Enter your username: ";
    getline(cin >> std::ws, username);

    cout << "Enter your password: ";
    getline(cin >> std::ws, password);

    System::UserReader();

    for (auto i: System::getMemberList()) {
        if (username == i.getUsername() && password == i.getPassword())
            cout << "welcome";
    }
}

void Event::Register() {
    string username;
    string password;

    cout << "Enter your username: ";
    getline(cin >> std::ws, username);

    cout << "Enter your password: ";
    getline(cin >> std::ws, password);
}

