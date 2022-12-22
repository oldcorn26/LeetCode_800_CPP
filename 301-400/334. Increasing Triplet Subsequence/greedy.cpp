#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int tails[2]{nums[0], 0}, len{1}, size{static_cast<int>(nums.size())};
        for (int i{1}; i < size; ++i) {
            int idx{len};
            while (idx > 0 && tails[idx - 1] >= nums[i]) {
                --idx;
            }
            if (idx == 2) return true;
            else if (idx == len) ++len;
            tails[idx] = nums[i];
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,1,1,1};
    bool result = solution.increasingTriplet(nums);
    cout << result;
    return 0;
}