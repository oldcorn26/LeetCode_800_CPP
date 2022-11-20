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
    int max = INT32_MIN;
public:
    int maxPathSum(TreeNode* root) {
        rootAsTerminal(root);
        return max;
    }

    int rootAsTerminal(TreeNode *root) {
        if (!root) return 0;

        int &&left = rootAsTerminal(root->left);
        int &&right = rootAsTerminal(root->right);
        const int &bigger = left < right ? right : left;
        if (left <= 0 && right <= 0) {
            max = root->val > max ? root->val : max;
            return root->val > 0 ? root->val : 0;
        } else if (left <= 0 || right <= 0) {
            int &&temp = root->val + bigger;
            if (temp > bigger) {max = temp > max ? temp : max; return temp;}
            else if (temp > 0) return temp;
            else return 0;
        } else {
            max = left + right + root->val > max ? left + right + root->val : max;
            return bigger + root->val > 0 ? bigger + root->val : 0;
        }
    }
};

int main() {
    Solution solution;
    TreeNode *head = new TreeNode(1, new TreeNode(2), nullptr);
//    head->right = new TreeNode(20, 15, 7);
    int result = solution.maxPathSum(head);
    cout << result;
    return 0;
}
