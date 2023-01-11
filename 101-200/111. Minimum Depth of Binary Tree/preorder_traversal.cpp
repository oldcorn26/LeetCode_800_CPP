#include <iostream>

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
    int ret{INT32_MAX};
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        preorderTraversal(root, 1);
        return ret;
    }

    void preorderTraversal(TreeNode *root, int idx) {
        if (!root->left && !root->right) {
            ret = idx < ret ? idx : ret;
            return;
        }
        if (root->left) preorderTraversal(root->left, idx + 1);
        if (root->right) preorderTraversal(root->right, idx + 1);
    }
};

int main() {
    Solution solution;
    TreeNode *root = new TreeNode(-2, nullptr, new TreeNode(-3));
    int result = solution.minDepth(root);
    cout << result;
    return 0;
}
