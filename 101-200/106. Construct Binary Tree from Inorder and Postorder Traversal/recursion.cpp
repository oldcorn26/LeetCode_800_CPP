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
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

        int crtVal{*(postorder.end() - 1)}, partition{0};
        TreeNode *ret{new TreeNode(crtVal)};

        for (; partition < inorder.size(); ++partition) if (inorder[partition] == crtVal) break;
        vector<int> leftInorder(inorder.begin(), inorder.begin() + partition),
                leftPostorder(postorder.begin(), postorder.begin() + partition),
                rightInorder(inorder.begin() + partition + 1, inorder.end()),
                rightPostorder(postorder.begin() + partition, postorder.end() - 1);
        if (leftInorder.size()) ret->left = buildTree(leftInorder, leftPostorder);
        if (rightInorder.size()) ret->right = buildTree(rightInorder, rightPostorder);

        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> inorder{9,3,15,20,7};
    vector<int> postorder{9,15,7,20,3};
    TreeNode *result = solution.buildTree(inorder, postorder);
    return 0;
}
