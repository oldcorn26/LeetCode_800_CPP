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
        int more = 0;
        ListNode *iterA = headA, *iterB = headB;

        while (iterA->next && iterB->next) {
            iterA = iterA->next;
            iterB = iterB->next;
        }

        if (iterA->next) {
            while (iterA->next) {
                iterA = iterA->next;
                ++more;
            }
            if (iterA != iterB) return nullptr;
            iterA = headA, iterB = headB;
        } else {
            while (iterB->next) {
                iterB = iterB->next;
                ++more;
            }
            if (iterA != iterB) return nullptr;
            iterA = headB, iterB = headA;
        }

        while (more) {
            iterA = iterA->next;
            --more;
        }

        while (iterA != iterB) {
            iterA = iterA->next;
            iterB = iterB->next;
        }
        return iterA;
    }
};

int main() {
    Solution solution;
    return 0;
}
