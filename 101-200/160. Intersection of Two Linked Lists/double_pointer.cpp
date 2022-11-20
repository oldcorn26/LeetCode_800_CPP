#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *iterA = headA, *iterB = headB;

        while (iterA != iterB) {
            iterA = iterA ? iterA->next : headB;
            iterB = iterB ? iterB->next : headA;
        }

        return iterA;
    }
};

int main() {
    Solution solution;
    return 0;
}
