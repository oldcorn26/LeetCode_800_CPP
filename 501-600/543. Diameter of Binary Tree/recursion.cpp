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
    int res = 0;
public:
    int diameterOfBinaryTree(TreeNode *root) {
        depth(root);
        return res;
    }

    int depth(TreeNode *root) {
        if (!root) return 0;

        int &&leftNum = depth(root->left);
        int &&rightNum = depth(root->right);
        res = max(leftNum + rightNum, res);
        return max(leftNum, rightNum) + 1;
    }
};

int main() {
    Solution solution;
    return 0;
}