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
    ListNode* reverseKGroup(ListNode* head, int k) {

        int count{1};
        ListNode *tail{head};

        while (tail->next && count < k) {
            ++count;
            tail = tail->next;
        }
        if (count < k || k == 1) return head;

        ListNode *nextHead{tail->next};
        ListNode *ret{reverseListNode(head, tail)};
        head->next = nextHead ? reverseKGroup(nextHead, k) : nullptr;

        return ret;
    }

    ListNode *reverseListNode(ListNode *head, ListNode *tail) {
        ListNode *pre{head}, *crt{head->next};
        while (crt != tail) {
            ListNode *temp{crt->next};
            crt->next = pre;
            pre = crt;
            crt = temp;
        }
        crt->next = pre;
        return crt;
    }
};

int main() {
    Solution solution;
    ListNode *head{new ListNode(1, new ListNode(2))};
    ListNode *result = solution.reverseKGroup(head, 2);
    return 0;
}
