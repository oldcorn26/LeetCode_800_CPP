#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIdx{-1}, fastIdx{0};
        for (; fastIdx < nums.size(); ++fastIdx) {
            if (nums[fastIdx] != val) {
                nums[++slowIdx] = nums[fastIdx];
            }
        }
        return slowIdx + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums{0,1,2,2,3,0,4,2};
    int result = solution.removeElement(nums, 2);
    cout << result;
    return 0;
}