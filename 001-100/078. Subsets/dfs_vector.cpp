#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tree;
        vector<vector<int>> res;
        res.push_back({});

        dfs(tree, 0, nums, res);
        return res;
    }

    void dfs(vector<int> &tree, int &&idx, const vector<int> &candi, vector<vector<int>> &res) {
        if (idx == candi.size()) return;
        for (int i = idx; i < candi.size(); ++i) {
            tree.push_back(candi[i]);
            res.push_back(tree);
            dfs(tree, i + 1, candi, res);
            tree.resize(tree.size() - 1);
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 2, 3, 4};
    vector<vector<int>> result = solution.subsets(nums);
    return 0;
}