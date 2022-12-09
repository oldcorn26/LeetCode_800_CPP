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
private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        convertBSTHelper(root);
        return root;
    }

    void convertBSTHelper(TreeNode *root) {
        if (!root) return;
        convertBSTHelper(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
    }
};

int main() {
    Solution solution;
    return 0;
}