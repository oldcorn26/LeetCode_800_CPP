#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int dp1[2]{-prices[0], 0}, dp2[2];
        int *pre{dp1}, *crt{dp2}, *temp;
        for (int &i: prices) {
            crt[0] = max(pre[0], pre[1] - i);
            crt[1] = max(pre[1], pre[0] + i);
            temp = pre;
            pre = crt;
            crt = temp;
        }
        return pre[0] > pre[1] ? pre[0] : pre[1];
    }
};

int main() {
    Solution solution;
    vector<int> prices{7,6,5,4,3,2,1};
    int result = solution.maxProfit(prices);
    cout << result;
    return 0;
}