#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx{}, sameCnt{1};
        for (int i{1}; i < nums.size(); ++i) {
            if (nums[idx] != nums[i]) {
                nums[++idx] = nums[i];
                sameCnt = 1;
            } else if (++sameCnt == 2) {
                nums[++idx] = nums[i];
            }
        }
        return idx + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums{0,0,1,1,1,1,2,3,3};
    int result = solution.removeDuplicates(nums);
    cout << result;
    return 0;
}