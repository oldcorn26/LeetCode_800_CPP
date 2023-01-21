#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {

        auto get = [&](int i) -> int {
            if (i == -1 || i == nums.size()) return INT32_MIN;
            else return nums[i];
        };

        int sta{0}, end{static_cast<int>(nums.size()) - 1};

        while (sta < end) {
            int &&mid{(sta + end) / 2};
            int l{get(mid - 1)}, m{get(mid)}, r{get(mid + 1)};
            if (m > l && m > r) return mid;
            else if (m > r) end = mid - 1;
            else sta = mid + 1;
        }

        return sta;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2};
    int result = solution.findPeakElement(nums);
    cout << result;
    return 0;
}
