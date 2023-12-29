//
// Created by Nick Anderson on 28/12/2023.
//

#include "../Header files/UI.h"
#include "../Header files/Event.h"

void UI::Start() {
    Event::StartScreen();
}

void UI::Login() {
    Event::LoginScreen();
}

void UI::Register() {
    Event::RegisterScreen();
}

void UI::Member() {}

