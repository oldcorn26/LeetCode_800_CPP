#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {

        int dpSize{2 * k};
        int dp[dpSize];

        for (int i{0}; i < dpSize; ++i) dp[i] = i % 2 ? 0 : -prices[0];

        for (int i{1}; i < prices.size(); ++i) {
            dp[0] = max(dp[0], -prices[i]);
            for (int j{1}; j < dpSize; ++j) {
                dp[j] = max(dp[j], dp[j - 1] + (j % 2 ? prices[i] : -prices[i]));
            }
        }

        return dp[dpSize - 1];
    }
};

int main() {
    Solution solution;
    vector<int> prices{3,2,6,5,0,3};
    int result = solution.maxProfit(2, prices);
    cout << result;
    return 0;
}
