#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPft{};
        int minPrice{prices[0]};
        for (int &i: prices) {
            maxPft = max(maxPft, i - minPrice);
            minPrice = min(minPrice, i);
        }
        return maxPft;
    }
};

int main() {
    Solution solution;
    vector<int> prices{2,1,2,1,0,1,2};
    int result = solution.maxProfit(prices);
    cout << result;
    return 0;
}
