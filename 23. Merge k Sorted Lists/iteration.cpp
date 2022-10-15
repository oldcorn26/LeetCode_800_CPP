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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        unordered_map<int, int> calMap;
        set<int> set1;
        ListNode *res = nullptr, *flag = nullptr;

        for (ListNode *l : lists) {
            while (l != nullptr) {
                if (++calMap[l->val] == 1) set1.insert(l->val);
                l = l->next;
            }
        }

        for (int i : set1) {
            for (int j = 0; j < calMap[i]; j++) {
                if (!flag) {
                    res = flag = new ListNode(i);
                } else {
                    flag->next = new ListNode(i);
                    flag = flag->next;
                }
            }
        }

        return res;
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