#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int sta{0}, end{static_cast<int>(nums.size()) - 1};

        while (sta < end) {
            int &&mid{(sta + end) / 2};
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) end = mid - 1;
            else sta = mid + 1;
        }
        
        return nums[sta] >= target ? sta : sta + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1};
    cout << solution.searchInsert(nums, 1);
    return 0;
}
