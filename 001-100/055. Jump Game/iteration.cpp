#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;

        int maxFlag = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (i > maxFlag) return false;
            maxFlag = i + nums[i] > maxFlag ? i + nums[i] : maxFlag;
            if (maxFlag >= nums.size() - 1) return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 1};
    bool result = solution.canJump(nums);
    cout << result;
    return 0;
}