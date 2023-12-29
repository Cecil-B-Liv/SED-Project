//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/Event.h"
#include "../Header files/BasicSTDLIB.h"
#include "../Header files/System.h"
#include "../Header files/UI.h"

#define LOGIN 1
#define REGISTER 2
#define MEMBERINFO 3

bool InputChecker(const string &input) {
    try {
        std::stoi(input);
        return true;
    } catch (std::invalid_argument &) {
        return false;
    }
}

void Event::StartScreen() {
    string input;
    int check;

    cout << "What do you want" << endl;
    cout << "1. Login\n2. Register" << endl;
    cout << ">>> ";

    cin >> input;

    // Check if user's input is only number
    if (!InputChecker(input)) {
        cout << "Not an option" << endl;
        UI::Start();
    }

    check = std::stoi(input);

    switch (check) {
        case LOGIN:
            UI::Login();
        case REGISTER:
            UI::Register();
        default:
            cout << "Not an option" << endl;
            UI::Start();
    }
}

void Event::LoginScreen() {
    string username;
    string password;

    cout << "Enter your username: ";
    getline(cin >> std::ws, username);

    cout << "Enter your password: ";
    getline(cin >> std::ws, password);

    System::UserReader();

    for (auto i: System::getMemberList()) {
        if (!(username == i.getUsername() && password == i.getPassword())) {
            cout << "Wrong username or password" << endl;
            UI::Login();
        }
        cout << "welcome";
        Event::MemberScreen();
    }
}

void Event::RegisterScreen() {
    string username;
    string password;

    cout << "Enter your username: ";
    getline(cin >> std::ws, username);

    cout << "Enter your password: ";
    getline(cin >> std::ws, password);
}

void Event::MemberScreen() {
    string input;
    int check;

    cout << "What do you want" << endl;
    cout << "1. View Info" << endl;
    cout << ">>> ";

    cin >> input;

    // Check if user's input is only number
    if (!InputChecker(input)) {
        cout << "Not an option" << endl;
        UI::Member();
    }

    check = std::stoi(input);

    switch (check) {
        case MEMBERINFO:
            UI::Login();
        default:
            cout << "Not an option" << endl;
            UI::Start();
    }
}
