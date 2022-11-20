#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack1;

        if (s.length() % 2) return false;

        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') stack1.push(c);
            else if (stack1.empty()) return false;
            else if ((c == ')' && stack1.top() == '(') ||
                     (c == ']' && stack1.top() == '[') ||
                     (c == '}' && stack1.top() == '{')) {
                stack1.pop();
            } else return false;
        }
        return stack1.empty();
    }
};

int main() {
    Solution solution;
    string s = ")}";
    cout << solution.isValid(s);
    return 0;
}
