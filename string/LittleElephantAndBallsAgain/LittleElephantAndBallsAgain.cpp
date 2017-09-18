#ifndef LittleElephantAndBallsAgain_h
#define LittleElephantAndBallsAgain_h
#include <string>
#include <iostream>
using namespace std;

class LittleElephantAndBallsAgain {
public:
    int getNumber(string s) {
        int max_count = 0;
        if (s.length() <= 1)
            return 0;
        char cur = s[0];
        int cur_count = 0;
        for (auto c : s) {
            if(c == cur) {
                ++cur_count;
            } else {
                max_count = max(max_count, cur_count);
                cur_count = 1;
                cur = c;
            }
        }
        return (int)s.length() - max_count;
    }
private:
};




#endif /* LittleElephantAndBallsAgain_h */
