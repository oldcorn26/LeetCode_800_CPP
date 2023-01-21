#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {

        if (!head) return nullptr;

        int listNum{0}, idx{0};
        ListNode *counter{head};

        while (counter) {
            ++listNum;
            counter = counter->next;
        }
        vector<int> nums(listNum);
        while (head) {
            nums[idx++] = head->val;
            head = head->next;
        }

        return sortedArrayToBSTHelper(nums, 0, listNum - 1);
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
    ListNode *head{nullptr};
    TreeNode *result = solution.sortedListToBST(head);
    return 0;
}
