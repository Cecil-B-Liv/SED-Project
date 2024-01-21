#include "../Header files/INCLUDEHEADERS.h"

#define ONLINE 1
#define OFFLINE -1

// Constructor
Booking::Booking() {
    std::time_t timeOfRequestObjectCreation = std::time(nullptr);
    creationTime = *std::localtime(&timeOfRequestObjectCreation);
}

// function code

// bool Booking::answerRequest() {
//     return true;
// }

void Booking::showInfo() {
    cout << COLOR_GREEN << "Booking ID: " << bookingID << COLOR_RESET << endl;
    cout << COLOR_GREEN << "Host ID: " << hostMemberID << COLOR_RESET << endl;
    cout << COLOR_GREEN << "Supporter ID: " << hostMemberID << COLOR_RESET
         << endl;
    cout << COLOR_CYAN << "Time Renting " << timeRenting << COLOR_RESET << endl;
    cout << COLOR_CYAN << "Creation time: " << getFormattedCreationTime()
         << COLOR_RESET << endl;
    cout << COLOR_CYAN
         << "Start Renting time: " << getFormattedStartRentingTime()
         << COLOR_RESET << endl;
    cout << COLOR_BLUE << "Status: " << status << COLOR_RESET << endl;
}
