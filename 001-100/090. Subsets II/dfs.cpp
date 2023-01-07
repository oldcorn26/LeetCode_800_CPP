#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> ret;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> settled(nums.size());

        ret.emplace_back();
        sort(nums.begin(), nums.end());
        dfs(nums, settled, 0, 0);

        return ret;
    }

    void dfs(vector<int> &nums, vector<int> &stl, int numsIdx, int candiIdx) {
        if (candiIdx == stl.size()) return;

        int pre{INT32_MIN};
        for (int i{numsIdx}; i < nums.size(); ++i) {
            if (nums[i] == pre) continue;
            stl[candiIdx] = nums[i];
            ret.emplace_back(stl.begin(), stl.begin() + candiIdx + 1);
            dfs(nums, stl, i + 1, candiIdx + 1);
            pre = nums[i];
        }
    }
};
int main() {
    Solution solution;
    vector<int> nums{1,2,2};
    vector<vector<int>> result = solution.subsetsWithDup(nums);
    return 0;
}