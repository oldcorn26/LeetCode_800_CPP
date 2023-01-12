#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<vector<int>> ret;
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> settled;
        if (root) dfs(root, settled, 0, targetSum);
        return ret;
    }

    void dfs(TreeNode *root, vector<int> &stl, int stlIdx, int tar) {
        if (stlIdx < stl.size()) stl[stlIdx] = root->val;
        else stl.push_back(root->val);

        if (!root->left && !root->right) {
            if (tar == root->val) ret.emplace_back(stl.begin(), stl.begin() + stlIdx + 1);
            return;
        }
        if (root->left) dfs(root->left, stl, stlIdx + 1, tar - root->val);
        if (root->right) dfs(root->right, stl, stlIdx + 1, tar - root->val);
    }
};

int main() {
    Solution solution;
    TreeNode *root = new TreeNode(-2, nullptr, new TreeNode(-3));
    vector<vector<int>> result = solution.pathSum(root, -5);
    return 0;
}