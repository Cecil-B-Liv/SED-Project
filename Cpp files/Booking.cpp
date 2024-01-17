#include "../Header files/INCLUDEHEADERS.h"

#define ONLINE 1
#define OFFLINE -1

// Constructor
Booking::Booking() {
    std::time_t timeOfRequestObjectCreation = std::time(nullptr);
    creationTime = *std::localtime(&timeOfRequestObjectCreation);

}

//function code

// bool Booking::answerRequest() {
//     return true;
// }


void Booking::showInfo() {
    cout << "Booking ID: " << bookingID << endl;
    cout << "Host ID: " << hostMemberID << endl;
    cout << "Supporter ID: " << hostMemberID << endl;
    cout << "Time Renting " << timeRenting << endl;
    cout << "Creation time: " << getFormattedCreationTime() << endl;
    cout << "Start Renting time: " << getFormattedStartRentingTime() << endl;
    cout << "Status: " << status << endl;
}
