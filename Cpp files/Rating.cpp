#include <utility>

#include "../Header files/INCLUDEHEADERS.h"

Rating::Rating(string ratingID, string memberID, string hostID,
               double skillRating, double supporterRating, double hostRating,
               string comments) {
    this->ratingID = ratingID;
    this->memberID = memberID;
    this->hostID = hostID;
    this->skillRating = skillRating;
    this->supporterRating = supporterRating;
    this->hostRating = hostRating;
    this->comments = comments;
}

void Rating::showInfo() {
    cout << COLOR_GREEN << "Rating ID: " << COLOR_RESET << ratingID << endl;
    cout << COLOR_CYAN << " Member ID: " << COLOR_RESET << memberID << endl;
    cout << COLOR_CYAN << " Host ID: " << COLOR_RESET << hostID << endl;
    cout << COLOR_BLUE << " Supporter Rating: " << COLOR_RESET
         << supporterRating << endl;
    cout << COLOR_BLUE << " Host Rating: " << COLOR_RESET << hostRating << endl;
    cout << COLOR_BLUE << " Comment: " << COLOR_RESET << comments << endl;
}