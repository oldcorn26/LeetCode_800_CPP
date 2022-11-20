#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<char> left, right;
    char recursionFlag = 0;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<char> deque1;
        traversal(deque1, root, p, q);

        int flag = 0, leftNum = left.size(), rightNum = right.size();
        TreeNode *res = root;
        while (flag < leftNum && flag < rightNum && left[flag] == right[flag]) {
            if (left[flag] == '0') res = res->left;
            else res = res->right;
            ++flag;
        }

        return res;
    }

    void traversal(deque<char> &deq, TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return;

        if (root == p) {left = {deq.begin(), deq.end()}; ++recursionFlag;}
        if (root == q) {right = {deq.begin(), deq.end()}; ++recursionFlag;}

        deq.push_back('0');
        if (recursionFlag != 2) traversal(deq, root->left, p, q);
        deq.pop_back(), deq.push_back('1');
        if (recursionFlag != 2) traversal(deq, root->right, p, q);
        deq.pop_back();
    }
};

int main() {
    Solution solution;
    return 0;
}
