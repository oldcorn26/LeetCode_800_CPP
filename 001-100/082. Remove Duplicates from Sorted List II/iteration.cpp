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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        int pre{-200};
        ListNode *resHead{new ListNode(0)};
        ListNode *crt{head}, *resTail{resHead};
        while (crt->next) {
            if (crt->val != pre && crt->next->val != crt->val) {
                resTail->next = crt;
                resTail = crt;
            }
            pre = crt->val;
            crt = crt->next;
        }
        resTail->next = crt->val == pre ? nullptr : crt;
        return resHead->next;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4)))));
    ListNode *result = solution.deleteDuplicates(head);
    return 0;
}