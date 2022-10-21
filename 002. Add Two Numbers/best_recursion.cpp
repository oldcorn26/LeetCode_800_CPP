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
        ListNode *l;

        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        } else if (l1 == nullptr) {

            if (l2->val > 9) {
                l = new ListNode(l2->val - 10);

                if (l2->next == nullptr) {
                    l2->next = new ListNode(1);
                } else {
                    l2->next->val++;
                }

                l->next = addTwoNumbers(nullptr, l2->next);
            } else {
                l = new ListNode(l2->val);
                l->next = addTwoNumbers(nullptr, l2->next);
            }

        } else if (l2 == nullptr) {

            if (l1->val > 9) {
                l = new ListNode(l1->val - 10);

                if (l1->next == nullptr) {
                    l1->next = new ListNode(1);
                } else {
                    l1->next->val++;
                }
                l->next = addTwoNumbers(l1->next, nullptr);
            } else {
                l = new ListNode(l1->val);
                l->next = addTwoNumbers(l1->next, nullptr);
            }

        } else {
            int temp = (l1->val + l2->val) / 10;
            l = new ListNode((l1->val + l2->val) - temp * 10);

            if (temp > 0) {
                if (l1->next == nullptr) {
                    l1->next = new ListNode(temp);
                } else {
                    l1->next->val += temp;
                }
            }

            l->next = addTwoNumbers(l1->next, l2->next);
        }
        return l;
    }
};

int main() {
    ListNode *l1 = new ListNode(9, new ListNode(9));
    ListNode *l2 = new ListNode(9);
    Solution solution;

    ListNode *result = solution.addTwoNumbers(l1, l2);
    return 0;
}
