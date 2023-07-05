#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(2));
        dp[0] = {0, nums[0]};
        for (int i{1}; i < size; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        return max(dp[size-1][0], dp[size-1][1]);
    }
};

int main() {
    Solution solution;
    vector<int> nums{2,7,9,3,1};
    int result = solution.rob(nums);
    cout << result;
    return 0;
}
