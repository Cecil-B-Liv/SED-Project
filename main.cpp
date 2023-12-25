#include <cstring>
#include <iostream>
#include <string>
// include header file of the module
#include "Member.h"

#define admin 0
#define user 1

using std::cout;
using std::string;

int main() {
    vector<string> skillExist{};

    User Liv("Liv", "Liv", "discord", 12345, 100, 100, 1, skillExist);
    Liv.showInfo();

    return 0;
}