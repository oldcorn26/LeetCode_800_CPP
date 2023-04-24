#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int n = arr1.size();
        int m = arr2.size();
        vector<vector<int>> dp(n + 1, vector<int>(min(m, n) + 1, INT32_MAX));
        dp[0][0] = -1;
        for (int i{1}; i <= n; ++i) {
            for (int j{0}; j <= min(i, m); ++j) {
                if (arr1[i - 1] > dp[i - 1][j])
                    dp[i][j] = arr1[i - 1];
                if (j > 0 && dp[i - 1][j - 1] != INT32_MAX) {
                    auto it = upper_bound(arr2.begin() + j - 1, arr2.end(), dp[i - 1][j - 1]);
                    if (it != arr2.end())
                        dp[i][j] = min(dp[i][j], *it);
                }
                if (i == n && dp[i][j] != INT32_MAX)
                    return j;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 15, 7, 9, 2, 5, 10};
    return 0;
}
