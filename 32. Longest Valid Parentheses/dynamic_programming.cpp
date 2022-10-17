#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        if (!s.size()) return 0;
        int dp[s.size()];

        dp[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') dp[i] = (i - 2 < 0 ? 0 : dp[i - 2]) + 2;
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                else dp[i] = 0;
            } else dp[i] = 0;
            if (dp[i]) maxLen = dp[i] > maxLen ? dp[i] : maxLen;
        }

        return maxLen;
    }
};

int main(){
    Solution solution;
    string s = "())";
    cout << solution.longestValidParentheses(s);
    return 0;
}
