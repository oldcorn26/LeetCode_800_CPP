#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int prePcs{1};
        for (; prePcs < nums.size() && nums[prePcs] == nums[prePcs - 1]; ++prePcs);
        if (prePcs == nums.size()) return 1;

        int len{2}, pre{nums[prePcs]};
        bool mode{nums[prePcs] > nums[prePcs - 1]};
        for (int i{prePcs + 1}; i < nums.size(); ++i) {
            if (nums[i] > pre) {
                len += mode ? 0 : 1;
                mode = true;
            } else if (nums[i] < pre) {
                len += mode ? 1 : 0;
                mode = false;
            }
            pre = nums[i];
        }
        return len;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,1,1,1};
    int result = solution.wiggleMaxLength(nums);
    cout << result;
    return 0;
}