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
        int length = 1;
        ListNode *temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
            length++;
        }

        temp = head;
        if (n == length) {
            head = head->next;
            delete temp;
            return head;
        }

        for (int i = 0; i < length - n - 1; ++i) {
            temp = temp->next;
        }

        ListNode *temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
        return head;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *result = solution.removeNthFromEnd(head, 2);
    return 0;
}
