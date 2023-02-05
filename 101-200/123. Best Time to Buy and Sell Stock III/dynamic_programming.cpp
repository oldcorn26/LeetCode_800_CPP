#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {

        int size = prices.size();
        int buy1{-prices[0]}, sell1{0}, buy2{-prices[0]}, sell2{0};

        for (int i{1}; i < size; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }

        return sell2;
    }
};

int main() {
    Solution solution;
    vector<int> prices{1,2,3,4,5};
    int result = solution.maxProfit(prices);
    cout << result;
    return 0;
}
