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
    ListNode *partition(ListNode *head, int x) {
        ListNode *smallHead{new ListNode(0)}, *smallTail{smallHead};
        ListNode *largeHead{new ListNode(0)}, *largeTail{largeHead};
        while (head) {
            if (head->val < x) {
                smallTail->next = head;
                smallTail = head;
            } else {
                largeTail->next = head;
                largeTail = head;
            }
            head = head->next;
        }
        largeTail->next = nullptr;
        smallTail->next = largeHead->next;
        return smallHead->next;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4)))));
    ListNode *result = solution.partition(head, 2);
    return 0;
}