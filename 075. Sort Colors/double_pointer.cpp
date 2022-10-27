#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, &&j = nums.size() - 1;

        for (int k = i; k <= j; ++k) {
            if (!nums[k]) {nums[k] = nums[i]; nums[i++] = 0;}
            else if (nums[k] == 2) {nums[k] = nums[j]; nums[j--] = 2; --k;}
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 2, 2, 2, 2, 0, 0, 0, 1, 1};
    solution.sortColors(nums);
    return 0;
}
