#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int size{static_cast<int>(nums.size())};
        int slowIdx{0}, fastIdx{1}, countFlag{1};
        for (; fastIdx < size; ++fastIdx) {
            if (nums[fastIdx] != nums[slowIdx]) {
                nums[++slowIdx] = nums[fastIdx];
                countFlag = 1;
            } else if (--countFlag >= 0) {
                nums[++slowIdx] = nums[fastIdx];
            }
        }
        return slowIdx + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums{0,0,1,1,1,1,2,3,3};
    int result = solution.removeDuplicates(nums);
    cout << result;
    return 0;
}