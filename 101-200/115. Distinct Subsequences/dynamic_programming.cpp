#include <iostream>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {

        int count{0};
        unsigned long long dp1[s.size()], dp2[s.size()];
        unsigned long long *pre{dp1}, *crt{dp2}, *temp;

        for (int j{0}; j < s.size(); ++j) {
            if (s[j] == t[0]) ++count;
            pre[j] = count;
        }

        for (int i{1}; i < t.size(); ++i) {
            crt[0] = 0;
            for (int j{1}; j < s.size(); ++j) {
                unsigned long long &&tempSum{crt[j - 1] + (t[i] == s[j] ? pre[j - 1] : 0)};
                crt[j] = tempSum;
            }
            temp = pre;
            pre = crt;
            crt = temp;
        }

        return pre[s.size() - 1];
    }
};

int main() {
    Solution solution;
    int result = solution.numDistinct("babgbag", "bag");
    cout << result;
    return 0;
}
