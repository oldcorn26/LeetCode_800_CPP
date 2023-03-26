#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        auto checkMatch = [](char i, char j) {
            return i == j || j == '.';
        };

        int starNum{};
        vector<vector<bool>> dp(s.size(), vector<bool>(p.size()));
        dp[0][0] = checkMatch(s[0], p[0]);
        for (int j{1}; j < p.size(); ++j) {
            if (p[j] != '*')
                dp[0][j] = checkMatch(s[0], p[j]) && starNum == (j-starNum);
            else if (!checkMatch(s[0], p[j-1])) {
                starNum++;
                dp[0][j] = j - 2 >= 0 && dp[0][j - 2];
            } else {
                starNum++;
                dp[0][j] = (j-2 < 0 ? 0 : dp[0][j-2]) || starNum == (j+1-starNum);
            }
        }
        for (int i{1}; i < s.size(); ++i) {
            for (int j{}; j < p.size(); ++j) {
                if (p[j] != '*') {
                    dp[i][j] = checkMatch(s[i], p[j]) && (j >= 1) && dp[i-1][j-1];
                } else if (!checkMatch(s[i], p[j-1])) {
                    dp[i][j] = j >= 2 && dp[i][j-2];
                } else {
                    dp[i][j] = (j >= 2 && dp[i][j-2]) || dp[i-1][j];
                }
            }
        }
        return dp[s.size()-1][p.size()-1];
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
