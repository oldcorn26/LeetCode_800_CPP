#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int halfSize = nums.size() / 2;
        if (nums.size() < 3) return nums[0];

        unordered_map<int, int> map;

        for (int &i: nums) {
            if (++map[i] > halfSize) return i;
        }

        return 0;
    }
};

int main() {
    Solution solution;
    vector<int> nums{2,2,1,1,1,2,2};
    int result = solution.majorityElement(nums);
    cout << result;
    return 0;
}
