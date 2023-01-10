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
};

class Solution {
private:
    vector<vector<int>> ret;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        layerOrderTraversal(root, 0);
        zigzagResult();
        return ret;
    }

    void layerOrderTraversal(TreeNode *root, int idx) {
        if (!root) return;
        if (idx == ret.size()) ret.push_back({root->val});
        else ret[idx].emplace_back(root->val);
        layerOrderTraversal(root->left, idx + 1);
        layerOrderTraversal(root->right, idx + 1);
    }

    void zigzagResult() {
        for (int i{1}; i < ret.size(); i += 2) {
            int eleSize{static_cast<int>(ret[i].size())};
            int halfSize{eleSize / 2};
            for (int j{0}; j < halfSize; ++j) {
                swap(ret[i][j], ret[i][eleSize - 1 - j]);
            }
        }
    }
};

int main() {
    Solution solution;
    TreeNode *root = new TreeNode(-2, nullptr, new TreeNode(-3));
    vector<vector<int>> result = solution.zigzagLevelOrder(root);
    return 0;
}
