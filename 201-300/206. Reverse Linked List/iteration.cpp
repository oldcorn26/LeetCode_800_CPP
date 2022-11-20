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
        if (!head) return nullptr;
        ListNode *pre = nullptr, *crt = head, *nxt = head->next;

        while(crt) {
            crt->next = pre;
            pre = crt;
            crt = nxt;
            if (nxt) nxt = nxt->next;
        }

        return pre;
    }
};

int main() {
    Solution solution;
    return 0;
}
