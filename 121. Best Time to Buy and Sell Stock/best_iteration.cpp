#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int head = prices[0], size = prices.size(), i, res = 0;
        for (i = 1; i < size; ++i) {
            if (head >= prices[i]) head = prices[i];
            else break;
        }
        if (i-- == size) return 0;

        int min = INT32_MAX, max = INT32_MIN;
        for (; i < size; ++i) {
            if (prices[i] >= min) continue;
            else {min = prices[i]; max = INT32_MIN;}
            for (int j = i + 1; j < size; ++j) {
                if (prices[j] <= max) continue;
                else max = prices[j];
                res = prices[j] - prices[i] > res ? prices[j] - prices[i] : res;
            }
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
