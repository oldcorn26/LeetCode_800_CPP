#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }

    int quickSelect(vector<int> &nums, int &&left, int &&right, int &k) {
        int pivot = nums[left], i = left, j = right;

        while (i < j) {
            while (i < j && nums[j] < pivot) --j;
            if (i < j) nums[i++] = nums[j];
            while (i < j && nums[i] >= pivot) ++i;
            if (i < j) nums[j--] = nums[i];
        }
        if (i + 1 == k) return pivot;
        else if (i + 1 < k) return quickSelect(nums, i + 1, move(right), k);
        else return quickSelect(nums, move(left), i - 1, k);
    }
};

int main() {
    Solution solution;
    vector<int> nums{3};
    int result = solution.findKthLargest(nums, 1);
    cout << result;
    return 0;
}
