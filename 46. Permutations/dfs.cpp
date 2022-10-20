#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> per(nums.size(), 11);
        dfs(per, 0, nums, res);
        return res;
    }

    void dfs(vector<int> &per, int &&idx, vector<int> &nums, vector<vector<int>> &res) {
        if (idx == nums.size()) {
            res.push_back(per);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 11) {
                per[idx] = nums[i]; nums[i] = 11;
                dfs(per, idx + 1, nums, res);
                nums[i] = per[idx]; per[idx] = 11;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 2, 3};
    vector<vector<int>> result = solution.permute(nums);
    return 0;
}
