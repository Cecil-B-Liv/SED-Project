#include "../Header files/INCLUDEHEADERS.h"

#define ONLINE 1
#define OFFLINE -1

// Constructor
Request::Request() {
    std::time_t timeOfRequestObjectCreation = std::time(nullptr);
    creationTime = *std::localtime(&timeOfRequestObjectCreation);
}

//function code

void Request::showInfo() {
    cout << "Booking ID: " << bookingID << endl;
    cout << "Host ID: " << hostMemberID << endl;
    cout << "Supporter ID: " << hostMemberID << endl;
    cout << "Skill Required: " << endl;
    cout << endl;
    cout << "Creation time: " << getFormattedCreationTime() << endl;
    cout << "Status: " << endl;

    // for (string *skill: skillRequired) {
    //     cout << *skill;
    // }
}
