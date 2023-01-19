#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int> &nums, int target) {

        int sta{0}, end{static_cast<int>(nums.size()) - 1};

        while (sta < end) {
            int &&mid{(sta + end) / 2};
            if (nums[mid] < nums[end]) {
                if (binarySearch(nums, mid, end, target)) return true;
                end = mid - 1;
            } else if (nums[mid] > nums[end]) {
                if (binarySearch(nums, 0, mid, target)) return true;
                sta = mid + 1;
            } else {
                --end;
            }
        }

        return nums[sta] == target;
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
    vector<int> nums{2,5,6,0,0,1,2};
    bool result = solution.search(nums, 2);
    cout << result;
    return 0;
}
