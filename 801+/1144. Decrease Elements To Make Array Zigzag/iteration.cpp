#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int> &nums) {
        if (nums.size() == 1) return 0;
        int ans[2]{max(0, nums[0] - nums[1] + 1), 0};
        for (int i{1}; i + 1 < nums.size(); ++i) {
            ans[i % 2] += max(0, nums[i] - min(nums[i-1], nums[i+1]) + 1);
        }
        ans[(nums.size() - 1) % 2] += max(0, nums[nums.size() - 1] - nums[nums.size() - 2] + 1);
        return min(ans[0], ans[1]);
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2,3};
    int result = solution.movesToMakeZigzag(nums);
    cout << result;
    return 0;
}
