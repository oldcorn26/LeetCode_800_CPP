#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        vector<int> ret;
        for (int num: nums) {
            nums[(num-1) % size] += size;
        }
        for (int i{}; i < size; ++i) {
            if (nums[i] <= size) {
                ret.emplace_back(i + 1);
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{4,3,2,7,8,2,3,1};
    vector<int> result = solution.findDisappearedNumbers(nums);
    return 0;
}