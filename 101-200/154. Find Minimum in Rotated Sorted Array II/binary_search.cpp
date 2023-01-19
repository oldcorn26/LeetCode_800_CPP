#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {

        int sta{0}, end{static_cast<int>(nums.size()) - 1};

        while (sta < end) {
            int mid{(sta + end) / 2};
            if (nums[mid] < nums[end]) end = mid;
            else if (nums[mid] > nums[end]) sta = mid + 1;
            else --end;
        }

        return nums[sta];
    }
};

int main() {
    Solution solution;
    vector<int> nums{3,1,3};
    int result = solution.findMin(nums);
    cout << result;
    return 0;
}
