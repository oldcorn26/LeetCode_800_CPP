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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head;

        if (!list1) return list2;
        else if (!list2) return list1;
        else if (list1->val <= list2->val) {
            head = list1;
            head->next = mergeTwoLists(list1->next, list2);
        } else {
            head = list2;
            head->next = mergeTwoLists(list1, list2->next);
        }

        return head;
    }
};

int main() {
    Solution solution;
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *result = solution.mergeTwoLists(list1, list2);
    return 0;
}
