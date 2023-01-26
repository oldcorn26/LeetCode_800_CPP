#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int> &nums) {
        return mergeSortHelper(nums, 0, nums.size() - 1);
    }

    int mergeSortHelper(vector<int> &nums, int sta, int end) {

        if (sta == end) return 0;
        int &&mid{(sta + end) / 2};
        int j{mid + 1};
        int ret{mergeSortHelper(nums, sta, mid) +
                mergeSortHelper(nums, mid + 1, end)};

        for (int i{sta}; i <= mid; ++i) {
            while (j <= end && nums[i] > (long) 2 * nums[j]) ++j;
            ret += j - mid - 1;
        }

        // Merge Sort
        int left{0}, right{mid + 1};
        vector<int> backup(nums.begin() + sta, nums.begin() + mid + 1);
        for (int i{sta}; i <= end; ++i) {
            if (right > end || (left < backup.size() && backup[left] < nums[right])) nums[i] = backup[left++];
            else nums[i] = nums[right++];
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{2,4,3,5,1};
    int result = solution.reversePairs(nums);
    cout << result;
    return 0;
}
