/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 2
    Author: Huynh Ngoc Tai, Tran Quang Minh, Nguyen Hoang Viet
    ID: s3978680, s3988776, s3926104
    Compiler used: Compiler version (e.g. g++ 13.1.0, type "g++ --version" to
   check) Created  date: 28/12/2023 Acknowledgement: None
*/

#include "../Header files/INCLUDEHEADERS.h"

enum UserPosition {
    GUEST = 1,
    MEMBER,
};

const string YES = "y";
const string NO = "n";

enum UserChoice {
    LOGIN = 1, REGISTER
};

enum {
    MEMBER_INFO = 1, MEMBER_SKILL_RATING
};

enum {
    RESET_MEM_PWD = 1
};

// username and password for admin
string const adminUsername = "admin";
string const adminPassword = "admin";

// Dividers shortcuts
#define sectionDivider                                                       \
    cout << COLOR_CYAN << "************************************************" \
         << COLOR_RESET << endl;
#define elementDivider \
    cout << "------------------------------------------------" << endl;

System &systemInstance = System::getInstance();

// Initialize all the reader and append to a vector for easy access
void Event::initialize() {
    systemInstance.memberFileReader();
    systemInstance.ratingFileReader();
    systemInstance.requestFileReader();
}

void Event::endScreen() {
    // pass
}

// Display the starting screen with welcome message and user role options
void Event::startScreen() {
    string input;

    // Welcome Message
    sectionDivider
    cout << COLOR_YELLOW << STYLE_BOLD
         << "EEET2482/COSC2082 ASSIGNMENT" << COLOR_RESET
         << endl;
    cout << COLOR_YELLOW << STYLE_UNDERLINE << "“TIME BANK” APPLICATION"
         << COLOR_RESET << endl;
    sectionDivider

    cout
            << endl;
    cout << "Instructor: Mr. Tran Duc Linh" << endl;
    cout << "Group: No. 6" << endl;
    cout << endl;
    cout << STYLE_UNDERLINE << "Team Members:" << endl;
    cout << COLOR_RED << "s3978680" << COLOR_WHITE << "- Huynh Ngoc Tai"
         << COLOR_RESET << endl;
    cout << COLOR_RED << "s3988776" << COLOR_WHITE << "- Tran Quang Minh"
         << COLOR_RESET << endl;
    cout << COLOR_RED << "s3926104" << COLOR_WHITE << "- Nguyen Hoang Viet"
         << COLOR_RESET << endl;
    cout << COLOR_RED << "s3940891" << COLOR_WHITE << "- Ngo Minh Hieu"
         << COLOR_RESET << endl;
    elementDivider

    while (true) {
        // Prompt User to Choose Role
        cout << COLOR_GREEN << "Select your role: " << COLOR_RESET << endl;
        cout << COLOR_BLUE << "  1. Guest - Browse as a guest" << COLOR_RESET
             << endl;
        cout << COLOR_BLUE << "  2. Member - Access member features"
             << COLOR_RESET << endl;
        cout << COLOR_RED << "  e. Exit - Close the application" << COLOR_RESET
             << endl;
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
            case UserPosition::GUEST:
                UI::showGuestScreen();
                return;
            case UserPosition::MEMBER:
                UI::showRegisterLoginScreen();
                return;
            default:
                cout << "Invalid option provided!" << endl;
        }
    }
}

// Get ID as parameter and search for that member in memberlist
// then, show Information of that member
void Event::getMemberInfoScreen(const string &ID) {
    systemInstance.displayMemberInformation(ID);
}

void Event::guestScreen() {
    string input_1;
    string input_2;
    elementDivider
    cout << "Welcome to our Time Bank Application, you are browsing as guest:" << endl;

    while (true) {
        cout << "\nDo you want to see the information of our supporter (y/n):" << endl;
        cout << ">>> ";
        cin >> input_1;
        // Check if user's input is only number

        if (input_1 == YES) {
            cout << "Details of available supporters: " << endl;
            for (auto &member: systemInstance.getMemberList()) {
                member.showInfo();
                cout << "\n";
            }
        } else if (input_1 == NO) {
            break;
        } else {
            cout << "Invalid option provided!" << endl;
        }
    }

    elementDivider

    while (true) {
        cout << COLOR_GREEN
             << "If you want to book one of our supporter, or becoming one of us, consider joining us here: "
                "\n Please select an option: "
             << COLOR_RESET << endl
             << endl;
        cout << COLOR_BLUE "1. Sign-in with an existing account " << COLOR_RESET
             << endl;
        cout << COLOR_BLUE << "2. Sign-up an account to join us." << COLOR_RESET
             << endl;
        cout << endl;
        cout << COLOR_RED << "e. Exit - Close the application" << COLOR_RESET
             << endl;
        cout << COLOR_YELLOW << "h. Return to start screen" << COLOR_RESET
             << endl;
        cout << endl;
        cout << ">>> ";

        cin >> input_2;

        if (input_2 == "e") {
            return;
        }

        if (input_2 == "h") {
            Event::startScreen();
            return;
        }

        // Check if user's input is only number
        switch (systemInstance.checkIfInputIsInteger(input_2)) {
            // case 0:
            case UserChoice::REGISTER:
                UI::showRegisterScreen();
                return;
            case UserChoice::LOGIN:
                UI::showLoginScreen();
                return;
            default:
                cout << "Invalid option provided!" << endl;
        }
    }
}

void Event::memberScreen(const string &ID) {
    string input;

    cout << ID << endl;

    elementDivider

    while (true) {
        cout << COLOR_GREEN << "Please select an option" << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_BLUE << "1. View my info" << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_RED << "e. Exit - Close the application" << COLOR_RESET
             << endl;
        cout << COLOR_YELLOW << "h. Return to start screen" << COLOR_RESET
             << endl;
        cout << endl;
        cout << ">>> ";

        cin >> input;

        if (input == "e") {
            return;
        }

        if (input == "h") {
            Event::startScreen();
            return;
        }

        // Check if user's input is only number
        switch (systemInstance.checkIfInputIsInteger(input)) {
            case MEMBER_INFO:
                UI::showMemberInformationScreen(ID);
                return;
            case MEMBER_SKILL_RATING:
                cout << "have yet to implemented";
                return;
            default:
                cout << COLOR_RED << "Invalid option provided!" << COLOR_RESET
                     << endl;
        }
    }
}

void Event::adminScreen() {
    string input;

    cout << "\nWelcome, you are browsing with administrator role." << endl;
    elementDivider

    while (true) {
        cout << COLOR_GREEN << "Please select an option" << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_BLUE << "1. Reset a member password." << COLOR_RESET
             << endl;
        cout << endl;
        cout << COLOR_RED << "e. Exit - Close the application" << COLOR_RESET
             << endl;
        cout << COLOR_YELLOW << "h. Return to start screen" << COLOR_RESET
             << endl;
        cout << endl;

        cout << ">>> ";

        cin >> input;

        if (input == "e") {
            return;
        }

        if (input == "h") {
            Event::startScreen();
            return;
        }

        // Check if user's input is only number
        switch (systemInstance.checkIfInputIsInteger(input)) {
            case RESET_MEM_PWD:
                UI::resetMemberPwdScreen();
                return;
            default:
                cout << COLOR_RED << "Invalid option provided!" << COLOR_RESET
                     << endl;
        }
    }
}

void Event::registerLoginScreen() {
    string givenChoice;

    while (true) {
        cout << COLOR_YELLOW << "Continue sign-in to enter." << COLOR_RESET
             << endl;
        cout << COLOR_GREEN << "Please select an option: " << COLOR_RESET
             << endl;
        cout << endl;
        cout << COLOR_BLUE << "1. Sign-in with an existing account."
             << COLOR_RESET << endl;
        cout << COLOR_BLUE
             << "2. Don't have an account? Consider signing up for one."
             << COLOR_RESET << endl
             << endl;
        cout << COLOR_YELLOW << "h. Return to start screen" << COLOR_RESET
             << endl;
        cout << COLOR_RED << "e. Exit - Close the application" << COLOR_RESET
             << endl;
        cout << endl;
        cout << ">>> ";

        cin >> givenChoice;

        if (givenChoice == "e") {
            return;
        }

        if (givenChoice == "h") {
            Event::startScreen();
            return;
        }
        // Check if user's input is only number

        switch (systemInstance.checkIfInputIsInteger(givenChoice)) {
            case UserChoice::LOGIN:
                UI::showLoginScreen();
                return;
            case UserChoice::REGISTER:
                UI::showRegisterScreen();
                return;
            default:
                cout << COLOR_RED << "Invalid option provided" << COLOR_RESET
                     << endl;
        }
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

        if (username == adminUsername && password == adminPassword) {
            UI::showAdminScreen();
            return;
        }

        if (!(systemInstance.getIDWithUsernamePassword(username, password).empty())) {
            cout << "Welcome to Time Bank!";
            UI::showMemberScreen(
                    systemInstance.getIDWithUsernamePassword(username, password));
            return;
        }
        cout << COLOR_RED << "Wrong username or password!" << COLOR_RESET
             << endl;
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

        cout << COLOR_RED << "Invalid email" << COLOR_RESET << endl;
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
    cout << "Successfully register your account \n Press e to exit to start screen.";
    UI::start();
}

void Event::resetMemberPwd() {
    string id;
    string input;
    string newPassword;

    while (true) {
        cout << "Enter the ID of the member you want to reset their password: ";
        getline(cin >> std::ws, id);

        if (systemInstance.checkMemberExist(id)) {
            cout << "Existing member with your inputted ID. Loading.." << endl;
            elementDivider
            cout << "Information of member" << id << endl;
            systemInstance.displayMemberInformation(id);
            break;
        }

        cout << "\nID not found.\nDo you want to try again?(y/n)";
        cin >> input;

        if (input == YES)
            continue;
        else if (input == NO)
            break;
        else {
            cout << "Invalid option. Return to administrator screen.";
            UI::showAdminScreen();
        }
    }

    while (true) {
        cout << "Select these options: " << endl;
        cout << "1. Change this account password." << endl;
        cout << COLOR_RED << "e. Exit - Close the application"
             << COLOR_RESET << endl;
        cout << COLOR_YELLOW << "h. Return to start screen" << COLOR_RESET
             << endl;
        cout << endl;

        cout << endl << ">>>>";
        cin >> input;

        if (input == "e") {
            return;
        }

        if (input == "h") {
            UI::start();
            return;
        }

        // Check if user's input is only number
        switch (systemInstance.checkIfInputIsInteger(input)) {
            case RESET_MEM_PWD:
                cout << "Enter new password that you want to reset: "
                     << endl;
                cout << ">>> ";
                getline(cin >> std::ws, newPassword);
                systemInstance.resetPassword(id, newPassword);
                UI::showAdminScreen();
                return;
            default:
                cout << COLOR_RED << "Invalid option provided" << COLOR_RESET << endl;
        }
    }
}