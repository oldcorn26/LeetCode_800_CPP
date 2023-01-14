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
    vector<int> ret;
public:
    vector<int> rightSideView(TreeNode *root) {
        if (root) layerOrderTraversal(root, 0);
        return ret;
    }

    void layerOrderTraversal(TreeNode *root, int idx) {
        if (idx == ret.size()) ret.emplace_back(root->val);
        else ret[idx] = root->val;
        if (root->left) layerOrderTraversal(root->left, idx + 1);
        if (root->right) layerOrderTraversal(root->right, idx + 1);
    }
};

int main() {
    Solution solution;
    return 0;
}
