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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k) return head;
        int len{1};
        ListNode *tail{head}, *newTail{head};
        while (tail->next) {
            tail = tail->next;
            ++len;
        }
        k = len - k % len - 1;
        while (k) {
            newTail = newTail->next;
            --k;
        }
        tail->next = head;
        head = newTail->next;
        newTail->next = nullptr;
        return head;
    }
};

int main() {
    Solution solution;
    return 0;
}