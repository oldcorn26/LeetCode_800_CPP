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

    TreeNode(int x, int y, int z) : val(x), left(new TreeNode(y)), right(new TreeNode(z)) {}
};

class Solution {
private:
    int maxLen{INT32_MIN};
public:
    int maxPathSum(TreeNode *root) {
        helper(root);
        return maxLen;
    }

    int helper(TreeNode *root) {
        if (!root)
            return 0;
        int left{helper(root->left) + root->val};
        int right{helper(root->right) + root->val};
        maxLen = max(maxLen, max(left, right));
        maxLen = max(maxLen, left + right - root->val);
        return left < 0 && right < 0 ? 0 : max(left, right);
    }
};

int main() {
    Solution solution;
    TreeNode *head = new TreeNode(1, new TreeNode(2), nullptr);
    int result = solution.maxPathSum(head);
    cout << result;
    return 0;
}
