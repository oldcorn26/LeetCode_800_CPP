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
    ListNode *crtHead;
    bool state{};
    bool ret{true};
public:
    bool isPalindrome(ListNode* head) {
        crtHead = head;
        check(head);
        return ret;
    }

    void check(ListNode *tail) {
        if (!state) {
            if (!tail) {
                state = true;
                return;
            }
            check(tail->next);
        }
        if (crtHead->val != tail->val)
            ret = false;
        crtHead = crtHead->next;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1, new ListNode(2));
    bool result = solution.isPalindrome(head);
    cout << result;
    return 0;
}
