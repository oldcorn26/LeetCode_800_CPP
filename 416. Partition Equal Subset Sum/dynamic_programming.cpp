#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum{0};
        for (int &i: nums) sum += i;
        if (sum % 2) return false;
        int &&halfSum{sum / 2};
        vector<char> dp(halfSum + 1, 0);
        dp[0] = 1;
        for (int &i: nums) {
            vector<char> tempDP{dp};
            for (int j = 0; j <= halfSum; ++j) {
                if (!tempDP[j]) continue;
                int &&tempSum{j + i};
                if (tempSum == halfSum) return true;
                else if (tempSum < halfSum) dp[tempSum] = 1;
                else break;
            }
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