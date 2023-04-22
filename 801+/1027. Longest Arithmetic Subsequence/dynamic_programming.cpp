#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int size = nums.size();
        int ret{1};
        vector<vector<int>> dp(size, vector<int>(1001, 1));
        unordered_map<int, int> record;
        for (int i{0}; i < size; ++i) {
            for (auto iter: record) {
                int interval{nums[i] - iter.first};
                dp[i][interval + 500] = dp[iter.second][interval + 500] + 1;
                ret = max(ret, dp[i][interval + 500]);
            }
            record[nums[i]] = i;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> arr{3,6,9,12};
    int result = solution.longestArithSeqLength(arr);
    cout << result;
    return 0;
}
