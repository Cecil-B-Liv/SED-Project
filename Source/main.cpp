#define admin 0
#define user 1

#include "../Header files/INCLUDEHEADERS.h"

int main() {

    // how to use vector of pointers
    vector<string *> testVector;

    string test1 = "info1";
    string test2 = "info2";

    string *ptest2 = &test2; // pointer ptest2 points to address of test2

    // 1st method
    testVector.push_back(&test1); // vector of pointers store the address of the data with no additional pointer

    // 2nd method
    testVector.push_back(ptest2); // vector of pointers store the pointer that stores the address of data

    // 1st method
    cout << *testVector[0] << endl; // dereference and get the value at index 0

    // 2nd method
    cout << *(*(testVector.begin() + 1)) << endl; // the first * indicate the position of the pointer in the vector,
    // the second * dereference that pointer to get the value

    // loops through the vector of points using a pointer
    for (string *ptr: testVector) {
        cout << *ptr << endl; // dereference and get the value
    }

    testVector.erase(testVector.begin() + 1); // erase value at index 1
    // loops through the vector of points using a pointer
    for (string *ptr: testVector) {
        cout << *ptr << endl; // dereference and get the value
    }
//    UI::Start(); // Start and initialize everything
    return 0;
}