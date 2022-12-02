#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        for (int &num: nums) {
            int &&x = (num - 1) % size;
            nums[x] += size;
        }
        vector<int> res;
        for (int i = 0; i < size; i++) {
            if (nums[i] <= size) res.emplace_back(i + 1);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{4,3,2,7,8,2,3,1};
    vector<int> result = solution.findDisappearedNumbers(nums);
    return 0;
}