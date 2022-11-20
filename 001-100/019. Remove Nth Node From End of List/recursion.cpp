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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr) {
            return new ListNode(101);
        } else {
            ListNode *temp = removeNthFromEnd(head->next, n);

            if (!temp) {
                head->next = temp;
                return head;
            }
            if (temp->val == 100 + n) {
                ListNode *successor = head->next;
                delete head;
                delete temp;
                return successor;
            } else if (temp->val > 100) {
                int val = temp->val;
                delete temp;
                return new ListNode(val + 1);
            } else {
                head->next = temp;
                return head;
            }
        }
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *result = solution.removeNthFromEnd(head, 5);
    return 0;
}
