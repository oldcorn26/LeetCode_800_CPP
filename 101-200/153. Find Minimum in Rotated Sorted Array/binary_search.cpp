#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {

        int sta{0}, end{static_cast<int>(nums.size()) - 1};

        while (sta < end) {
            int mid{(sta + end) / 2};
            if (nums[mid] > *(nums.end() - 1)) sta = mid + 1;
            else end = mid;
        }

        return nums[sta];
    }
};

int main() {
    Solution solution;
    vector<int> nums{3,4,5,1,2};
    int result = solution.findMin(nums);
    cout << result;
    return 0;
}
