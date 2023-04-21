#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int size = arr.size();
        vector<int> dp(size);
        for (int i{}; i < size; ++i) {
            int maxNum{INT32_MIN};
            for (int j{}; j < k && i - j >= 0; ++j) {
                maxNum = max(maxNum, arr[i - j]);
                int pre{i - j - 1 >= 0 ? dp[i - j - 1] : 0};
                dp[i] = max(dp[i], pre + maxNum * (j + 1));

            }
        }
        return dp[size-1];
    }
};

int main() {
    Solution solution;
    vector<int> arr{1,15,7,9,2,5,10};
    int result = solution.maxSumAfterPartitioning(arr, 3);
    cout << result;
    return 0;
}
