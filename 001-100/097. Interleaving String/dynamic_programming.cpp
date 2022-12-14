#include <iostream>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 + len2 != s3.size()) return false;
        bool dp1[len2 + 1], dp2[len2 + 1];
        bool *pre{dp1}, *crt{dp2}, *temp;
        pre[0] = true;
        for (int j{1}; j <= len2; ++j) {
            pre[j] = pre[j - 1] && s3[j - 1] == s2[j -1];
        }

        for (int i{1}; i <= len1; ++i) {
            crt[0] = s1[i - 1] == s3[i - 1] && pre[0];
            for (int j{1}; j <= len2; ++j) {
                crt[j] = (s1[i - 1] == s3[i + j - 1] && pre[j]) || (s2[j - 1] == s3[i + j - 1] && crt[j - 1]);
            }
            temp = pre;
            pre = crt;
            crt = temp;
        }
        return pre[len2];
    }
};

int main() {
    Solution solution;
    bool result = solution.isInterleave("","","a");
    cout << result;
    return 0;
}