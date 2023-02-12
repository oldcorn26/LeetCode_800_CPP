#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {

        int left{0}, star1{0};
        int right{0}, star2{0};

        for (char &ch: s) {
            if (ch == '(') ++left;
            else if (ch == '*') ++star1;
            else if (left > 0) --left;
            else if (star1 > 0) --star1;
            else return false;
        }
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') ++right;
            else if (s[i] == '*') ++star2;
            else if (right > 0) --right;
            else if (star2 > 0) --star2;
            else return false;
        }

        return star1 >= left && star2 >= right;
    }
};

int main() {
    Solution solution;
    bool result = solution.checkValidString("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())");
    cout << result;
    return 0;
}
