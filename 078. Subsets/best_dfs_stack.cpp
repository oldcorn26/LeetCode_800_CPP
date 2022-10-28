#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        stack<int> tree;
        vector<vector<int>> res;
        res.push_back({});

        dfs(tree, 0, nums, res);
        return res;
    }

    void dfs(stack<int> &tree, int &&idx, const vector<int> &candi, vector<vector<int>> &res) {
        if (idx == candi.size()) return;
        for (int i = idx; i < candi.size(); ++i) {
            tree.push(candi[i]);

            vector<int> element(tree.size());
            stack<int> temp(tree);
            for (int &iter : element) {iter = temp.top(); temp.pop();}
            res.push_back(element);

            dfs(tree, i + 1, candi, res);
            tree.pop();
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 2, 3, 4};
    vector<vector<int>> result = solution.subsets(nums);
    return 0;
}