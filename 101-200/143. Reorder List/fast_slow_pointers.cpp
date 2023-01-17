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
    void reorderList(ListNode* head) {

        ListNode *fastNode{head->next}, *slowNode{head};

        if (!fastNode || !fastNode->next) return;
        while (fastNode->next) {
            fastNode = fastNode->next->next ? fastNode->next->next : fastNode->next;
            slowNode = slowNode->next;
        }
        reverseList(slowNode->next);
        slowNode->next = nullptr;
        mergeTwoLists(head, fastNode);
    }

    void reverseList(ListNode *oldHead) {

        ListNode *pre{oldHead}, *crt{oldHead->next};
        oldHead->next = nullptr;

        while (crt) {
            ListNode *temp{crt->next};
            crt->next = pre;
            pre = crt;
            crt = temp;
        }
    }

    void mergeTwoLists(ListNode *l1, ListNode *l2) {

        ListNode *temp1{l1}, *temp2{l2};

        while (l2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
            l1->next = l2;
            l2->next = temp1;
            l1 = temp1;
            l2 = temp2;
        }
    }
};

int main() {
    Solution solution;
    ListNode *head{new ListNode(1, new ListNode(2, new ListNode(3)))};
    solution.reorderList(head);
    return 0;
}
