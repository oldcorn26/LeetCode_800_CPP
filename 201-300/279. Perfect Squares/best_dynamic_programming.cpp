#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> squareMemo;
    vector<int> dp{0};
public:
    int numSquares(int n) {
        if (squareMemo.empty())
            for (int i{1}; i * i <= n; ++i)
                squareMemo.emplace_back(i * i);
        if (n <= dp.size()-1)
            return dp[n];
        int minCost{INT32_MAX};
        for (int i: squareMemo) {
            if (i > n)
                break;
            minCost = min(minCost, numSquares(n-i));
        }
        dp.emplace_back(minCost + 1);
        return minCost + 1;
    }
};

int main() {
    Solution solution;
    int result = solution.numSquares(4);
    cout << result;
    return 0;
}
