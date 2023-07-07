#include <iostream>

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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *newHead{reverseList(head->next)};
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    head = solution.reverseList(head);
    return 0;
}
