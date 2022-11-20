#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int max = nums[0], min = nums[0], res = nums[0];

        for (int i = 1; i < size; ++i) {
            int &&maxTemp = max * nums[i], &&minTemp = min * nums[i];
            if (maxTemp < minTemp) {int temp = maxTemp; maxTemp = minTemp; minTemp = temp;}

            max = maxTemp > nums[i] ? maxTemp : nums[i];
            min = minTemp < nums[i] ? minTemp : nums[i];
            res = max > res ? max : res;
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{-2, 3, -4};
    int result = solution.maxProduct(nums);
    cout << result;
    return 0;
}
