#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size(), temp = 1;
        vector<int> res(size); res[0] = 1;

        for (int i = 1; i < size; ++i) {
            temp *= nums[i - 1];
            res[i] = temp;
        }
        temp = 1;
        for (int i = size - 2; i >= 0; --i) {
            temp *= nums[i + 1];
            res[i] *= temp;
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{-1,1,0,-3,3};
    vector<int> result = solution.productExceptSelf(nums);
    return 0;
}
