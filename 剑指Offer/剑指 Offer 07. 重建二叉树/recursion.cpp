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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        else if (preorder.size() == 1) return new TreeNode(preorder[0]);
        int headIdx{};
        TreeNode *head{new TreeNode(preorder[0])};
        for (; headIdx < inorder.size() && inorder[headIdx] != preorder[0]; ++headIdx);
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + headIdx);
        vector<int> leftIn(inorder.begin(), inorder.begin() + headIdx);
        vector<int> rightPre(preorder.begin() + 1 + headIdx, preorder.end());
        vector<int> rightIn(inorder.begin() + headIdx + 1, inorder.end());
        head->left = buildTree(leftPre, leftIn);
        head->right = buildTree(rightPre, rightIn);
        return head;
    }
};

int main() {
    Solution solution;
    return 0;
}
