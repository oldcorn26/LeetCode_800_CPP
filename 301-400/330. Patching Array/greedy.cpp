#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res{0}, index{0}, len = nums.size();
        long x{1};
        while (x <= n) {
            if (index < len && nums[index] <= x) {
                x += nums[index];
                ++index;
            } else {
                x *= 2;
                ++res;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2,3};
    int result = solution.minPatches(nums, 20);
    cout << result;
    return 0;
}