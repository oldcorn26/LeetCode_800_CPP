#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int dp1[2], dp2[2];
        int *pre{dp1}, *crt{dp2}, *temp;
        pre[0] = s[0] != '0', pre[1] = 0;
        for (int i{1}; i < s.size(); ++i) {
            crt[0] = s[i] == '0' ? 0 : pre[0] + pre[1];
            crt[1] = (s[i - 1] - '0') * 10 + s[i] - '0' > 26 ? 0 : pre[0];
            temp = crt;
            crt = pre;
            pre = temp;
        }
        return pre[0] + pre[1];
    }
};

int main() {
    Solution solution;
    int result = solution.numDecodings("226");
    cout << result;
    return 0;
}