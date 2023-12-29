#include "../Header files/Rating.h"

Rating::Rating(string ratingID, string memberRating, double skillRating,
               double supporterRating, double hostRating, string comments) {
    this->ratingID = ratingID;
    this->memberRating = memberRating;
    this->skillRating = skillRating;
    this->supporterRating = supporterRating;
    this->hostRating = hostRating;
    this->comments = comments;
}

void Rating::addReview(){
}