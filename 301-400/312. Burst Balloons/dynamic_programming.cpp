#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int size;
    vector<vector<int>> dp;
public:
    int maxCoins(vector<int>& nums) {
        size = nums.size();
        dp = vector<vector<int>>(size+2, vector<int>(size+2, -1));
        return helper(nums, -1, size);
    }

    int helper(vector<int> &nums, int sta, int end) {
        if (sta+1 >= end)
            return 0;
        if (dp[sta+1][end+1] >= 0)
            return dp[sta+1][end+1];
        int ret{};
        int mul{(sta >= 0 ? nums[sta] : 1) * (end < size ? nums[end] : 1)};
        for (int i{sta+1}; i < end; ++i) {
            ret = max(ret, mul * nums[i] + helper(nums, sta, i) + helper(nums, i, end));
        }
        return dp[sta+1][end+1] = ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,5};
    int result = solution.maxCoins(nums);
    cout << result;
    return 0;
}
