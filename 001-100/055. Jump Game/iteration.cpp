#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farIdx{};
        for (int i{}; i < nums.size() && i <= farIdx; ++i)
            farIdx = max(farIdx, i+nums[i]);
        return farIdx+1 >= nums.size();
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 1};
    bool result = solution.canJump(nums);
    cout << result;
    return 0;
}