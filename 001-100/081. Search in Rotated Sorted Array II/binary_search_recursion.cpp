#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        if (nums.size() == 1) return nums[0] == target;
        int mid{(static_cast<int>(nums.size()) - 1) / 2};
        if (nums[mid] < nums[0]) {
            vector<int> nextVec(nums.begin(), nums.begin() + mid);
            return binarySearch(nums, mid, nums.size() - 1, target) || search(nextVec, target);
        } else if (nums[mid] > nums[nums.size() - 1]){
            vector<int> nextVec(nums.begin() + mid + 1, nums.end());
            return binarySearch(nums, 0, mid, target) || search(nextVec, target);
        } else {
            for (int &i: nums) {
                if (i == target) return true;
            }
            return false;
        }
    }

    bool binarySearch(vector<int> &nums, int sta, int end, int target) {
        while (sta < end) {
            int &&mid{(sta + end) / 2};
            if (nums[mid] == target) return true;
            else if (nums[mid] > target) end = mid - 1;
            else sta = mid + 1;
        }
        return nums[sta] == target;
    }
};

int main() {
    Solution solution;
    vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    bool result = solution.search(nums, 3);
    cout << result;
    return 0;
}
