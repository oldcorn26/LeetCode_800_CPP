#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int p2{0}, p3{0}, p5{0};
        vector<int> dp(n);
        dp[0] = 1;
        for (int i{1}; i < n; ++i) {
            int res2{dp[p2] * 2};
            int res3{dp[p3] * 3};
            int res5{dp[p5] * 5};
            int minRes{min(res2, min(res3, res5))};
            if (minRes == res2) ++p2;
            if (minRes == res3) ++p3;
            if (minRes == res5) ++p5;
            dp[i] = minRes;
        }

        return dp[n - 1];
    }
};

int main() {
    Solution solution;
    int result = solution.nthUglyNumber(10);
    cout << result;
    return 0;
}
