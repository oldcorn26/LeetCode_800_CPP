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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }

    TreeNode *sortedArrayToBSTHelper(vector<int> &nums, int sta, int end) {

        int &&mid{(sta + end) / 2};
        TreeNode *ret{new TreeNode(nums[mid])};
        if (sta <= mid - 1) ret->left = sortedArrayToBSTHelper(nums, sta, mid - 1);
        if (mid + 1 <= end) ret->right = sortedArrayToBSTHelper(nums, mid + 1, end);

        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{-10,-3,0,5,9};
    TreeNode *result = solution.sortedArrayToBST(nums);
    return 0;
}
