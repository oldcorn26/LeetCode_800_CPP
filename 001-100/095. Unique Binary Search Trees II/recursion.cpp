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
    vector<int> treeNum;
public:
    vector<TreeNode*> generateTrees(int n) {
        treeNum.resize(n + 1, 1);
        for (int i{2}; i <= n; ++i) {
            treeNum[i] = treeNum[i - 1] * 2 * (2 * i - 1) / (i + 1);
        }
        return generateHelper(1, n);
    }

    vector<TreeNode*> generateHelper(int sta, int end) {
        if (sta > end) return {nullptr};
        else if (sta == end) return {new TreeNode(sta)};

        int idx{-1};
        vector<TreeNode*> res(treeNum[end - sta + 1]);
        for (int i{sta}; i <= end; ++i) {
            vector<TreeNode*> &&left = generateHelper(sta, i - 1);
            vector<TreeNode*> &&right = generateHelper(i + 1, end);
            for (TreeNode* &leftIter: left) {
                for (TreeNode* &rightIter: right) {
                    res[++idx] = new TreeNode(i, leftIter, rightIter);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<TreeNode*> result = solution.generateTrees(5);
    return 0;
}