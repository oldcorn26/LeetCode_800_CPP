#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, 0, nums.size()-1, k);
    }

    int helper(vector<int> &nums, int sta, int end, int k) {
        int left{sta}, right{end};
        int pivot{nums[sta]};
        while (left < right) {
            while (left < right && nums[right] < pivot)
                right--;
            if (left < right)
                nums[left++] = nums[right];
            while (left < right && nums[left] >= pivot)
                left++;
            if (left < right)
                nums[right--] = nums[left];
        }
        if (left+1 == k)
            return pivot;
        else if (left+1 < k)
            return helper(nums, left+1, end, k);
        else
            return helper(nums, sta, left-1, k);
    }
};

int main() {
    Solution solution;
    vector<int> nums{3};
    int result = solution.findKthLargest(nums, 1);
    cout << result;
    return 0;
}
