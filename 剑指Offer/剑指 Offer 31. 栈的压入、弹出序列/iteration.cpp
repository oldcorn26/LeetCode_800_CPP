#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int popIdx{};
        stack<int> s;
        for (int i{}; i < pushed.size(); ++i) {
            if (pushed[i] == popped[popIdx])
                popIdx++;
            else if (!s.empty() && s.top() == popped[popIdx]) {
                s.pop();
                popIdx++, i--;
            }
            else
                s.emplace(pushed[i]);
        }
        for (; popIdx < popped.size(); ++popIdx) {
            if (s.top() != popped[popIdx]) return false;
            s.pop();
        }
        return true;
    }
};

int main() {
    Solution solution;
    return 0;
}
