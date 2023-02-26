#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int maxSize{0}, maxIdx{0}, maxNum{0};
        vector<int> dp(nums.size());
        for (int i{0}; i < nums.size(); ++i) {
            for (int j{0}; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIdx = i;
                maxNum = nums[i];
            }
        }
        vector<int> ret;
        for (; maxIdx >= 0; --maxIdx) {
            if (dp[maxIdx] == maxSize && maxNum % nums[maxIdx] == 0) {
                ret.emplace_back(nums[maxIdx]);
                maxNum = nums[maxIdx];
                maxSize--;
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2,3};
    vector<int> result = solution.largestDivisibleSubset(nums);
    return 0;
}
