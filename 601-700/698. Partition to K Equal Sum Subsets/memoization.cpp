#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    int finalState;
    int per{0};
    unordered_set<int> memo;
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {

        int sum{0};

        sort(nums.begin(), nums.end(), greater<>());
        for (int &i: nums) sum += i;
        per = sum / k;
        if (nums[0] > per || sum % k) return false;
        finalState = (1 << (nums.size() + 1)) - 1;

        return k == 1 || dfs(nums, 1 << nums.size(), 0);
    }

    bool dfs(vector<int> &nums, int state, int crtSum) {

        if (state == finalState) return true;
        if (memo.find(state) != memo.end()) return false;
        memo.emplace(state);

        for (int i{0}; i < nums.size(); ++i) {
            if (nums[i] + crtSum > per || (state >> i) & 1) continue;
            if (dfs(nums, state | (1 << i), (nums[i] + crtSum) % per)) return true;
        }

        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums{4, 3, 2, 3, 5, 2, 1};
    bool result = solution.canPartitionKSubsets(nums, 4);
    cout << result;
    return 0;
}
