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

    TreeNode(int x, int y, int z) : val(x), left(new TreeNode(y)), right(new TreeNode(z)) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        else {
            int &&left = maxDepth(root->left);
            int &&right = maxDepth(root->right);
            return max(left,right) + 1;
        }
    }
};

int main() {
    Solution solution;
    TreeNode *head = new TreeNode(3, new TreeNode(9), new TreeNode(20, 15, 7));
    int result = solution.maxDepth(head);
    cout << result;
    return 0;
}
