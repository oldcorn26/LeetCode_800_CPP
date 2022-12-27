#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int size{static_cast<int>(nums.size())};
        int slowIdx{0}, fastIdx{1};
        for (; fastIdx < size; ++fastIdx) {
            if (nums[slowIdx] != nums[fastIdx]) {
                nums[++slowIdx] = nums[fastIdx];
            }
        }
        return slowIdx + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    int result = solution.removeDuplicates(nums);
    cout << result;
    return 0;
}