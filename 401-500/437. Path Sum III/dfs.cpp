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
    int ret{};
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> prefix(1001);
        dfs(root, prefix, 1, targetSum);
        return ret;
    }

    void dfs(TreeNode *root, vector<long long> &prefix, int idx, int target) {
        if (!root) {
            return;
        }
        prefix[idx] = prefix[idx-1] + root->val;
        for (int i{}; i < idx; ++i) {
            if (prefix[idx] - prefix[i] == target) {
                ret++;
            }
        }
        dfs(root->left, prefix, idx+1, target);
        dfs(root->right, prefix, idx+1, target);
    }
};

int main() {
    Solution solution;
    TreeNode *root = new TreeNode(0, new TreeNode(1), new TreeNode(1));
    int result = solution.pathSum(root, 1);
    cout << result;
    return 0;
}