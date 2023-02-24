#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i{3}; i <= n; ++i) {
            for (int j{1}; j <= i / 2; ++j) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    int result = solution.integerBreak(10);
    cout << result;
    return 0;
}
