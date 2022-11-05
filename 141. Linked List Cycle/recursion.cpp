#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;

        if (head->val < INT32_MAX) {
            head->val = INT32_MAX;
            return hasCycle(head->next);
        } else return true;
    }
};
