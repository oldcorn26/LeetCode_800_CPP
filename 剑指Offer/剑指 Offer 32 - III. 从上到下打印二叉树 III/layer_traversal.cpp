#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> children{{root}};
        vector<vector<int>> ret;
        while (!children.empty()) {
            int crtSize = children.size();
            vector<int> crt(crtSize);
            for (int i{}; i < crtSize; ++i) {
                crt[i] = children.front()->val;
                if (children.front()->left)
                    children.emplace(children.front()->left);
                if (children.front()->right)
                    children.emplace(children.front()->right);
                children.pop();
            }
            if (ret.size() % 2)
                reverse(crt.begin(), crt.end());
            ret.push_back(crt);
        }
        return ret;
    }
};

int main() {
    Solution solution;
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    vector<vector<int>> result = solution.levelOrder(root);
    return 0;
}
