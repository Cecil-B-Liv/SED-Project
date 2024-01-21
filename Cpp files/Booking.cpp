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


void Booking::showInfo() const {
    cout << COLOR_GREEN << "Booking ID: " << COLOR_RESET << bookingID << endl;
    cout << COLOR_CYAN << "Host ID: " << COLOR_RESET<< hostMemberID << endl;
    cout << COLOR_CYAN <<"Supporter ID: " << COLOR_RESET<< hostMemberID << endl;
    cout << COLOR_BLUE << "Time Renting " << COLOR_RESET<< timeRenting << endl;
    cout << COLOR_BLUE <<"Creation time: " << COLOR_RESET<< getFormattedCreationTime() << endl;
    cout << COLOR_BLUE <<"Start Renting time: " << COLOR_RESET<< getFormattedStartRentingTime() << endl;
    cout << COLOR_BLUE <<"Status: " << COLOR_RESET<< status << endl;
}
