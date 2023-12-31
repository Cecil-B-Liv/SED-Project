//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/INCLUDEHEADERS.h"

#define GUEST 1
#define LOGIN 2
#define REGISTER 3
#define MEMBERINFO 1
#define MEMBERSKILLRATING 2

bool InputChecker(const string &input) {
    // Check if user's input is only number
    try {
        stoi(input);
        return true;
    } catch (std::invalid_argument &) {
        return false;
    }
}

// Event Start Screen
void Event::StartScreen() {
    string input;
    int check;

    // Welcome Message
    cout << "EEET2482/COSC2082 ASSIGNMENT" << endl;
    cout << "“TIME BANK” APPLICATION" << endl << endl;
    cout << "Instructor: Mr. Tran Duc Linh" << endl;
    cout << "Group: Group No." << endl;

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

    // Check if User Input is Valid
    if (InputChecker(input)) {
        // Store User Input as Integer
        check = stoi(input);

        // Switch Based on User Input
        switch (check) {
            case GUEST:
                // Process as Guest
                break;
            case LOGIN:
                // Process as Member
                break;
            case REGISTER:
                // Process as Admin
                break;
            default:
                // Invalid Input
                break;
        }
    } else {
        // Invalid Input (Non-numeric)
    }
}

void Event::LoginScreen() {
    string username;
    string password;
    int attempts;
    //int position;
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

    cout << "Welcome";
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