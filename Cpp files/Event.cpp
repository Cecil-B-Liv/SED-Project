//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/Event.h"
#include "../Header files/BasicSTDLIB.h"

#define LOGIN 1
#define REGISTER 2

void Event::Login() {
    string username;
    string password;

    cout << "Enter your username: ";
    getline(cin >> std::ws, username);

    cout << "Enter your password: ";
    getline(cin >> std::ws, password);

    if ((username == "liv") && (password == "LIV")) {
        cout << "Welcome";
    }
}

void Event::Menu() {
    int choice;

    cout << "What do you want\n";
    cout << "1. Login\n2. Register\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == LOGIN) {

    }
}
