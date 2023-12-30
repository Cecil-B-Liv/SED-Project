//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/Event.h"
#include "../Header files/System.h"
#include "../Header files/UI.h"

#define GUEST 1
#define LOGIN 2
#define REGISTER 3
#define MEMBERINFO 1
#define MEMBERSKILLRATING 2

bool InputChecker(const string &input) {
    try {
        stoi(input);
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

    cout << "Use the app as: 1. Guest 2. Member 3. Admin" << endl;
    cout << "Exit the app: e or E" << endl;
    cout << ">>> ";

    cin >> input;

    if (input == "e") {
        return;
    }

    // Check if user's input is only number
    if (!InputChecker(input)) {
        cout << "Not an option" << endl;
        UI::Start();
        return;
    }

    check = stoi(input);

    switch (check) {
        case GUEST:
        case LOGIN:
            UI::Login();
            return;
        case REGISTER:
            UI::Register();
            return;
        default:
            cout << "Not an option" << endl;
            UI::Start();
            return;
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

    if (System::LoginCheck(username, password) == "false") {
        cout << "Wrong username or password" << endl;
        UI::Login();
        return;
    }

    cout << "welcome";
    ID = System::LoginCheck(username, password);
    UI::Member(ID);
}

void Event::RegisterScreen() {
    string username;
    string password;

    cout << "Enter your username: ";
    getline(cin >> std::ws, username);

    cout << "Enter your password: ";
    getline(cin >> std::ws, password);
}

void Event::MemberScreen(const string &ID) {
    string input;
    int check;

    cout << ID << endl << endl;

    cout << "What do you want" << endl;
    cout << "1. View Info" << endl;
    cout << "Exit the app: e or E" << endl;
    cout << ">>> ";

    cin >> input;

    if (input == "e") {
        return;
    }

    // Check if user's input is only number
    if (!InputChecker(input)) {
        cout << "Not an option" << endl;
        UI::Member(ID);
        return;
    }

    check = stoi(input);

    switch (check) {
        case MEMBERINFO:
            UI::Information(ID);
            return;
        case MEMBERSKILLRATING:
        default:
            cout << "Not an option" << endl;
            UI::Start();
            return;
    }
}

void Event::InformationScreen(const string &ID) {
    System::getMemberInformation(ID);
}

