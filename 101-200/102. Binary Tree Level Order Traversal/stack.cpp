#include <iostream>
#include <vector>
#include <queue>

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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> s{{root}};
        vector<vector<int>> ret;
        while (!s.empty()) {
            int size = s.size();
            vector<int> element;
            while (size-- > 0) {
                element.push_back(s.front()->val);
                if (s.front()->left)
                    s.push(s.front()->left);
                if (s.front()->right)
                    s.push(s.front()->right);
                s.pop();
            }
            ret.push_back(std::move(element));
        }
        return ret;
    }
};

int main() {
    Solution solution;
    TreeNode *head = new TreeNode(3, new TreeNode(9), new TreeNode(20, 15, 7));
    vector<vector<int>> result = solution.levelOrder(head);
    return 0;
}
