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
    void showInfo();
    // EXTRA::void updateRating();

    string getRatingID() const { return ratingID; }

    string getMemberID() const { return memberID; }

    string getHostID() const { return hostID; }

    double getSkillRating() const { return skillRating; }

    double getSupporterRating() const { return supporterRating; }

    double getHostRating() const { return hostRating; }

    string getComments() const { return comments; }

    // Setter functions are not marked as const
    void setRatingID(const string &ratingIDVal) { this->ratingID = ratingIDVal; }

    void setMemberID(const string &memberIDVal) { this->memberID = memberIDVal; }

    void setHostID(const string &hostIDVal) { this->hostID = hostIDVal; }

    void setSkillRating(double skillRatingVal) { this->skillRating = skillRatingVal; }

    void setSupporterRating(double supporterRatingVal) { this->supporterRating = supporterRatingVal; }

    void setHostRating(double hostRatingVal) { this->hostRating = hostRatingVal; }

    void setComments(const string &commentsVal) { this->comments = commentsVal; }

};

#endif  // SED_PROJECT_RATING_Hß