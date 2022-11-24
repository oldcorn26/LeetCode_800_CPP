#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    TreeNode(int x, int y, int z) : val(x), left(new TreeNode(y)), right(new TreeNode(z)) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> &&dp = robHelper(root);
        return max(dp.first, dp.second);
    }

    pair<int, int> robHelper(TreeNode *root) {
        if (!root) return {0, 0};
        pair<int, int> &&lDP = robHelper(root->left), &&rDP = robHelper(root->right);
        return {max(lDP.first, lDP.second) + max(rDP.first, rDP.second), root->val + lDP.first + rDP.first};
    }
};

int main() {
    Solution solution;
    return 0;
}