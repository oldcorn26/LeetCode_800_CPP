#include <iostream>

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

        int tailIdx{-1};
        ListNode *counter{head};

        while (counter) {
            ++tailIdx;
            counter = counter->next;
        }

        return buildBST(head, 0, tailIdx);
    }

    TreeNode *buildBST(ListNode *&head, int sta, int end) {

        int &&mid{(sta + end) / 2};
        TreeNode *ret{new TreeNode()};

        if (sta <= mid - 1) ret->left = buildBST(head, sta, mid - 1);
        ret->val = head->val;
        head = head->next;
        if (mid + 1 <= end) ret->right = buildBST(head, mid + 1, end);

        return ret;
    }
};

int main() {
    Solution solution;
    ListNode *head{nullptr};
    TreeNode *result = solution.sortedListToBST(head);
    return 0;
}
