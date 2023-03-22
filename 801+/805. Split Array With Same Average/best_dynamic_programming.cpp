#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int> &nums) {
        int size = nums.size();
        int dpSize{size/2+1};
        bool isPossible{false};
        int sum{accumulate(nums.begin(), nums.end(), 0)};
        for (int i{1}; i < dpSize && !isPossible; ++i)
            if (sum*i%size == 0)
                isPossible = true;
        if (!isPossible)
            return false;
        vector<unordered_set<int>> dp(dpSize);
        dp[0].emplace(0);
        for (int &num: nums) {
            for (int j{dpSize-1}; j > 0; --j) {
                for (auto &k: dp[j-1]) {
                    int crt{k+num};
                    if (crt*size == sum*j)
                        return true;
                    dp[j].emplace(crt);
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums{3,10,5,25,2,8};
    bool result = solution.splitArraySameAverage(nums);
    cout << result;
    return 0;
}
