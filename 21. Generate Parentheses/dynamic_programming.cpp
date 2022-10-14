#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        else if (n == 1) return vector<string>{"()"};
        else if (n == 2) return vector<string>{"(())", "()()"};
        else if (n == 3) return vector<string>{"((()))", "(())()", "()(())", "(()())", "()()()"};
        else if (n == 4) return vector<string>{"(((())))", "((()()))", "((())())", "((()))()", "(()(()))",
                                               "(()()())", "(()())()", "(())(())", "(())()()", "()((()))",
                                               "()(()())", "()(())()", "()()(())", "()()()()"};

        int flag = 0;
        vector<string> &&temp = generateParenthesis(n - 1);
        vector<string> res(temp.size() * 2);
        for (const string &s: temp) {
            res[flag++] = "()" + s;
            res[flag++] = '(' + s + ')';
        }

        for (int i = 1; i < n - 1; i++) {
            vector<string> &&left = generateParenthesis(i);
            vector<string> &&right = generateParenthesis(n - i - 1);
            res.resize(res.size() + left.size() * right.size());
            for (const string &s1: left) {
                for (const string &s2: right) {
                    res[flag++] = '(' + s1 + ')' + s2;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<string> &&res = solution.generateParenthesis(5);
    cout << vector<string>{}.size();
    return 0;
}