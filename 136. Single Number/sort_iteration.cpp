#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];

        sort(nums.begin(), nums.end());
        for (int i = 1; i < size; i+=2) if (nums[i] != nums[i - 1]) return nums[i - 1];

        return nums[size - 1];
    }
};

int main() {
    Solution solution;
    vector<int> nums{4,1,2,1,2};
    int result = solution.singleNumber(nums);
    cout << result;
    return 0;
}
