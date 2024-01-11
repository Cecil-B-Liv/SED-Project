#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

class Rating;


class Member{
protected:
    string name;
    string memID;
    bool isHost = 0; //member is supporter


public: 
    Member(string name = "", string memID = "", bool isHost = false)
    : name(name), memID(memID), isHost(isHost){}

     void showInfo(){
        cout << "\nName: " << name << ", ID: " << memID << ", " << (isHost ? "Host" : "Supporter" ) << "\n"; 
    }

    friend void addReview(Member &m);
    
};

class Rating : public Member{
private:

    double skillRating;
    double supporterRating;
    double hostRating;

public:
    //constructor
    Rating(string name = "", string memID = "",  double skillRating = 0, 
    double supporterRating = 0, double hostRating = 0)
    : Member(name, memID), skillRating(skillRating), 
    supporterRating(supporterRating), hostRating(hostRating){}

    void showRating(){
        cout << "\nSupporter Rating: " << supporterRating << " , skill Rating: " << skillRating
        << " , host Rating: " << hostRating << "\n";
    }

    friend void addReview( Member &m);
};

        void addReview( Member &m){
        double sup_score = 0;
        double host_score = 0;
        string comment;
        if (m.isHost == true){
            std::cout << "Enter a score for the supporter: ";
            std::cin >> sup_score;
            std::cin.ignore();  // ignore newline character
            
            std::cout << "Enter a comment for the supporter: ";
            std::getline(std::cin, comment);
            std::cout << "Host " << m.name << " rate the supporter " << sup_score;
            std::cout << " with the comment: " 
            << comment << std::endl;
        } else {
            std::cout << "Enter a score for the host: ";
            std::cin >> host_score;
            std::cin.ignore();  // ignore newline character
            std::cout << "Enter a comment for the host: ";
            std::getline(std::cin, comment);
            std::cout << "Supporter " << m.name << " rated the host: " << host_score;
            std::cout << " , with the comment: " 
            << comment <<  "."<<std::endl; 
        }
    }

int main(){


    // Member m1 ("John", "user1", 1);
    // Member m2 ("Steve", "user2", 0);
    // Rating r1 ("John", "user1", 3, 5, 3.5);
    // m1.showInfo();
    // r1.showRating();
    // //addReview(m1);
    // addReview(m2);

   
    


    
    return 0;
}