#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() < 3) return nums[0];

        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

int main() {
    Solution solution;
    vector<int> nums{2,2,1,1,1,2,2};
    int result = solution.majorityElement(nums);
    cout << result;
    return 0;
}
