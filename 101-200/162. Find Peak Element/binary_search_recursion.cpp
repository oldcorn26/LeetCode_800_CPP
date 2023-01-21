#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        if (nums.size() == 1) return 0;
        else return findPeakElementHelper(nums, 0, nums.size() - 1);
    }

    int findPeakElementHelper(vector<int> &nums, int sta, int end) {
        if (sta + 1 == end) {
            if (sta == 0 && nums[0] > nums[1]) return 0;
            else if (end == nums.size() - 1 && *(nums.end()-1) > *(nums.end()-2)) return nums.size() - 1;
            else return -1;
        }

        int &&mid{(sta + end) / 2};
        if (mid && nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) return mid;
        int left = findPeakElementHelper(nums, sta, mid);
        if (left != -1) return left;
        else return findPeakElementHelper(nums, mid, end);
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2,1,3,5,6,4};
    int result = solution.findPeakElement(nums);
    cout << result;
    return 0;
}
