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
    int res = 0;
public:
    int pathSum(TreeNode *root, int targetSum) {
        vector<long> candidates(1, targetSum);
        pathSumHelper(root, candidates, targetSum);
        return res;
    }

    void pathSumHelper(TreeNode *root, vector<long> &candi, int &tar) {
        if (!root) return;

        int size = candi.size();
        vector<long> nextCandi(size + 1);
        for (int i = 0; i < size; ++i) {
            if (candi[i] == root->val) ++res;
            nextCandi[i] = candi[i] - root->val;
        }
        nextCandi[size] = tar;
        pathSumHelper(root->left, nextCandi, tar);
        pathSumHelper(root->right, nextCandi, tar);
    }
};

int main() {
    Solution solution;
    TreeNode *root = new TreeNode(0, new TreeNode(1), new TreeNode(1));
    int result = solution.pathSum(root, 1);
    cout << result;
    return 0;
}