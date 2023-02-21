#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ret{nums[0]};
        int minPrefix{INT32_MAX}, crtSum{0};
        for (int &i: nums) {
            minPrefix = min(minPrefix, crtSum);
            crtSum += i;
            ret = max(ret, crtSum - minPrefix);
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{-2};
    int result = solution.maxSubArray(nums);
    cout << result;
    return 0;
}
