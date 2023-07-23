#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> dp{0, -prices[0], 0};
        for (int i{}; i < size; ++i) {
            vector<int> backup{dp};
            dp[0] = max(backup[0], backup[2]);
            dp[1] = max(backup[1], backup[0] - prices[i]);
            dp[2] = max(backup[0], dp[1] + prices[i]);
        }
        return max(dp[0], max(dp[1], dp[2]));
    }
};

int main() {
    Solution solution;
    vector<int> prices{1, 2, 3, 0, 2};
    int result = solution.maxProfit(prices);
    cout << result;
    return 0;
}
