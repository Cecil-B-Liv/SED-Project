#ifndef SED_PROJECT_RATING_H
#define SED_PROJECT_RATING_H

#include "BasicSTDLIB.h"
#include "Member.h"

class Rating {
   private:
    string ratingID;
    string memberRating;

    double skillRating;
    double supporterRating;
    double hostRating;
    string comments;

   public:
   //constructor code
    Rating(string, string, double, double, double, string);
    //function code
    void addReview();
    // EXTRA::void updateRating();
};

#endif  // SED_PROJECT_RATING_H