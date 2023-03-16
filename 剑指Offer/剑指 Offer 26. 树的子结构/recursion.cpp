#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        if (A->val == B->val && dfs(A, B)) return true;
        else return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool dfs(TreeNode *A, TreeNode *B) {
        if (!B) return true;
        if (!A) return false;
        if (A->val != B->val) return false;
        return dfs(A->left, B->left) && dfs(A->right, B->right);
    }
};

int main() {
    Solution solution;
    return 0;
}
