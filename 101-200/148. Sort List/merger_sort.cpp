#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int num = 0;
        ListNode *temp = head;
        while (temp) {temp = temp->next; ++num;}

        return sortListHelper(head, move(num));
    }

    ListNode* sortListHelper(ListNode* head, int &&num) {
        if (num < 2) return head;
        else if (num == 2) {
            if (head->val > head->next->val) {
                int temp = head->val;
                head->val = head->next->val;
                head->next->val = temp;
            }
            return head;
        }

        int &&leftNum = num - num / 2, &&rightNum = num / 2, leftFlag = 1, rightFlag = 0;
        ListNode *rightHead = head, *leftHead, *bottom;
        for (int i = 0; i < leftNum; ++i) rightHead = rightHead->next;
        leftHead = sortListHelper(head, move(leftNum));
        rightHead = sortListHelper(rightHead, num / 2);

        if (leftHead->val > rightHead->val) {
            head = rightHead; leftNum = rightNum;
            rightHead = leftHead; rightNum = num - leftNum;
        } else head = leftHead;
        leftHead = head->next; bottom = head;

        while(leftFlag < leftNum || rightFlag < rightNum) {
            if ((rightFlag == rightNum) || (leftFlag < leftNum && leftHead->val <= rightHead->val)) {
                bottom->next = leftHead; bottom = leftHead;
                leftHead = leftHead->next; ++leftFlag;
            } else {
                bottom->next = rightHead; bottom = rightHead;
                rightHead = rightHead->next; ++rightFlag;
            }
        }
        bottom->next = nullptr;

        return head;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(-1, new ListNode(5, new ListNode(3, new ListNode(4, new ListNode(0)))));
    head = solution.sortList(head);
    return 0;
}
