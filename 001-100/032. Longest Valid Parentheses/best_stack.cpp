#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ret{};
        stack<int> ss{{-1}};
        for (int i{}; i < s.size(); ++i) {
            if (s[i] == '(') {
                ss.emplace(i);
            } else if (ss.size() == 1) {
                ss.pop();
                ss.emplace(i);
            } else {
                ss.pop();
                ret = max(ret, i - ss.top());
            }
        }
        return ret;
    }
};

int main(){
    Solution solution;
    string s = ")()())";
    cout << solution.longestValidParentheses(s);
    return 0;
}
