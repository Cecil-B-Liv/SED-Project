#include "User.h"  //include header file of the module

#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::string;

int main() {
    string skillInfo{"Teaching", "Eating"};

    User Liv("Liv","Liv","Liv","discord",12345,skillInfo);
    Liv.showInfo();

    return 0;
}