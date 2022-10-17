#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> stack1;

        stack1.push(-1);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack1.push(i);
            } else if (stack1.size() == 1){
                stack1.pop();
                stack1.push(i);
            } else {
                stack1.pop();
                maxLen = i - stack1.top() > maxLen ? i - stack1.top() : maxLen;
            }
        }

        return maxLen;
    }
};

int main(){
    Solution solution;
    string s = ")()())";
    cout << solution.longestValidParentheses(s);
    return 0;
}
