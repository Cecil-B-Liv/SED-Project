#include "../Header files/INCLUDEHEADERS.h"

#define ONLINE 1
#define OFFLINE -1

// Constructor
Booking::Booking() {
    std::time_t timeOfRequestObjectCreation = std::time(nullptr);
    creationTime = *std::localtime(&timeOfRequestObjectCreation);
}

//function code
bool Booking::answerRequest() {
    return true;
}

void Booking::showInfo() {
    cout << "Booking ID: " << bookingID << endl;
    cout << "Member ID: " << memberID << endl;
    cout << "Skill Required: " << endl;

    for (string *skill: skillRequired) {
        cout << *skill;
    }
    cout << endl;
    cout << "Creation time: " << getFormattedCreationTime() << endl;
    cout << "Status: " << endl;
}
