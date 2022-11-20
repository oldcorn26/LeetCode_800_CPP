#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int &i: nums) {
            if (i) nums[idx++] = i;
        }
        for (; idx < nums.size(); ++idx) nums[idx] = 0;
    }
};

int main() {
    Solution solution;
    vector<int> nums{0};
    solution.moveZeroes(nums);
    return 0;
}
