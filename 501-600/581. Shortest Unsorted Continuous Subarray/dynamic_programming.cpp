#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int maxFlag{nums[0]}, idx1{-1};
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < maxFlag) idx1 = i;
            else maxFlag = nums[i];
        }
        if (idx1 < 0) return 0;
        int minFlag{nums[idx1]}, idx2{idx1};
        for (int &&i = idx1 - 1; i >= 0; --i) {
            if (nums[i] > minFlag) idx2 = i;
            else minFlag = nums[i];
        }
        return idx1 - idx2 + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,3,5,4,2};
    int result = solution.findUnsortedSubarray(nums);
    cout << result;
    return 0;
}