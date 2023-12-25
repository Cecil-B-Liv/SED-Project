#include <cstring>
#include <iostream>
#include <string>

#include "User.h"  //include header file of the module

using std::cout;
using std::string;

int main() {
    vector<string> skillExist{};

    User Liv("Liv", "Liv", "Liv", "discord", 12345, 100, 100, skillExist);
    Liv.showInfo();

    return 0;
}