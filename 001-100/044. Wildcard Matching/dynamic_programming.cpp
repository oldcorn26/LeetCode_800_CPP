#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        if (!sLen) {
            for (char &ch: p) {
                if (ch != '*') return false;
            }
            return true;
        }
        if (!pLen) return false;

        bool dp1[sLen], dp2[sLen];
        bool *pre{dp1}, *crt{dp2}, *temp;
        bool firstFlag{p[0] == '?' || p[0] == s[0]};
        pre[0] = p[0] == '*' || p[0] == '?' || p[0] == s[0];
        for (int j{1}; j < sLen; ++j) pre[j] = p[0] == '*';

        for (int i{1}; i < pLen; ++i) {

            if (pre[0] && !firstFlag && (p[i] == s[0] || p[i] < 64)) {
                crt[0] = true;
                firstFlag = p[i] != '*';
            } else if (pre[0] && firstFlag) {
                crt[0] = p[i] == '*';
            } else crt[0] = false;

            for (int j{1}; j < sLen; ++j) {
                if (p[i] == '*') {
                    crt[j] = pre[j] || crt[j - 1];
                } else {
                    crt[j] = (p[i] == '?' || p[i] == s[j]) && pre[j - 1];
                }
            }
            temp = pre;
            pre = crt;
            crt = temp;
        }
        return pre[sLen - 1];
    }
};

int main() {
    Solution solution;
    bool result = solution.isMatch("adceb", "*a*b");
    cout << result;
    return 0;
}