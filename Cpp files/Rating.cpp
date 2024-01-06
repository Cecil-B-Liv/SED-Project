#include <utility>

#include "../Header files/INCLUDEHEADERS.h"

Rating::Rating(string ratingID, string memberID, string hostID, double skillRating,
               double supporterRating, double hostRating, string comments) {
    this->ratingID = ratingID;
    this->memberID = memberID;
    this->hostID = hostID;
    this->skillRating = skillRating;
    this->supporterRating = supporterRating;
    this->hostRating = hostRating;
    this->comments = comments;
}

void Rating::showInfo() {

}