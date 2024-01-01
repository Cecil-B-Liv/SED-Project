#ifndef SED_PROJECT_RATING_H
#define SED_PROJECT_RATING_H

#include "BasicSTDLIB.h"
#include "Member.h"

class Rating {
   private:
    string ratingID;
    string memberID;
    string hostID;

    double skillRating;
    double supporterRating;
    double hostRating;
    string comments;

   public:
    // constructor code
    Rating(string, string, string, double, double, double, string);
    // function code
    void addReview();
    // EXTRA::void updateRating();

    // Accessor methods
    string getRatingID() { return ratingID; }

    void setRatingID(string ratingID) { this->ratingID = ratingID; }

    string getMemberID() { return memberID; }

    void setMemberID(string memberID) { this->memberID = memberID; }

    string getHostID() { return hostID; }

    void setHostID(string hostID) { this->hostID = hostID; }

    double getSkillRating() { return skillRating; }

    void setSkillRating(double skillRating) { this->skillRating = skillRating; }

    double getSupporterRating() { return supporterRating; }

    void setSupporterRating(double supporterRating) {
        this->supporterRating = supporterRating;
    }

    double getHostRating() { return hostRating; }

    void setHostRating(double hostRating) { this->hostRating = hostRating; }

    string getComments() { return comments; }

    void setComments(string comments) { this->comments = comments; }
};

#endif  // SED_PROJECT_RATING_H