#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroIdx = 0, twoIdx = nums.size() - 1;
        for (int i{zeroIdx}; i <= twoIdx; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[zeroIdx]);
                zeroIdx++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[twoIdx]);
                twoIdx--;
                i--;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 2, 2, 2, 2, 0, 0, 0, 1, 1};
    solution.sortColors(nums);
    return 0;
}
