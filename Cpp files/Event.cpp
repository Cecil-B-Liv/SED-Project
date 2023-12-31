//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/Event.h"
#include "../Header files/System.h"
#include "../Header files/UI.h"

#define GUEST 1
#define MEMBER 2
#define ADMIN 3

#define LOGIN 1
#define REGISTER 2

#define MEMBERINFO 1
#define MEMBERSKILLRATING 2

void Event::StartScreen() {
    string input;

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

    int checkedUserInput = System::userInputCheck(input);

    // Check if user's input is only number
    if (checkedUserInput == -1) {
        cout << "Not an option" << endl;
        UI::Start();
        return;
    }

    switch (checkedUserInput) {
        case GUEST:
        case MEMBER:
            UI::RegisterLogin(MEMBER);
            return;
        case ADMIN:
            UI::RegisterLogin(ADMIN);
            return;
        default:
            cout << "Not an option" << endl;
            UI::Start();
            return;
    }
}

void Event::MemberScreen(const string &ID) {
    string input;

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
    int checkedUserInput = System::userInputCheck(input);

    // Check if user's input is only number
    if (checkedUserInput == -1) {
        cout << "Not an option" << endl;
        UI::Start();
        return;
    }

    switch (checkedUserInput) {
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

void Event::RegisterLoginScreen(int choice) {
    string givenChoice;
    string username;
    string password;

    if (choice == ADMIN) {
        return;
    }

    if (choice == MEMBER) {
        cout << "1. Log in 2. Register" << endl;
        cout << ">>> ";
        cin >> givenChoice;
    }

    int checkedUserInput = System::userInputCheck(givenChoice);

    // Check if user's input is only number
    if (checkedUserInput == -1) {
        cout << "Not an option" << endl;
        UI::RegisterLogin(choice);
        return;
    }

    cout << "Enter your username: ";
    getline(cin >> std::ws, username);

    cout << "Enter your password: ";
    getline(cin >> std::ws, password);

    switch (checkedUserInput) {
        case LOGIN:
            if (System::loginCheck(username, password).empty()) {
                cout << "Wrong username or password" << endl;
                UI::RegisterLogin(choice);
                return;
            }
            cout << "welcome";
            UI::Member(System::loginCheck(username, password));
            return;
        case REGISTER:
            cout << "User already exist";
            return;
        default:
            return;
    }
}
