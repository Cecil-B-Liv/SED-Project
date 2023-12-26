#include <cstring>
#include <iostream>
#include <string>
// include header file of the module
#include "Member.h"  //include the User.h already

#define admin 0
#define user 1

using std::cout;
using std::string;

int main() {
    Member Liv("Liv", "Liv");
    Liv.showInfo();

    return 0;
}