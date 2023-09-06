#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[nums[0]]++;
        dp[-nums[0]]++;
        for (int i{1}; i < nums.size(); ++i) {
            unordered_map<int, int> backup{std::move(dp)};
            dp.clear();
            for (auto &[k, v]: backup) {
                dp[k + nums[i]] += v;
                dp[k - nums[i]] += v;
            }
        }
        return dp[target];
    }
};

int main() {
    Solution solution;
    vector<int> nums{7,9,3,8,0,2,4,8,3,9};
    int result = solution.findTargetSumWays(nums, 0);
    cout << result << endl;
    return 0;
}