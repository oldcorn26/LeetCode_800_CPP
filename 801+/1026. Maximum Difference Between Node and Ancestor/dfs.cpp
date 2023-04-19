#include <iostream>
#include <algorithm>

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
    int ret{};
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, INT32_MIN, INT32_MAX);
        return ret;
    }

    void dfs(TreeNode *root, int maxVal, int minVal) {
        if (!root)
            return;
        int rootVal{root->val};
        maxVal = max(maxVal, rootVal);
        minVal = min(minVal, rootVal);
        ret = max(ret, max(maxVal-rootVal,rootVal-minVal));
        dfs(root->left, maxVal, minVal);
        dfs(root->right, maxVal, minVal);
    }
};

int main() {
    Solution solution;
    return 0;
}
