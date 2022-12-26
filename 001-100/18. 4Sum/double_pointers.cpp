#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int &&quarter{target / 4};
        sort(nums.begin(), nums.end());
        for (int i{0}; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] <= quarter) threeSum(nums, i + 1, target - nums[i]);
        }
        return res;
    }

    void threeSum(vector<int> &nums, int idx, long target) {
        int &&oneThird{static_cast<int>(target / 3)};
        if (nums.size() - idx < 2) return;
        for (int i{idx}; i < nums.size(); i++) {
            if (nums[i] > oneThird) return;
            if (i > idx && nums[i] == nums[i - 1]) continue;
            int &&l{i + 1}, &&r{static_cast<int>(nums.size() - 1)};
            while (l < r) {
                long &&temp{static_cast<long>(nums[l]) + nums[r] + nums[i]};
                if (temp > target) {
                    --r;
                } else if (temp < target) {
                    ++l;
                } else {
                    res.push_back({nums[idx - 1], nums[i], nums[l], nums[r]});
                    while (r > l && nums[r] == nums[r - 1]) --r;
                    while (r > l && nums[l] == nums[l + 1]) ++l;
                    ++l, --r;
                }
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{-1000000000,-1000000000,-1000000000,-1000000000};
    vector<vector<int>> result = solution.fourSum(nums, -1);
    return 0;
}