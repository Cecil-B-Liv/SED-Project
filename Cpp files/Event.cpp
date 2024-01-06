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

// Initialize all the reader and append to a vector for easy access
void Event::Initialize() {
    systemInstance.memberFileReader();
    systemInstance.hostFileReader();
    systemInstance.ratingFileReader();
    systemInstance.requestFileReader();
    systemInstance.supporterFileReader();
}


void Event::StartScreen() {
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

        switch (systemInstance.checkIfInputIsInteger(input)) {
            case GUEST:
            case MEMBER:
            case ADMIN:
                UI::RegisterLogin(systemInstance.checkIfInputIsInteger(input));
                return;
        }
        cout << "Not an option" << endl;
    }
}

void Event::MemberScreen(const string &ID) {
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
        if (systemInstance.checkIfInputIsInteger(input) != -1) {
            switch (systemInstance.checkIfInputIsInteger(input)) {
                case MEMBER_INFO:
                    UI::Information(ID);
                    return;
                case MEMBER_SKILL_RATING:
                    return;
            }
        }
        cout << "Not an option" << endl;
    }
}

void Event::InformationScreen(const string &ID) {
    systemInstance.getMemberInformation(ID);
}

void Event::RegisterLoginScreen(int choice) {
    string givenChoice;

    if (choice == ADMIN) {
        return;
    }

    // Other than admin was chosen
    while (true) {
        cout << "1. Log in 2. Register" << endl;
        cout << ">>> ";

        cin >> givenChoice;

        // Check if user's input is only number

        switch (systemInstance.checkIfInputIsInteger(givenChoice)) {
            case LOGIN:
                UI::Login();
                return;
            case REGISTER:
                UI::Register();
                return;
        }
        cout << "Not an option" << endl;
    }
}

void Event::LoginScreen() {
    string username;
    string password;

    while (true) {
        cout << "Enter your username: ";
        getline(cin >> std::ws, username);

        cout << "Enter your password: ";
        getline(cin >> std::ws, password);

        if (!(systemInstance.loginCheck(username, password).empty())) {
            cout << "welcome ";
            UI::Member(systemInstance.loginCheck(username, password));
            return;
        }
        cout << "Wrong username or password" << endl;
    }
}

void Event::RegisterScreen() {
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

    regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    while (true) {
        cout << "Enter your email: ";
        getline(cin >> std::ws, email);

        if (regex_match(email, emailRegex)) { break; }

        cout << "Invalid email" << endl;
    }

    regex phoneRegex(R"(\+?[0-9]+[\s\-]*[0-9]+[\s\-]*[0-9]+)");

    while (true) {
        cout << "Enter your phone number: ";
        getline(cin >> std::ws, phoneNumber);

        if (regex_match(phoneNumber, phoneRegex)) { break; }

        int checked = systemInstance.checkIfInputIsInteger(phoneNumber);
        if (checked != -1) {
            break;
        }

        cout << "Invalid phone number" << endl;
    }
    systemInstance.registerNewMember(fullname, email, address, stoi(phoneNumber), username, password);
    UI::RegisterLogin(MEMBER);
}