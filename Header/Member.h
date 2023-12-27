#include "User.h"  //include header file of the module

class Member : public User {
   private:
    string username;
    string password;

   public:
    // constructor code
    Member(string username = "username", string password = "pass")
        : username(username), password(password){};

    void showInfo() {
        cout << "Username : " << username << endl;
        cout << "Password : " << password << endl;
    }

    
};