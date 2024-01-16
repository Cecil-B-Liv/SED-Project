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
    cout << "Rating ID: " << ratingID;
    cout << "Member ID: " << memberID;
    cout << "Host ID: " << hostID;
    cout << "Supporter Rating: " << supporterRating;
    cout << "Host Rating: " << hostRating;
    cout << "Comment: " << comments;
}

// void addReview(Member &member)
// {
//     double sup_score = 0;
//     double skill_score = 0;
//     double host_score = 0;
//     string comment;
//     if (member.isHost == true)
//     {
//         std::cout << "Enter a  score for the supporter's performance (1 - 5): ";
//         std::cin >> sup_score;
//         std::cin.ignore(); // ignore newline character
//         std::cout << "Enter a score for the supporter's skill (1 - 5): ";
//         std::cin >> skill_score;
//         std::cin.ignore(); // ignore newline character
//         std::cout << "Enter a comment for the supporter: ";
//         std::getline(std::cin, comment);
//         std::cout << "Host " << m.getFullName() << " rate the supporter " << sup_score << " for performance and "
//                   << skill_score << " for skill of the supporter";
//         std::cout << " with the comment: "
//                   << comment << std::endl;
//     }
//     else
//     {
//         std::cout << "Enter a score for the host (1 - 5): ";
//         std::cin >> host_score;
//         std::cin.ignore(); // ignore newline character
//         std::cout << "Enter a comment for the host: ";
//         std::getline(std::cin, comment);
//         std::cout << "Supporter " << m.getFullName() << " rated the host: " << host_score;
//         std::cout << " , with the comment: "
//                   << comment << "." << std::endl;
//     }
// }