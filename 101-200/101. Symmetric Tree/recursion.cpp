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
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root, root);
    }

    bool isSymmetricHelper(TreeNode *rootL, TreeNode *rootR) {
        if (!rootL ^ !rootR) return false;
        else if (!rootL && !rootR) return true;

        return rootL->val == rootR->val && isSymmetricHelper(rootL->left, rootR->right) && isSymmetricHelper(rootL->right, rootR->left);
    }
};

int main() {
    Solution solution;
    TreeNode *head = new TreeNode(1, new TreeNode(2, 3, 4), new TreeNode(2, 4, 3));
    bool result = solution.isSymmetric(head);
    cout << result;
    return 0;
}
