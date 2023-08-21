#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int halfSum{};
        for (int i: nums)
            halfSum += i;
        if (halfSum % 2)
            return false;
        else
            halfSum /= 2;
        vector<bool> dp(halfSum+1);
        dp[0] = true;
        for (int num: nums) {
            if (num > halfSum)
                return false;
            vector<bool> backup{dp};
            for (int j{}; j <= halfSum; ++j) {
                if (!backup[j] || num+j > halfSum)
                    continue;
                dp[num+j] = true;
            }
            if (dp[halfSum])
                return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums{3,3,3,4,5};
    bool result = solution.canPartition(nums);
    cout << result;
    return 0;
}
