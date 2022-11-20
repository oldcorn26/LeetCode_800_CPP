#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int pre = 0, maxAns = nums[0];
        for (int &i: nums) {
            pre = pre + i > i ? pre + i : i;
            maxAns = pre > maxAns ? pre : maxAns;
        }

        return maxAns;
    }
};

int main() {
    Solution solution;
    vector<int> nums{8,-19,5,-4,20};
    int result = solution.maxSubArray(nums);
    cout << result;
    return 0;
}