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

const vector<string> skillStrings = {
        "Unknown skill", "Car Mechanic",
        "Teaching", "Tutoring",
        "Plumbing Repair", "Writing",
        "Photography", "Cooking",
        "Gardening", "House Cleaning",
        "Laundry", "Sewing",
        "First Aid", "Time Management",
        "Public Speaking", "Basic Computer Skills",
        "Money Management", "Communication",
        "Problem Solving", "Teamwork",
        "Stress Management"};

enum UserPosition {
    GUEST = 1,
    MEMBER,
};

const string YES = "y";
const string NO = "n";

enum City {
    HCM = 1, Hanoi
};
enum UserChoice {
    LOGIN = 1, REGISTER
};


enum {
    MEMBER_INFO = 1, BOOK_AVAILABLE_SUPPORTER, BOOKING, ADD_SKILL, REMOVE_SKILL, SET_BOOKING_STATUS, COMPLETE_BOOKING
};


enum ADMIN {
    RESET_MEM_PWD = 1,
    VIEW_MEMBERLIST,
    VIEW_RATINGLIST,
    VIEW_BOOKINGLIST
};

// username and password for admin
string const adminUsername = "admin";
string const adminPassword = "admin";

string currentID;

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
    systemInstance.bookingFileReader();
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
    cout << COLOR_YELLOW << STYLE_UNDERLINE << "\"TIME BANK\" APPLICATION"
         << COLOR_RESET << endl;
    sectionDivider


    cout
            << "Instructor: Mr. Tran Duc Linh" << endl;

    cout << "Group: No. 6" << endl;
    cout << endl;
    cout << STYLE_UNDERLINE << "Team Members:" << COLOR_RESET << endl;
    cout << COLOR_RED << "s3978680 " << COLOR_WHITE << "- Huynh Ngoc Tai"
         << COLOR_RESET << endl;
    cout << COLOR_RED << "s3988776 " << COLOR_WHITE << "- Tran Quang Minh"
         << COLOR_RESET << endl;
    cout << COLOR_RED << "s3926104 " << COLOR_WHITE << "- Nguyen Hoang Viet"
         << COLOR_RESET << endl;
    cout << COLOR_RED << "s3940891 " << COLOR_WHITE << "- Ngo Minh Hieu"
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
                systemInstance.clearTerminal();
                UI::showGuestScreen();
                return;
            case UserPosition::MEMBER:
                UI::showRegisterLoginScreen();
                return;
            default:
                cout << COLOR_RED << "Invalid option provided!" << COLOR_RESET
                     << endl;
        }
    }
}

// Get ID as parameter and search for that member in memberlist
// then, show Information of that member
void Event::getMemberInfoScreen(const string &ID) {
    systemInstance.displayMemberInformation(ID);
}

void Event::getAllSupporterInformationScreen() {
    string input;
    string inputMinRating;
    Member &temp = systemInstance.getMemberObject(currentID);

    while (true) {
        cout << "\nMinimum rating score: "
             << endl;
        cout << ">>> ";
        cin >> inputMinRating;

        try {
            std::stod(inputMinRating);
        } catch (std::invalid_argument &) {
            cout << "no";
        }
        if (std::stod(inputMinRating) > 0 && std::stod(inputMinRating) <= 5) {
            break;
        }
        cout << "no" << endl;
    }

    // Check if user's input is only number
    cout << "Details of available supporters: " << endl;

    for (auto &member: systemInstance.getMemberList()) {
        if (member.getMemberAvailableStatus() &&
            member.getMemberID() != currentID &&
            member.getHomeAddress() == temp.getHomeAddress() &&
            member.getRatingScore() >= std::stod(inputMinRating)) {
            member.showInfo();
        }
        cout << "\n";
    }
}


void Event::showAllBookingList() {
    string input;
    while (true) {
        cout << "\nDo you want to see all booking in our "
                "system? (y.YES/n.NO):"
             << endl;
        cout << ">>> ";
        cin >> input;
        // Check if user's input is only number
        if (input == YES) {
            cout << "Details of active booking in the system: " << endl;
            for (auto &booking: systemInstance.getBookingList()) {
                booking.showInfo();
                cout << "\n";
            }
            break;
        } else if (input == NO) {
            break;
        } else {
            cout << "Invalid option provided!" << endl;
        }
    }
}

void Event::showAllRatingList() {
    string input;
    while (true) {
        cout << "\nDo you want to see the all the rating in the system? "
                "(y.YES/n.NO):"
             << endl;
        cout << ">>> ";
        cin >> input;
        // Check if user's input is only number
        if (input == YES) {
            cout << "Details of rating in the system: " << endl;
            for (auto &rating: systemInstance.getRatingList()) {
                rating.showInfo();
                cout << "\n";
            }
            return;
        } else if (input == NO) {
            UI::showMemberScreen(currentID);
            return;
        } else {
            cout << "Invalid option provided!" << endl;
        }
    }
}

void Event::guestScreen() {
    string input_1;
    string input_2;
    elementDivider
    cout
            << COLOR_YELLOW << STYLE_UNDERLINE
            << "Welcome to our Time Bank Application, you are browsing as guest:"
            << COLOR_RESET << endl;

    while (true) {
        cout << "\nDo you want to see the information of our supporter (y/n):"
             << endl;
        cout << COLOR_YELLOW << ">>> " << COLOR_RESET;
        cin >> input_1;
        // Check if user's input is only number

        if (input_1 == YES) {
            cout << COLOR_CYAN << STYLE_UNDERLINE
                 << "Details of available supporters: " << COLOR_RESET << endl;
            cout << endl;
            for (auto &member: systemInstance.getMemberList()) {
                member.showInfo();
                cout << "\n";
            }
            break;
        } else if (input_1 == NO) {
            break;
        } else {
            cout << COLOR_RED << "Invalid option provided!" << COLOR_RESET
                 << endl;
        }
    }

    elementDivider

    while (true) {
        cout << COLOR_GREEN
             << "If you want to book one of our supporter, or becoming one of "
                "us, consider joining us here: "
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
        cout << COLOR_YELLOW << ">>> " << COLOR_RESET;

        cin >> input_2;

        if (input_2 == "e") {
            return;
        }

        if (input_2 == "h") {
            systemInstance.clearTerminal();
            Event::startScreen();
            return;
        }

        // Check if user's input is only number
        switch (systemInstance.checkIfInputIsInteger(input_2)) {
            // case 0:
            case UserChoice::REGISTER:
                systemInstance.clearTerminal();
                UI::showRegisterScreen();
                return;
            case UserChoice::LOGIN:
                systemInstance.clearTerminal();
                UI::showLoginScreen();
                return;
            default:
                cout << COLOR_RED << "Invalid option provided!" << COLOR_RESET
                     << endl;
        }
    }
}

void Event::memberScreen(const string &ID) {
    string input;

    cout << ID << "-" << systemInstance.getMemberObject(ID).getFullName()
         << endl;

    while (true) {
        cout << COLOR_GREEN << "Please select an option" << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_BLUE << "1. View my info." << COLOR_RESET << endl;
        cout << COLOR_BLUE << "2. View available supporter and book them."
             << COLOR_RESET << endl;
        cout << COLOR_BLUE << "3. See pending booking."
             << COLOR_RESET << endl;

        cout << endl;
        cout << COLOR_BLUE << "4. Add skills."
             << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_BLUE << "5. Remove skills."
             << COLOR_RESET << endl;
        cout << endl;
        cout << COLOR_RED << "e. Exit - Close the application." << COLOR_RESET
             << endl;
        cout << COLOR_YELLOW << "h. Return to start screen." << COLOR_RESET
             << endl;
        cout << endl;
        cout << COLOR_YELLOW << ">>> " << COLOR_RESET;

        cin >> input;

        if (input == "e") {
            return;
        }

        if (input == "h") {
            systemInstance.clearTerminal();
            Event::startScreen();
            return;
        }

        // Check if user's input is only number
        switch (systemInstance.checkIfInputIsInteger(input)) {
            case MEMBER_INFO:
                systemInstance.clearTerminal();
                UI::showMemberInformationScreen(ID);
                UI::showMemberScreen(ID);
                return;
            case BOOK_AVAILABLE_SUPPORTER:
                //                 while (true) {
                //                     cout << "\nDo you want to see the
                //                     information of our "
                //                             "supporters (y.YES/n.NO):"
                //                          << endl;
                //                     cout << COLOR_YELLOW << ">>> " <<
                //                     COLOR_RESET; cin >> input;
                //                     // Check if user's input is only number
                //                     if (input == YES) {
                //                         cout << COLOR_CYAN << STYLE_UNDERLINE
                //                         << "Details of available supporters:
                //                         " << endl; cout << endl; for (auto
                //                         &member :
                //                         systemInstance.getMemberList()) {
                //                             member.showInfo();
                //                             cout << "\n";
                //                         }
                //                     } else if (input == NO) {
                //                         break;
                //                     } else {
                //                         cout << COLOR_RED << "Invalid option
                //                         provided!" << COLOR_RESET << endl;
                //                     }
                //                 }
                systemInstance.clearTerminal();
                UI::showAllSupporterInformationScreen();
                UI::bookSupporter(ID);
                return;
            case BOOKING:
                systemInstance.clearTerminal();
                UI::showPendingBooking();
                return;
            case ADD_SKILL:
                systemInstance.clearTerminal();
                UI::showAddSKill();
                return;
            case REMOVE_SKILL:
                systemInstance.clearTerminal();
                UI::showRemoveSkill();
                return;
            case SET_BOOKING_STATUS:
                systemInstance.clearTerminal();
                UI::showBookingStatus();
                return;
            case COMPLETE_BOOKING:
                systemInstance.clearTerminal();
                UI::showCompleteBooking();
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
        cout << COLOR_BLUE << "2. View member in the system." << COLOR_RESET
             << endl;
        cout << COLOR_BLUE << "3. View all rating in the system." << COLOR_RESET
             << endl;
        cout << COLOR_BLUE << "4. View all booking in the system."
             << COLOR_RESET << endl;

        cout << endl;
        cout << COLOR_YELLOW << "h. Return to start screen" << COLOR_RESET
             << endl;
        cout << COLOR_RED << "e. Exit - Close the application" << COLOR_RESET
             << endl;
        cout << endl;

        cout << COLOR_YELLOW << ">>> " << COLOR_RESET;

        cin >> input;

        if (input == "e") {
            return;

        } else if (input == "h") {
            Event::startScreen();
            return;
        }

        // Check if user's input is only number
        switch (systemInstance.checkIfInputIsInteger(input)) {
            case RESET_MEM_PWD:
                systemInstance.clearTerminal();
                UI::resetMemberPwdScreen();
                return;
            case VIEW_MEMBERLIST:
                UI::showAllSupporterInformationScreen();
                UI::showAdminScreen();
                return;
            case VIEW_RATINGLIST:
                UI::showAllRatingScreen();
                UI::showAdminScreen();
                return;
            case VIEW_BOOKINGLIST:
                UI::showAllBookingScreen();
                UI::showAdminScreen();
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
        cout << COLOR_YELLOW << "\nContinue sign-in to enter." << COLOR_RESET
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
        cout << COLOR_YELLOW ">>> " << COLOR_RESET;

        cin >> givenChoice;

        if (givenChoice == "e") {
            return;
        } else if (givenChoice == "h") {
            systemInstance.clearTerminal();
            Event::startScreen();
            return;
        }
        // Check if user's input is only number

        switch (systemInstance.checkIfInputIsInteger(givenChoice)) {
            case UserChoice::LOGIN:
                systemInstance.clearTerminal();
                UI::showLoginScreen();
                return;
            case UserChoice::REGISTER:
                systemInstance.clearTerminal();
                UI::showRegisterScreen();
                return;
            default:
                cout << COLOR_RED << "Invalid option provided!" << COLOR_RESET
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
            systemInstance.clearTerminal();
            UI::showAdminScreen();
            return;
        }

        if (!(systemInstance.getIDWithUsernamePassword(username, password)
                .empty())) {
            cout << COLOR_BLUE
                 << "\nCurrently loading you to your member screen."
                 << COLOR_RESET << endl;
            elementDivider

            cout
                    << COLOR_YELLOW << STYLE_UNDERLINE << "\nWelcome to Time Bank!"
                    << COLOR_RESET << endl;
            currentID =
                    systemInstance.getIDWithUsernamePassword(username, password);
            UI::showMemberScreen(currentID);

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
        cout << "Re-enter your password: " << endl;
    }

    cout << "Enter the city where you are living (Our application only "
            "available in 2 Vietnamese cities. 1.HCM/ 2.Hanoi): ";
    cout << "\nPress e if you want to exit." << endl;

    string input;

    while (true) {
        cout << ">>> ";
        getline(cin >> std::ws, input);

        if (input == "e")
            return;
        else if (systemInstance.checkIfInputIsInteger(input) == HCM) {
            address = "Ho Chi Minh City";
            break;
        } else if (systemInstance.checkIfInputIsInteger(input) == Hanoi) {
            address = "Ha Noi City";
            break;
        }
        cout << COLOR_RED << "Invalid option provided!" << COLOR_RESET << endl;
    }
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

                                     phoneNumber, username, password);
    cout << COLOR_GREEN
         << "Successfully register your account \n Press e to exit to start "
            "screen."
         << COLOR_RESET << endl;

    UI::start();
}

void Event::resetMemberPwd() {
    string id;
    string input;
    string newPassword;

    while (true) {
        cout << "Enter the ID of the member you want to reset their "
                "password: ";
        getline(cin >> std::ws, id);

        if (systemInstance.checkMemberExist(id)) {
            cout << COLOR_GREEN
                 << "Existing member found with matching ID. Loading..."
                 << COLOR_RESET << endl;
            elementDivider
            cout << "Information of member: " << id << endl;
            systemInstance.displayMemberInformation(id);
            break;
        }

        cout << COLOR_YELLOW
             << "\nID not found.\nDo you want to try again?(y/n): "
             << COLOR_RESET;
        cin >> input;

        if (input == YES)
            continue;
        else if (input == NO)
            break;
        else {
            cout << COLOR_RED
                 << "Invalid option. Returning to administrator screen."
                 << COLOR_RESET << endl;
            UI::showAdminScreen();
        }
    }

    while (true) {
        cout << COLOR_GREEN << "Select an option: " << COLOR_RESET << endl;
        cout << COLOR_BLUE << "1. Change this account password." << endl;
        cout << endl;
        cout << COLOR_YELLOW << "h. Return to start screen" << COLOR_RESET
             << endl;
        cout << COLOR_RED << "e. Exit - Close the application" << COLOR_RESET
             << endl;
        cout << endl;

        cout << COLOR_YELLOW << ">>>" << COLOR_RESET;
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
                cout << "Enter new password that you want to reset: " << endl;
                cout << COLOR_YELLOW << ">>> " << COLOR_RESET;
                getline(cin >> std::ws, newPassword);
                systemInstance.resetPassword(id, newPassword);
                systemInstance.clearTerminal();
                UI::showAdminScreen();
                return;
            default:
                cout << COLOR_RED << "Invalid option provided" << COLOR_RESET
                     << endl;
        }
    }
}

void Event::bookSupporter(const string &hostID) {
    string supporterID;
    string input;
    double rentingTime;
    string time;
    regex timeRegex(R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2})");

    while (true) {
        cout << "\nEnter the ID of the member you want to book: ";
        getline(cin >> std::ws, supporterID);

        if (systemInstance.checkMemberExist(supporterID)) {
            break;
        }
        cout << "System doesn't have the supporter with your inputted ID.";
    }

    cout << "Existing member with your inputted ID. Loading.." << endl;
    elementDivider

    while (true) {
        cout << "Information of member " << supporterID << endl;
        systemInstance.displayMemberInformation(supporterID);
        cout << "\nDo you wish to proceed? [y/n]: ";
        cout << "\n>>> ";
        cin >> input;

        if (input == NO) {
            UI::bookSupporter(hostID);
            return;
        } else if (input == YES) {
            break;
        } else {
            cout << "Invalid input" << endl;
        }
    }

    while (true) {
        cout << "\nHow long do you want to rent: ";
        cin >> rentingTime;
        // prevent renting over 12 hours and negative number
        if (rentingTime > 0 && rentingTime < 12) {
            break;
        }
        cout << "Please enter renting time that is valid (>0 and <12): ";
    }

    while (true) {
        cout << "\nDate and time that you want to rent your supporter "
                "(yyyy-mm-dd hh:mm): ";
        getline(cin >> std::ws, time);

        if (regex_match(time, timeRegex)) {
            break;
        }
        cout << "\nWrong format! Please follow this format (yyyy-mm-dd hh:mm)"
             << endl
             << endl;
    }
    systemInstance.addNewBooking(hostID, supporterID, "Pending", rentingTime,
                                 systemInstance.parseCSVTime(time));

    for (auto &hostMember: systemInstance.getMemberList()) {
        if (hostMember.getMemberID() == hostID)
            hostMember.setSupporterMember(supporterID);
    }

    for (auto &supporterMember: systemInstance.getMemberList()) {
        if (supporterMember.getMemberID() == supporterID)
            supporterMember.setHostMember(currentID);
    }
    systemInstance.bookingFileWriter();
    systemInstance.memberFileWriter();

    UI::showMemberScreen(currentID);
}

void Event::PendingScreen() {
    string ID = currentID;
    string input;
    int cInput;
    Member &member = systemInstance.getMemberObject(currentID);

    for (Booking &booking: systemInstance.getBookingList()) {
        if (booking.getSupporterMemberID() == ID && booking.getStatus() == "Pending") {
            cout << "You were booked by: " << booking.getHostMemberID() << endl;
        } else {
            cout << "No one booked you" << endl;
            UI::showMemberScreen(ID);
            return;
        }
    }

    while (true) {
        cout << "1. Accept" << endl;
        cout << "2. Deny" << endl;
        cout << "h. Back" << endl;

        getline(cin >> std::ws, input);

        if (input == "h") {
            return;
        }

        cInput = systemInstance.checkIfInputIsInteger(input);
        if (cInput) break;

        cout << "invalid";
    }


    if (cInput == 1) {
        for (Booking &booking: systemInstance.getBookingList()) {
            if (booking.getSupporterMemberID() == ID) {
                booking.setStatus("Approved");
                member.setAvailableStatus(false);
            }
        }
    } else if (cInput == 2) {
        for (Booking &booking: systemInstance.getBookingList()) {
            if (booking.getSupporterMemberID() == ID)
                booking.setStatus("Denied");
        }
    } else {
        cout << "no";
    }

    systemInstance.bookingFileWriter();
    systemInstance.memberFileWriter();
    UI::showMemberScreen(ID);
}

void Event::topUpScreen(const string &memberID) {
    systemInstance.clearTerminal();
    cout << COLOR_YELLOW << STYLE_UNDERLINE << "Top-Up Credits" << COLOR_RESET
         << endl;
    elementDivider

    int topUpAmount;
    cout << "Enter the amount of credits to top up: ";
    cin >> topUpAmount;

    if (cin.fail() || topUpAmount < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << COLOR_RED << "Invalid input. Please enter a positive number."
             << COLOR_RESET << endl;
        UI::showMemberScreen(memberID);
        return;
    }

    string passwordInput;
    int attempts = 0;
    while (attempts < 3) {
        cout << "Enter your password to confirm: ";
        cin >> passwordInput;
        if (systemInstance.topUpCredits(memberID, topUpAmount, passwordInput)) {
            Member member = systemInstance.getMemberObject(memberID);
            int updatedBalance = member.getCreditPoints();

            cout << COLOR_GREEN << "Top-up successful. Your new credit balance is: " << updatedBalance << COLOR_RESET
                 << endl;

            break;
        } else {
            attempts++;
            cout << COLOR_RED
                 << "Incorrect password. Attempts left: " << (3 - attempts)
                 << COLOR_RESET << endl;
        }
    }

    if (attempts == 3) {
        systemInstance.clearTerminal();
        cout
                << COLOR_RED
                << "Incorrect password entered 3 times. Returning to Member Screen."
                << COLOR_RESET << endl;
        UI::showMemberScreen(memberID);
        return;
    }
}

void Event::AddSkill() {
    string inputSkill;
    string inputToContinue;
    int cInput;

    while (true) {
        cout << "Select with number: " << endl;

        for (int i = 1; i < skillStrings.size(); i++) {
            std::cout << i << ". " << skillStrings[i] << std::endl;
        }

        cout << ">>> ";
        getline(cin >> std::ws, inputSkill);

        if (systemInstance.checkIfInputIsInteger(inputSkill)) {
            cInput = systemInstance.checkIfInputIsInteger(inputSkill);
            break;
        }

        cout << "Invalid inputSkill" << endl;
    }
    systemInstance.addNewSkill(cInput, currentID);

    while (true) {
        cout << "Add more skills ?" << endl;
        cout << "y/n" << endl;

        getline(cin >> std::ws, inputToContinue);

        if (inputToContinue == YES) {
            UI::showAddSKill();
            return;
        } else if (inputToContinue == NO) {
            UI::showMemberScreen(currentID);
            return;
        } else {
            cout << "Invalid input";
        }
    }
}

void Event::RemoveSkill() {
    string inputSkill;
    string inputToContinue;
    int cInput;
    Member &member = systemInstance.getMemberObject(currentID);

    while (true) {
        cout << "Select with number: " << endl;

        int idx = 1;
        for (auto &it: member.getSkillInfo()) {
            cout << idx++ << "." << *it << endl;
        }

        cout << ">>> ";
        getline(cin >> std::ws, inputSkill);

        if (systemInstance.checkIfInputIsInteger(inputSkill)) {
            cInput = systemInstance.checkIfInputIsInteger(inputSkill);
            break;
        }
    }
    systemInstance.removeSkill(cInput, currentID);

    while (true) {
        cout << "Add more skills ?" << endl;
        cout << "y/n" << endl;

        getline(cin >> std::ws, inputToContinue);

        if (inputToContinue == YES) {
            UI::showRemoveSkill();
            return;
        } else if (inputToContinue == NO) {
            UI::showMemberScreen(currentID);
            return;
        } else {
            cout << "Invalid input";
        }
    }
}


void Event::BookingStatus() {
    Member &member = systemInstance.getMemberObject(currentID);
    string inputForStatus;

    cout << "Your current status: " << (member.getMemberAvailableStatus() ? "Online" : "Offline") << endl;
    while (true) {
        cout << "Do you wish to go: " << (member.getMemberAvailableStatus() ? "Offline" : "Online") << endl;
        getline(cin >> std::ws, inputForStatus);

        if (inputForStatus == YES && !member.getMemberAvailableStatus()) {
            member.setAvailableStatus(true);
            break;
        } else if (inputForStatus == YES && member.getMemberAvailableStatus()) {
            member.setAvailableStatus(false);
            return;
        } else if (inputForStatus == NO && member.getMemberAvailableStatus()) {
            break;
        } else if (inputForStatus == NO && !member.getMemberAvailableStatus()) {
            return;
        } else {
            cout << "no valid input" << endl;
        }
    }

    systemInstance.memberFileWriter();
}

void Event::CompleteBooking() {
    string ID = currentID;
    string input;
    string inputScore;
    string comment;

    int cInput;
    int cInputScore;

    string supporterID;
    Member &currMem = systemInstance.getMemberObject(currentID);


    for (Booking &booking: systemInstance.getBookingList()) {
        if (booking.getHostMemberID() == ID) {
            supporterID = booking.getSupporterMemberID();
        }
    }
    Member &supporterMember = systemInstance.getMemberObject(supporterID);

    for (Booking &booking: systemInstance.getBookingList()) {
        if (booking.getHostMemberID() == ID && booking.getStatus() == "Approved") {
            cout << "You booked: " << booking.getSupporterMemberID() << endl;
        } else {
            cout << "You haven't booked anyone yet" << endl;
            UI::showMemberScreen(ID);
            return;
        }
    }
    while (true) {
        cout << "1. Complete" << endl;
        cout << "h. Back" << endl;

        getline(cin >> std::ws, input);

        if (input == "h") {
            return;
        }

        cInput = systemInstance.checkIfInputIsInteger(input);
        if (cInput) break;

        cout << "invalid";
    }

    while (true) {
        cout << "Rate the user: ";
        getline(cin >> std::ws, inputScore);

        cInputScore = systemInstance.checkIfInputIsInteger(inputScore);
        if (cInputScore && (cInput >= 0 && cInput <= 5))
            break;

        cout << "invalid";

        switch (cInputScore) {
            case 1:
                comment = "This supporter is bad";
                break;
            case 2:
                comment = "This supporter is decent";
                break;
            case 3:
                comment = "This supporter is fine";
                break;
            case 4:
                comment = "This supporter is good";
                break;
            case 5:
                comment = "This supporter is excellent";
                break;
            default:
                cout << "fuck you";
        }
    }

    for (Booking &booking: systemInstance.getBookingList()) {
        if (booking.getHostMemberID() == currentID) {
            booking.setStatus("Completed");
        }
    }

    supporterMember.addRating(new double(cInputScore));
    supporterMember.setRatingScore(systemInstance.calculateSupporterRating(supporterID));
    systemInstance.addNewRating(supporterID, currentID,
                                systemInstance.calculateSupporterRating(supporterID),
                                0, 0, comment);

    systemInstance.ratingFileWriter();
    systemInstance.bookingFileWriter();
    systemInstance.memberFileWriter();
    UI::showMemberScreen(currentID);
}