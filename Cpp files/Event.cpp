//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/INCLUDEHEADERS.h"

#define GUEST 1
#define MEMBER 2
#define ADMIN 3


#define LOGIN 1
#define REGISTER 2

#define MEMBERINFO 1
#define MEMBERSKILLRATING 2

void Event::StartScreen() {
    System &system = System::getInstance();
    string input;

    // Welcome Message
    cout << "EEET2482/COSC2082 ASSIGNMENT" << endl;
    cout << "“TIME BANK” APPLICATION" << endl << endl;
    cout << "Instructor: Mr. Tran Duc Linh" << endl;
    cout << "Group: Group No." << endl;

    while (true) {
        // Prompt User to Choose Role
        cout << "Use the app as: 1. Guest 2. Member 3. Admin" << endl;
        cout << "Exit the app: e or E" << endl;
        cout << ">>> ";

        // Get User Input
        cin >> input;

        // Check for Exit Condition
        if (input == "e") {
            // Close Application
            return;
        }

        // Check if user's input is only number

        switch (system.memberInputCheck(input)) {
            case GUEST:
            case MEMBER:
            case ADMIN:
                UI::RegisterLogin(system.memberInputCheck(input));
                return;
        }
        cout << "Not an option" << endl;
    }
}

void Event::MemberScreen(const string &ID) {
    System &system = System::getInstance();
    string input;

    cout << ID << endl << endl;

    while (true) {
        cout << "What do you want" << endl;
        cout << "1. View Info" << endl;
        cout << "Exit the app: e or E" << endl;
        cout << ">>> ";

        cin >> input;

        if (input == "e") {
            return;
        }

        // Check if user's input is only number
        if (system.memberInputCheck(input) != -1) {
            switch (system.memberInputCheck(input)) {
                case MEMBERINFO:
                    UI::Information(ID);
                    return;
                case MEMBERSKILLRATING:
                    return;
            }
        }
        cout << "Not an option" << endl;
    }
}

void Event::InformationScreen(const string &ID) {
    System &system = System::getInstance();
    system.getMemberInformation(ID);
}

void Event::RegisterLoginScreen(int choice) {
    System &system = System::getInstance();
    string givenChoice;
    string username;
    string password;

    if (choice == ADMIN) {
        return;
    }

    // Other than admin was chosen
    while (true) {
        cout << "1. Log in 2. Register" << endl;
        cout << ">>> ";

        cin >> givenChoice;

        // Check if user's input is only number


        if (system.memberInputCheck(givenChoice) == LOGIN) {
            break;
        }
        cout << "Not an option" << endl;
    }

    while (true) {
        cout << "Enter your username: ";
        getline(cin >> std::ws, username);

        cout << "Enter your password: ";
        getline(cin >> std::ws, password);

        if (!(system.loginCheck(username, password).empty())) {
            cout << "welcome";
            UI::Member(system.loginCheck(username, password));
            return;
        }
        cout << "Wrong username or password" << endl;
    }
}
