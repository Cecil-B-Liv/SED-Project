#include "../Header files/INCLUDEHEADERS.h"

#define ONLINE 1
#define OFFLINE -1

// Constructor
Request::Request() {
    std::time_t timeOfRequestObjectCreation = std::time(nullptr);
    creationTime = *std::localtime(&timeOfRequestObjectCreation);
}

//function code
bool Request::answerRequest() {
    return true;
}

void Request::showInfo() {

}
