#define admin 0
#define user 1

#include "../Header files/Member.h"

int main() {
    vector<string> obj;
    obj.push_back("lmao");
    Member Test("lol", "lol", "lol", 1, 1, 2.3, 3.4, 5.6, obj);
    Test.showInfo();
    return 0;
}