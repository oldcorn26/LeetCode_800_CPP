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
    ListNode *ctr;
    char flag = 0;
public:
    bool isPalindrome(ListNode* head) {
        ctr = head;

        return checkIfPalindrome(head) == -1;
    }

    int checkIfPalindrome(ListNode *head) {
        if (!head) return -1;

        int &&temp = checkIfPalindrome(head->next);
        if (temp == -1 && (head == ctr || head->next == ctr)) flag = 1;
        if (flag || (temp == -1 && head->val == ctr->val)) {
            ctr = ctr->next;
            return -1;
        } else return -2;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1, new ListNode(2));
    bool result = solution.isPalindrome(head);
    cout << result;
    return 0;
}
