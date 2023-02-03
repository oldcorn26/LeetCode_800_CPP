#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {

        int len = nums.size() - 1;
        if (len == 0) return nums[0];
        int rest1{0}, rob1{nums[0]}, rest2{0}, rob2{nums[1]};

        for (int i{1}; i < len; ++i) {
            int temp1{rest1}, temp2{rest2};
            rest1 = max(rest1, rob1);
            rest2 = max(rest2, rob2);
            rob1 = temp1 + nums[i];
            rob2 = temp2 + nums[i + 1];
        }

        return max(max(rest1, rest2), max(rob1, rob2));
    }
};

int main() {
    Solution solution;
    vector<int> nums{2,3,2};
    int result = solution.rob(nums);
    cout << result;
    return 0;
}
