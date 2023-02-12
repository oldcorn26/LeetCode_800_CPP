#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {

        int minCount{0}, maxCount{0};

        for (int i{0}; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++minCount, ++maxCount;
            } else if (s[i] == ')') {
                minCount = max(minCount - 1, 0);
                if (--maxCount < 0) return false;
            } else {
                minCount = max(minCount - 1, 0);
                ++maxCount;
            }
        }

        return minCount == 0;
    }
};

int main() {
    Solution solution;
    bool result = solution.checkValidString("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())");
    cout << result;
    return 0;
}
