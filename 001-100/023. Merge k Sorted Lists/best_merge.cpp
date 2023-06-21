#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return merge(lists, 0, lists.size()-1);
    }

    ListNode *merge(vector<ListNode *> &lists, int sta, int end) {
        if (sta == end)
            return lists[sta];
        else if (sta > end)
            return nullptr;
        int mid{(sta + end) / 2};
        return mergeTwoLists(merge(lists, sta, mid), merge(lists, mid+1, end));
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head{new ListNode()};
        ListNode *crt{head};
        while (l1 && l2) {
            ListNode *&small{l1->val < l2->val ? l1 : l2};
            crt->next = small;
            crt = crt->next;
            small = small->next;
        }
        crt->next = l1 ? l1 : l2;
        return head->next;
    }
};

int main() {
    Solution solution;
    ListNode *list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *list3 = new ListNode(2, new ListNode(6));
    vector<ListNode *> lists{list1, list2, list3};
    ListNode *result = solution.mergeKLists(lists);
    return 0;
}