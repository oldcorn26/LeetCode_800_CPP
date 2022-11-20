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
    TreeNode *pre = nullptr;
public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;

        if (!isValidBST(root->left)) return false;
        if (pre && root->val <= pre->val) return false;
        else pre = root;
        return isValidBST(root->right);
    }
};

int main() {
    Solution solution;
//    TreeNode *head = new TreeNode(5, new TreeNode(4), new TreeNode(6, new TreeNode(3), new TreeNode(7)));
    TreeNode *head = new TreeNode(INT32_MIN);
    bool result = solution.isValidBST(head);
    cout << result;
    return 0;
}
