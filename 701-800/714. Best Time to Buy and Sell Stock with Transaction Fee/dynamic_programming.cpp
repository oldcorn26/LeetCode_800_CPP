#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {

        int size = prices.size();
        int hold{-prices[0]}, notHold{0};

        for (int i{0}; i < size; ++i) {
            int preNotHold{notHold};
            notHold = max(notHold, hold + prices[i] - fee);
            hold = max(preNotHold - prices[i], hold);
        }

        return max(hold, notHold);
    }
};

int main() {
    Solution solution;
    vector<int> prices{1, 3, 2, 8, 4, 9};
    int result = solution.maxProfit(prices, 2);
    cout << result;
    return 0;
}
