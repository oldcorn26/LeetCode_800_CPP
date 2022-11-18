#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if (!m || !n) return m + n;
        int dp[m][n], flag = 0;

        for (int i = 0; i < m; ++i) {
            if (!flag && word2[0] == word1[i]) flag = 1;
            dp[i][0] = i + 1 - flag;
        }
        flag = 0;
        for (int j = 0; j < n; ++j) {
            if (!flag && word1[0] == word2[j]) flag = 1;
            dp[0][j] = j + 1 - flag;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (word1[i] == word2[j]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution solution;
    int result = solution.minDistance("horse", "ros");
    cout << result;
    return 0;
}
