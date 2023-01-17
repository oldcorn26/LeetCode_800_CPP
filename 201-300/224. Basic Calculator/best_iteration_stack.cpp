#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {

        stack<int> ops;
        ops.push(1);
        int flag{1}, ret{0};
        int size = s.length();

        for (int i{0}; i < size; ++i) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] == '+') {
                flag = ops.top();
            } else if (s[i] == '-') {
                flag = -ops.top();
            } else if (s[i] == '(') {
                ops.push(flag);
            } else if (s[i] == ')') {
                ops.pop();
            } else {
                long num{0};
                while (i < size && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    ++i;
                }
                --i;
                ret += flag * num;
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    int result = solution.calculate(" 2-1 + 2 ");
    cout << result;
    return 0;
}
