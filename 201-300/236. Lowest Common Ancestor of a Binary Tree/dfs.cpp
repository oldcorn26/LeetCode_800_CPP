#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<int, TreeNode*> fatherMap;
    unordered_set<TreeNode*> vis;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal{p->val};
        dfs(root);
        vis.emplace(p);
        while (fatherMap.find(pVal) != fatherMap.end()) {
            vis.emplace(fatherMap[pVal]);
            pVal = fatherMap[pVal]->val;
        }
        while (vis.find(q) == vis.end())
            q = fatherMap[q->val];
        return q;
    }

    void dfs(TreeNode *root) {
        if (!root)
            return;
        if (root->left){
            fatherMap[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right) {
            fatherMap[root->right->val] = root;
            dfs(root->right);
        }
    }
};

int main() {
    Solution solution;
    return 0;
}
