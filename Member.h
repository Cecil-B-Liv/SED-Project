#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

#include "User.h"  //include header file of the module

class Member : public User {
    private:
    string username;
    string password;
};