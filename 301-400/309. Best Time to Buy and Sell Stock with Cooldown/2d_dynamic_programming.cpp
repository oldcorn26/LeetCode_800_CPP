#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int &&size = prices.size();
        int dp[3]{-prices[0], 0, 0};

        for (int i = 1; i < size; ++i) {
            int temp0 = dp[0], temp2 = dp[2];
            dp[0] = max(temp2 - prices[i], temp0);
            dp[2] = dp[1] > temp2 ? dp[1] : temp2;
            dp[1] = temp0 + prices[i];
        }
        return dp[1] > dp[2] ? dp[1] : dp[2];
    }
};

int main() {
    Solution solution;
    vector<int> prices{1, 2, 3, 0, 2};
    int result = solution.maxProfit(prices);
    cout << result;
    return 0;
}