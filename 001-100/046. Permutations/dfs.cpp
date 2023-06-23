#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int finalState;
    vector<vector<int>> ret;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> crt(nums.size());
        finalState = (1 << nums.size()) - 1;
        dfs(nums, crt, 0, 0);
        return ret;
    }

    void dfs(vector<int> &nums, vector<int> &crt, int crtIdx, int state) {
        if (state == finalState) {
            ret.push_back(crt);
            return;
        }
        for (int i{}; i < nums.size(); ++i) {
            if ((1 << i) & state)
                continue;
            crt[crtIdx] = nums[i];
            dfs(nums, crt, crtIdx + 1, state | (1 << i));
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 2, 3};
    vector<vector<int>> result = solution.permute(nums);
    return 0;
}
