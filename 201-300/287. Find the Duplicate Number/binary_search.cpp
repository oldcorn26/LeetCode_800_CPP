#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {

        int size = nums.size();
        int sta{1}, end{size - 1};
        int ret{0};

        while (sta <= end) {
            int cnt{0};
            int mid{(sta + end) >> 1};
            for (int i{0}; i < size; ++i) cnt += (nums[i] <= mid);
            if (cnt <= mid) sta = mid + 1;
            else end = ret = mid - 1;
        }

        return ret + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2,2};
    int result = solution.findDuplicate(nums);
    cout << result;
    return 0;
}
