#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> dp;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        if (maxChoosableInteger >= desiredTotal) return true;
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
        dp = vector<int>(1 << maxChoosableInteger);

        return dfs(0, maxChoosableInteger, desiredTotal) == 1;
    }

    int dfs(int state, int max, int desired) {
        if (dp[state] != 0) return dp[state];
        for (int i{max - 1}; i >= 0; --i) {
            if (((state >> i) & 1) == 1) continue;
            if (i + 1 >= desired) return dp[state] = 1;
            if (dfs(state | (1 << i), max, desired - i - 1) == -1) return dp[state] = 1;
        }
        return dp[state] = -1;
    }
};

int main() {
    Solution solution;
    bool result = solution.canIWin(20, 201);
    cout << result;
    return 0;
}
