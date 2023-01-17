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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode *ret{head};


        while (ret && ret->val == val) {
            ret = ret->next;
        }
        if (!ret) return nullptr;
        ret->next = removeElements(ret->next, val);
        return ret;
    }
};

int main() {
    Solution solution;
    ListNode *head{new ListNode(1, new ListNode(2, new ListNode(3)))};
    solution.removeElements(head, 3);
    return 0;
}
