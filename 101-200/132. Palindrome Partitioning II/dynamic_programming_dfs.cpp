#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<bool>> dp;
    vector<int> memo;
public:
    int minCut(string s) {
        int size = s.size();
        dp = vector<vector<bool>>(size, vector<bool>(size));
        memo = vector<int>(size);

        for (int i{size - 1}; i >= 0; --i) {
            dp[i][i] = true;
            for (int j{i + 1}; j < size; ++j) {
                dp[i][j] = s[i] == s[j] && (i + 2 > j || dp[i + 1][j - 1]);
            }
        }

        return dfs(s, 0) - 1;
    }

    int dfs(string &s, int sIdx) {

        if (sIdx == s.size()) return 0;
        if (memo[sIdx]) return memo[sIdx];

        int min{INT32_MAX};

        for (int i = s.size() - 1; i >= 0; --i) {
            if (!dp[sIdx][i]) continue;
            int next{dfs(s, i + 1)};
            if (next == -1) continue;
            min = 1 + next < min ? 1 + next : min;
        }
        return memo[sIdx] = min == INT32_MAX ? -1 : min;
    }
};

int main() {
    Solution solution;
    int result = solution.minCut("aaabaa");
    cout << result;
    return 0;
}
