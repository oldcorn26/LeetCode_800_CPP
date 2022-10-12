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
        ListNode *min, *max, *head, *bottom;

        if (!list1) return list2;
        else if (!list2) return list1;

        min = head = bottom = list1->val <= list2->val ? list1 : list2;
        min = min->next;
        max = list1->val <= list2->val ? list2 : list1;

        while (min) {
            if (min->val > max->val) {
                bottom->next = max;
                max = min;
                min = bottom->next->next;
            } else {
                bottom->next = min;
                min = min->next;
            }
            bottom = bottom->next;
        }

        bottom->next = max;

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
