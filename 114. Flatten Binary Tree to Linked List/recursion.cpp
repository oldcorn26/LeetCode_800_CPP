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
private:
    TreeNode *orderedHead = nullptr;
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->right);
        flatten(root->left);
        if (!orderedHead) orderedHead = root;
        else {
            root->right = orderedHead;
            root->left = nullptr;
            orderedHead = root;
        }
    }
};

int main() {
    Solution solution;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2, 3, 4);
    head->right = new TreeNode(5, nullptr, new TreeNode(6));
    solution.flatten(head);
    return 0;
}
