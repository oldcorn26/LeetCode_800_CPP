#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size() + 1];
        dp[0] = 0; dp[1] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            dp[i + 1] = nums[i] + dp[i - 1] > dp[i] ? nums[i] + dp[i - 1] : dp[i];
        }

        return dp[nums.size()];
    }
};

int main() {
    Solution solution;
    vector<int> nums{2,7,9,3,1};
    int result = solution.rob(nums);
    cout << result;
    return 0;
}
