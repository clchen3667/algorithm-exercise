#include <string>
using namespace std;
bool equal_typo(string s1, string s2) {
    int count = 0;
    for (int i = 0;i < s1.length();i++) {
        if (s1[i] != s2[i]) {
             ++count;
            if (count > 2)
                return false;
        }
    }
    return true;
}

bool diff1_typo(string s1, string s2) {
    string a,b;
    int l1 = (int)s1.length(), l2 = (int)s2.length(), diff = 0;
    if (l1 < l2) {
        a = s1;
        b = s2;
    } else {
        a = s2;
        b = s1;
    }
    int j = 0;
    for (int i = 0;i < a.length();) {
        if (a[i] != b[j]) {
            ++diff;
            if (diff > 1)
                return false;
        } else
            ++i;
        ++j;
    }
    return true;
}
