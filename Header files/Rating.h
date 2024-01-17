#ifndef SED_PROJECT_RATING_H
#define SED_PROJECT_RATING_H

#include "BasicSTDLIB.h"
#include "Member.h"

class Rating {
   private:
    string ratingID;
    string memberID;
    string hostID;

    // all score ratings which can vary from 1 to 5
    // rate the supporter for the skill performed
    double skillRating;
    // (how well this supporter helped the hosts)
    double supporterRating;
    //(how kind this host treated the supporters)
    double hostRating;
    string comments;

   public:
    // constructor code
    explicit Rating(string = "", string = "", string = "", double = 0.0,
                    double = 0.0, double = 0.0, string = "");

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
    void setRatingID(const string &ratingIDVal) {
        this->ratingID = ratingIDVal;
    }

    void setMemberID(const string &memberIDVal) {
        this->memberID = memberIDVal;
    }

    void setHostID(const string &hostIDVal) { this->hostID = hostIDVal; }

    void setSkillRating(double skillRatingVal) {
        this->skillRating = skillRatingVal;
    }

    void setSupporterRating(double supporterRatingVal) {
        this->supporterRating = supporterRatingVal;
    }

    void setHostRating(double hostRatingVal) {
        this->hostRating = hostRatingVal;
    }

    void setComments(const string &commentsVal) {
        this->comments = commentsVal;
    }
};

#endif  // SED_PROJECT_RATING_Hß