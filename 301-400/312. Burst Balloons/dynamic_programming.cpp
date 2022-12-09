#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int &&dpSize = nums.size() + 2;
        int dp[dpSize][dpSize];
        for (int interval{1}; interval < dpSize; ++interval) {
            for (int i{0}; i + interval < dpSize; ++i) {
                int &&j{i + interval}, sidePro;
                if (i == 0) sidePro = j + 1 < dpSize ? nums[j - 1] : 1;
                else if (j == dpSize - 1) sidePro = nums[i - 1];
                else sidePro = nums[i - 1] * nums[j - 1];
                dp[i][j] = 0;
                for (int &&k{i + 1}; k < j; ++k) {
                    int &&crtNum{nums[k - 1] * sidePro};
                    dp[i][j] = max(dp[i][j], crtNum + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][dpSize - 1];
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,5};
    int result = solution.maxCoins(nums);
    cout << result;
    return 0;
}