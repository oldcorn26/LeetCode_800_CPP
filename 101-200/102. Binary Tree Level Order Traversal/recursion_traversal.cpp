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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        preorderTraversal(root, res, 0);
        return res;
    }

    void preorderTraversal(TreeNode *root, vector<vector<int>> &res, int &&layer) {
        if (!root) return;
        else {
            while (layer >= res.size()) res.push_back({});
            res[layer].push_back(root->val);
            preorderTraversal(root->left, res, layer + 1);
            preorderTraversal(root->right, res, layer + 1);
        }
    }
};

int main() {
    Solution solution;
    TreeNode *head = new TreeNode(3, new TreeNode(9), new TreeNode(20, 15, 7));
    vector<vector<int>> result = solution.levelOrder(head);
    return 0;
}
