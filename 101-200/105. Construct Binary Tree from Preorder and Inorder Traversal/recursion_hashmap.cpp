#include <iostream>
#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> hashMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < preorder.size(); ++i) hashMap.insert({inorder[i], i});
        return buildTreeHelper(preorder, inorder, 0, 0, preorder.size());
    }

    TreeNode* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int &&flag1, int &&flag2, int &&len) {
        if (!len) return nullptr;
        else if (len == 1) return new TreeNode(preorder[flag1]);

        int &idx2 = hashMap[preorder[flag1]];
        return new TreeNode(preorder[flag1],
                            buildTreeHelper(preorder, inorder, flag1 + 1, move(flag2), idx2 - flag2),
                            buildTreeHelper(preorder, inorder, flag1 + 1 + idx2 - flag2, idx2 + 1,
                                            len - 1 - idx2 + flag2));
    }
};

int main() {
    Solution solution;
    vector<int> preorder{1, 2};
    vector<int> inorder{1, 2};
    TreeNode *head = solution.buildTree(preorder, inorder);
    return 0;
}
