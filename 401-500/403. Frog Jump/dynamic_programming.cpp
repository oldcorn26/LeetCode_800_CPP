#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool canCross(vector<int> &stones) {
        int size = stones.size();
        bool dp[size][size + 1];
        memset(dp, 0, sizeof(dp));
        if (stones[1] != 1) return false;
        dp[1][1] = true;
        for (int i{2}; i < size; ++i) {
            for (int j{1}; j < i; j++) {
                int dis{stones[i] - stones[j]};
                if (dis <= j + 1) dp[i][dis] = dp[j][dis - 1] || dp[j][dis] || dp[j][dis + 1];
            }
        }
        for (int i = 1; i < size; i++) {
            if (dp[size - 1][i]) return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums{0,1,3,5,6,8,12,17};
    bool result = solution.canCross(nums);
    cout << result;
    return 0;
}
