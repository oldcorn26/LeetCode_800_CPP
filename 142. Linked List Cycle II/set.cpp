#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;

        unordered_set<ListNode*> set;
        while (head->next) {
            if (set.find(head) == set.end()) set.insert(head);
            else return head;
            head = head->next;
        }

        return nullptr;
    }
};

int main() {
    Solution solution;
    return 0;
}
