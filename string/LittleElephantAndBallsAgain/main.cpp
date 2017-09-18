#include <iostream>
#include "LittleElephantAndBallsAgain.cpp"
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    LittleElephantAndBallsAgain S1;
    string str1;
    while(getline(cin, str1)) {
        cout << S1.getNumber(str1) << endl;
    }
    return 0;
}
