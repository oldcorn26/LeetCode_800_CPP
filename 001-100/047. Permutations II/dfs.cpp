#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> candidates(21), element(nums.size());
        for (int &i: nums) {
            ++candidates[i + 10];
        }
        dfs(element, 0, candidates);
        return res;
    }

    void dfs(vector<int> &element, int idx, vector<int> &candi) {
        if (idx == element.size()) {
            res.push_back(element);
        }
        for (int i{0}; i < 21; ++i) {
            if (!candi[i]) continue;
            --candi[i];
            element[idx] = i - 10;
            dfs(element, idx + 1, candi);
            ++candi[i];
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,1,2};
    vector<vector<int>> result = solution.permuteUnique(nums);
    return 0;
}