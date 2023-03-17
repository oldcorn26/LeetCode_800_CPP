#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int idx2{}, idx3{}, idx5{};
        vector<int> dp(n);
        dp[0] = 1;
        for (int i{1}; i < n; ++i) {
            int temp2{dp[idx2] * 2};
            int temp3{dp[idx3] * 3};
            int temp5{dp[idx5] * 5};
            dp[i] = ::min(temp2, ::min(temp3, temp5));
            if (dp[i] == temp2) idx2++;
            if (dp[i] == temp3) idx3++;
            if (dp[i] == temp5) idx5++;
        }
        return dp[n-1];
    }
};

int main() {
    Solution solution;
    return 0;
}
