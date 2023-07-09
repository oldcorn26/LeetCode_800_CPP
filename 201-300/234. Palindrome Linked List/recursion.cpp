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
private:
    ListNode *crtHead;
public:
    bool isPalindrome(ListNode* head) {
        crtHead = head;
        return check(head);
    }

    bool check(ListNode *head) {
        if (!head)
            return true;
        if (!check(head->next) || crtHead->val != head->val)
            return false;
        crtHead = crtHead->next;
        return true;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1, new ListNode(2));
    bool result = solution.isPalindrome(head);
    cout << result;
    return 0;
}
