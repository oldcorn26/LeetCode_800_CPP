#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return size;
        sort(nums.begin(), nums.end());

        int maxLen = 1, idx = 0, repeatedNum = 0;
        for (int i = 1; i < size; ++i) {
            if (nums[i] == nums[i - 1] + 1) maxLen = i - idx - repeatedNum + 1 > maxLen ? i - idx - repeatedNum + 1 : maxLen;
            else nums[i] == nums[i - 1] ? ++repeatedNum : (idx = i, repeatedNum = 0);
        }

        return maxLen;
    }
};

int main() {
    Solution solution;
    vector<int> nums{100,4,200,1,3,2};
    int result = solution.longestConsecutive(nums);
    cout << result;
    return 0;
}
