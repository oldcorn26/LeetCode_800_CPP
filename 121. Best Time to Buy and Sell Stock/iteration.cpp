#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min= prices[0], size = prices.size(), res = 0;

        for (int i = 0; i < size; ++i) {
            min = prices[i] < min ? prices[i] : min;
            res = prices[i] - min > res? prices[i] - min : res;
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> prices{2,1,2,1,0,1,2};
    int result = solution.maxProfit(prices);
    cout << result;
    return 0;
}
