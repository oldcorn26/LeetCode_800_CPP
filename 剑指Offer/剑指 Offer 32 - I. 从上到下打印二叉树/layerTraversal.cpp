#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<vector<int>> layer;
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ret;
        layerTraversal(root, 0);
        for (vector<int> &vec: layer)
            ret.insert(ret.end(), vec.begin(), vec.end());
        return ret;
    }

    void layerTraversal(TreeNode *root, int idx) {
        if (!root) return;
        if (idx == layer.size()) layer.emplace_back();
        layer[idx].emplace_back(root->val);
        layerTraversal(root->left, idx+1);
        layerTraversal(root->right, idx+1);
    }
};

int main() {
    Solution solution;
    return 0;
}
