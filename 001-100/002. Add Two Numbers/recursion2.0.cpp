#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return helper(l1, l2, 0);
    }

    ListNode *helper(ListNode *l1, ListNode *l2, int carr) {
        if (!l1 && !l2 && !carr)
            return nullptr;
        int n1{l1 ? l1->val : 0};
        int n2{l2 ? l2->val : 0};
        ListNode *ret{new ListNode((n1 + n2 + carr) % 10)};
        ret->next = helper(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, (n1 + n2 + carr) / 10);
        return ret;
    }
};

int main() {
    ListNode *l1 = new ListNode(9, new ListNode(9));
    ListNode *l2 = new ListNode(9);
    Solution solution;

    ListNode *result = solution.addTwoNumbers(l1, l2);
    return 0;
}
