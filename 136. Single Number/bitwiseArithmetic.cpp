#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];

        int ret = 0;
        for (int &i : nums) ret ^= i;

        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{4,1,2,1,2};
    int result = solution.singleNumber(nums);
    cout << result;
    return 0;
}
