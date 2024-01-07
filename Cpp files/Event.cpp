//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/INCLUDEHEADERS.h"

#define GUEST 1
#define MEMBER 2
#define ADMIN 3

#define LOGIN 1
#define REGISTER 2

#define MEMBER_INFO 1
#define MEMBER_SKILL_RATING 2

System &systemInstance = System::getInstance();

// initialize all the reader and append to a vector for easy access
void Event::initialize() {
    systemInstance.memberFileReader();
    systemInstance.hostFileReader();
    systemInstance.ratingFileReader();
    systemInstance.requestFileReader();
    systemInstance.supporterFileReader();
}

void Event::startScreen() {
    string input;

    // Welcome Message
    cout << "EEET2482/COSC2082 ASSIGNMENT" << endl;
    cout << "“TIME BANK” APPLICATION" << endl << endl;
    cout << "Instructor: Mr. Tran Duc Linh" << endl;
    cout << "Group: Group No." << endl;

    while (true) {
        // Prompt User to Choose Role
        cout << "Use the app as: 1. Guest 2. Member 3. Admin" << endl;
        cout << "Exit the app: Press e" << endl;
        cout << ">>> ";

        // Get User Input
        cin >> input;

        // Check for Exit Condition
        if (input == "e") {
            // Close Application
            return;
        }

        // Check if user's input is only number
        switch (systemInstance.checkIfInputIsInteger(input)) {
            case GUEST:
                UI::showGuestScreen();
                return;
            case MEMBER:
                UI::showMemberScreen();
                return;
            case ADMIN:
                UI::showRegisterLoginScreen(
                    systemInstance.checkIfInputIsInteger(input));
                return;
            default:
                cout << "Not an option" << endl;
        }
    }
}

void Event::guestScreen() {
    string input;

    cout << "Detail of available Supporters: " << endl;
    for (Member supporter : systemInstance.getMemberList()) {
        supporter.showInfo();
        cout << ">>>>" << endl << endl;
    }

    while (true) {
        cout << "What do you want" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "Exit the app: e" << endl;
        cout << ">>> ";

        cin >> input;

        if (input == "e") {
            return;
        }

        // Check if user's input is only number
        switch (systemInstance.checkIfInputIsInteger(input)) {
            case LOGIN:
                UI::showLoginScreen();
                return;
            case REGISTER:
                UI::showRegisterScreen();
                return;
            default:
                cout << "Not an option" << endl;
        }
    }
}

void Event::memberScreen(const string &ID) {
    string input;

    cout << ID << endl;

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
        switch (systemInstance.checkIfInputIsInteger(input)) {
            case MEMBER_INFO:
                UI::showMemberInformationScreen(ID);
                return;
            case MEMBER_SKILL_RATING:
                return;
        }
        cout << "Not an option" << endl;
    }
}

void Event::informationScreen(const string &ID) {
    systemInstance.getMemberInformation(ID);
}

void Event::registerLoginScreen(int choice) {
    string givenChoice;

    if (choice == ADMIN) {
        return;
    }

    // Other than admin was chosen
    while (true) {
        cout << "1. Log in 2. showRegisterScreen" << endl;
        cout << ">>> ";

        cin >> givenChoice;

        // Check if user's input is only number

        switch (systemInstance.checkIfInputIsInteger(givenChoice)) {
            case LOGIN:
                UI::showLoginScreen();
                return;
            case REGISTER:
                UI::showRegisterScreen();
                return;
        }
        cout << "Not an option" << endl;
    }
}

void Event::loginScreen() {
    string username;
    string password;

    while (true) {
        cout << "Enter your username: ";
        getline(cin >> std::ws, username);

        cout << "Enter your password: ";
        getline(cin >> std::ws, password);

        if (!(systemInstance.loginCheck(username, password).empty())) {
            cout << "welcome ";
            UI::showMemberScreen(systemInstance.loginCheck(username, password));
            return;
        }
        cout << "Wrong username or password" << endl;
    }
}

void Event::registerScreen() {
    string fullname;
    string username;
    string password;
    string passwordDoubleCheck;
    string address;
    string phoneNumber;
    string email;

    cout << "Enter your full name: ";
    getline(cin >> std::ws, fullname);

    cout << "Enter your username: ";
    getline(cin >> std::ws, username);

    while (true) {
        cout << "Enter your password: ";
        getline(cin >> std::ws, password);

        cout << "Confirm your password: ";
        getline(cin >> std::ws, passwordDoubleCheck);

        if (password == passwordDoubleCheck) {
            break;
        }
        cout << "Re-enter your password" << endl;
    }

    cout << "Enter your address: ";
    getline(cin >> std::ws, address);
    // HCM or HN only

    regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    while (true) {
        cout << "Enter your email: ";
        getline(cin >> std::ws, email);

        if (regex_match(email, emailRegex)) {
            break;
        }

        cout << "Invalid email" << endl;
    }

    regex phoneRegex(R"(\+?[0-9]+[\s\-]*[0-9]+[\s\-]*[0-9]+)");

    while (true) {
        cout << "Enter your phone number: ";
        getline(cin >> std::ws, phoneNumber);

        if (regex_match(phoneNumber, phoneRegex)) {
            break;
        }

        int checked = systemInstance.checkIfInputIsInteger(phoneNumber);
        if (checked != -1) {
            break;
        }

        cout << "Invalid phone number" << endl;
    }
    systemInstance.registerNewMember(fullname, email, address,
                                     stoi(phoneNumber), username, password);
    UI::showRegisterLoginScreen(MEMBER);
}