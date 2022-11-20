#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        int maxLen = 1;
        int start = 0;
        bool dp[length][length];

        for (int i = 0; i < length; ++i) {
            dp[i][i] = true;
        }

        for (int j = 1; j < length; ++j) {
            for (int i = 0; i < j; ++i) {
                if (checkIfSame(s, j, i)) {
                    dp[i][j] = j - i == 1 || dp[i + 1][j - 1];
                } else {
                    dp[i][j] = false;
                }
                if (dp[i][j] && maxLen < j - i + 1) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }

    static bool checkIfSame(string &s, int &flag1, int &flag2) {
        if (flag1 < 0 || flag2 >= s.length()) {
            return false;
        } else {
            return s[flag1] == s[flag2];
        }
    }
};

int main() {
    string s = "laa";
    Solution solution;
    cout << solution.longestPalindrome(s);
    return 0;
}
