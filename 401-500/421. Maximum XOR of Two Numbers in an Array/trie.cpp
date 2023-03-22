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
public:
    int findMaximumXOR(vector<int>& nums) {
        int ret{};
        TreeNode *root = new TreeNode();
        for (int &i: nums) {
            creatNode(root, i);
            ret = max(ret, findOpposite(root, i));
        }
        return ret;
    }

    void creatNode(TreeNode *root, int num) {
        TreeNode *crt{root};
        for (int i{30}; i >= 0; --i) {
            int crtBit{(num >> i) & 1};
            if (crtBit) {
                if (!crt->left)
                    crt->left = new TreeNode();
                crt = crt->left;
            } else {
                if (!crt->right)
                    crt->right = new TreeNode();
                crt = crt->right;
            }
        }
    }

    int findOpposite(TreeNode *root, int num) {
        unsigned int ret{};
        TreeNode *crt{root};
        for (int i{30}; i >= 0; --i) {
            int crtBit{(num >> i) & 1};
            if (crtBit) {
                if (!crt->right) {
                    crt = crt->left;
                } else {
                    ret |= 1 << i;
                    crt = crt->right;
                }

            } else {
                if (crt->left) {
                    crt = crt->left;
                    ret |= 1 << i;
                } else {
                    crt = crt->right;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{3,10,5,25,2,8};
    int result = solution.findMaximumXOR(nums);
    cout << result;
    return 0;
}
