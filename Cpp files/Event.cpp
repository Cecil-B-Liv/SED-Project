//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/Event.h"
#include "../Header files/BasicSTDLIB.h"
#include "../Header files/System.h"
#include "../Header files/UI.h"

#define GUEST 1
#define LOGIN 2
#define REGISTER 3
#define MEMBERINFO 1
#define MEMBERSKILLRATING 2

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

    cout << "EEET2482/COSC2082 ASSIGNMENT" << endl;
    cout << "“TIME BANK” APPLICATION" << endl << endl;
    cout << "Instructor: Mr. Tran Duc Linh" << endl;
    cout << "Group: Group No." << endl;

    cout << "Use the app as 1. Guest 2. Member 3. Admin" << endl;
    cout << ">>> ";

    cin >> input;

    // Check if user's input is only number
    if (!InputChecker(input)) {
        cout << "Not an option" << endl;
        UI::Start();
    }

    check = std::stoi(input);

    switch (check) {
        case GUEST:
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
    int attempts;
//    int position;
    string ID;

    cout << "Enter your username: ";
    getline(cin >> std::ws, username);

    cout << "Enter your password: ";
    getline(cin >> std::ws, password);

    System::UserReader();

    for (auto i: System::getMemberList()) {
        if (!(username == i.getUsername() && password == i.getPassword())) {
            cout << "Wrong username or password" << endl;
//            position = i.getPosition();
            UI::Login();
        }
        cout << "welcome";
        ID = i.getMemberID();
        UI::Member(ID);
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

void Event::MemberScreen(string ID) {
    string input;
    int check;

    cout << ID << endl << endl;

    cout << "What do you want" << endl;
    cout << "1. View Info" << endl;
    cout << ">>> ";

    cin >> input;

    // Check if user's input is only number
    if (!InputChecker(input)) {
        cout << "Not an option" << endl;
        UI::Member(ID);
    }

    check = std::stoi(input);

    switch (check) {
        case MEMBERINFO:
//            UI::Information(position, ID);
        case MEMBERSKILLRATING:

        default:
            cout << "Not an option" << endl;
            UI::Start();
    }
}

//void Event::InformationScreen(position, ID) {
//
//}

