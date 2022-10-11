#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i;
        p = standardization(p);
        int sLen = s.length();
        int pLen = p.length();
        bool dp[sLen][pLen];

        //Handle the first line.
        for (i = 0; i < pLen; ++i) {
            int flagOfLower = 0;
            int upperCaseNum = 0;
            bool haveLetter = false;
            for (int temp = 0; temp <= i; ++temp) {
                if (p[temp] + 32 == s[0] || p[temp] + 32 == '.') haveLetter = true;
                if (!(p[temp] >= 'a' || p[temp] == '.')) ++upperCaseNum; else flagOfLower = temp;
            }
            if (upperCaseNum == i + 1 && haveLetter) {
                dp[0][i] = true;
            } else if (upperCaseNum == i) {
                dp[0][i] = p[flagOfLower] == s[0] || p[flagOfLower] == '.';
            } else dp[0][i] = false;
        }

        //Handle the first column.
        for (i = 1; i < sLen; ++i) {
            if (p[0] + 32 == '.') {
                dp[i][0] = dp[i - 1][0];
            } else if (p[0] <= 'Z' && p[0] >='A') {
                dp[i][0] = s[i] == p[0] + 32 && dp[i - 1][0];
            } else dp[i][0] = false;
        }

        //Handle the rest.
        for (int j = 1; j < pLen; ++j) {
            for (i = 1; i < sLen; ++i) {
                if (p[j] + 32 == '.') {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 1];
                } else if (p[j] <= 'Z' && p[j] >= 'A') {
                    dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - 1]) && s[i] == p[j] + 32 || dp[i][j - 1];
                } else dp[i][j] = (p[j] == '.' || s[i] == p[j]) && dp[i - 1][j - 1];
            }
        }

//        for (i = 0; i < sLen; ++i) {
//            for (int j = 0; j < pLen; ++j) {
//                cout << dp[i][j] << "  ";
//            }
//            cout << endl;
//        }

        return dp[sLen - 1][pLen - 1];
    }


    /**
     * Turn the 'x*' combination to (char) x - 32.
     * @param s is the input string.
     * @return standardized string.
     */
    static string standardization(string s) {
        int i;
        int length = s.length();
        string sTemp = "";

        //Handle the continuous *.
        for (i = 0; i < length; ++i) {
            if (s[i] == '*') {
                int temp = i;
                while (s[temp + 1] == '*' && temp + 1 < length) {
                    ++temp;
                }
                sTemp += '*';
                i = temp;
            } else sTemp += s[i];
        }
        length = sTemp.length();
        s = "";

        //Handle the 'x*' combination.
        for (i = 0; i < length; ++i) {
            if (i + 1 < length && sTemp[i + 1] == '*') {
                s += (char) (sTemp[i] - 32);
                ++i;
                continue;
            }
            s += sTemp[i];
        }
        return s;
    }
};

int main() {
    Solution solution;
    string s = "aaa";
    string p = "ab*ac*a";
    bool result = (bool) solution.isMatch(s, p);
    cout << result;
    return 0;
}