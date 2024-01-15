/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 2
    Author: Huynh Ngoc Tai, Tran Quang Minh, Nguyen Hoang Viet
    ID: s3978680, s3988776, s3926104
    Compiler used: Compiler version (e.g. g++ 13.1.0, type "g++ --version" to check)
    Created  date: 28/12/2023
    Acknowledgement: None
*/

#include "../Header files/INCLUDEHEADERS.h"

#define GUEST 1
#define MEMBER 2
#define ADMIN 3

#define LOGIN 1
#define REGISTER 2

#define MEMBER_INFO 1
#define MEMBER_SKILL_RATING 2

// Dividers shortcuts
#define sectionDivider cout << COLOR_CYAN << "************************************************" << COLOR_RESET << endl;
#define elementDivider cout << "------------------------------------------------" << endl;
// #define print(x) cout << x << endl;

System &systemInstance = System::getInstance();

// Initialize all the reader and append to a vector for easy access
void Event::initialize() {
    systemInstance.memberFileReader();
    systemInstance.hostFileReader();
    systemInstance.ratingFileReader();
    systemInstance.requestFileReader();
    systemInstance.supporterFileReader();
}

// Display the starting screen with welcome message and user role options
void Event::startScreen() {
    string input;

    // Welcome Message
    cout << endl;
    sectionDivider;
    cout << endl;
    cout << COLOR_YELLOW << STYLE_BOLD << "EEET2482/COSC2082 ASSIGNMENT" << COLOR_RESET << endl;
    cout << COLOR_YELLOW << STYLE_UNDERLINE << "“TIME BANK” APPLICATION" << COLOR_RESET << endl;
    cout << endl;
    sectionDivider;

    cout << endl;
    cout << "Instructor: Mr. Tran Duc Linh" << endl;
    cout << "Group: No. 6" << endl;
    cout << endl;
    cout << COLOR_YELLOW << STYLE_UNDERLINE << "Team Members:" << COLOR_RESET << endl;
    cout << COLOR_RED << "s3978680 " <<  COLOR_WHITE << "- Huynh Ngoc Tai" << COLOR_RESET << endl;
    cout << COLOR_RED << "s3988776 " <<  COLOR_WHITE << "- Tran Quang Minh" << COLOR_RESET << endl;
    cout << COLOR_RED << "s3926104 " <<  COLOR_WHITE << "- Nguyen Hoang Viet" << COLOR_RESET << endl;
    cout << COLOR_RED << "s3940891 " <<  COLOR_WHITE << "- Ngo Minh Hieu" << COLOR_RESET << endl;
    elementDivider;

    while (true) {
        // Prompt User to Choose Role
        cout << COLOR_GREEN << "Select your role: " << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_BLUE << "  1. Guest - Browse as a guest" << COLOR_RESET << endl;
        cout << COLOR_BLUE << "  2. Member - Access member features" << COLOR_RESET << endl;
        cout << COLOR_BLUE << "  3. Admin - Administrative tasks" << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_RED << "  e. Exit - Close the application" << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_YELLOW << ">>> " << COLOR_RESET;

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
                cout << "Invalid option provided!" << endl;
        }
    }
}

void Event::guestScreen() {
    string input;

    cout << "Details of available supporters: " << endl;
    for (Member supporter : systemInstance.getMemberList()) {
        supporter.showInfo();
        cout << ">>>>" << endl << endl;
    }

    elementDivider;

    while (true) {
        cout << COLOR_GREEN << "If you want to book one of our supporter, consider joining us here: \nPlease select an option: " << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_BLUE << "1. Sign-up an account to join us." << COLOR_RESET << endl;
        cout << COLOR_BLUE "2. Sign-in with an existing account "<< COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_RED << "e. Exit - Close the application" << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_YELLOW << ">>> " << COLOR_RESET;

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
                cout << COLOR_RED << "Invalid option provided!" << COLOR_RESET << endl;
        }
    }
}

void Event::memberScreen(const string &ID) {
    string input;

    cout << ID << endl;

    elementDivider;

    while (true) {
        cout << COLOR_GREEN << "Please select an option" << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_BLUE << "1. View my info" << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_RED << "e. Exit - Close the application" << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_YELLOW << ">>> " << COLOR_RESET;

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
            default: 
                cout << COLOR_RED << "Invalid option provided!" << COLOR_RESET << endl;
        }
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
        cout << COLOR_GREEN << "Please select an option: " << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_BLUE << "1. Login as member" << COLOR_RESET << endl;
        cout << COLOR_BLUE << "2. Register as a member" << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_YELLOW ">>> " << COLOR_RESET;

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
        cout << COLOR_RED << "Invalid option provided!" << COLOR_RESET << endl;
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
            cout << "Welcome to Time Bank!";
            UI::showMemberScreen(systemInstance.loginCheck(username, password));
            return;
        }
        cout << COLOR_RED << "Wrong username or password!" << COLOR_RESET << endl;
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

    cout << "Enter your fullname: ";
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

        cout << COLOR_RED << "Invalid email!" << COLOR_RESET << endl;
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

        cout << COLOR_RED << "Invalid phone number!" << COLOR_RESET << endl;
    }
    systemInstance.registerNewMember(fullname, email, address,
                                     stoi(phoneNumber), username, password);
    UI::showRegisterLoginScreen(MEMBER);
}