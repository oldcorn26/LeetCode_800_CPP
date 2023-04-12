#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> nextLargerNodes(ListNode* head) {
        int num{}, idx{};
        ListNode *crt{head};
        while (crt) {
            num++;
            crt = crt->next;
        }
        vector<int> ret(num);
        stack<pair<int, int>> mono{{{INT32_MAX, INT32_MAX}}};
        crt = head;
        while (crt) {
            while (mono.top().first < crt->val) {
                ret[mono.top().second] = crt->val;
                mono.pop();
            }
            mono.emplace(crt->val, idx++);
            crt = crt->next;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    return 0;
}
