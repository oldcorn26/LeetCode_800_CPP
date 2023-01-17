#include <iostream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        return calculateHelper(s, 0, s.size() - 1);
    }

    int calculateHelper(string &s, int sta, int end) {

        int flag{1};
        long ret{0};

        for (int i{sta}; i <= end; ++i) {
            if (s[i] == ' ') continue;
            else if (s[i] == '-') flag = -1;
            else if (s[i] == '+') flag = 1;
            else if (s[i] >= '0' && s[i] <= '9') {
                int tempIdx{i + 1};
                long num{s[i] - '0'};
                while (s[tempIdx] >= '0' && s[tempIdx] <= '9') {
                    num = num * 10 + s[tempIdx] - '0';
                    ++tempIdx;
                }
                ret += flag * num;
                i = tempIdx - 1;
            } else if (s[i] == '(') {
                int tempIdx{i}, tempCounter{1};
                while (tempCounter != 0) {
                    ++tempIdx;
                    if (s[tempIdx] == '(') ++tempCounter;
                    else if (s[tempIdx] == ')') --tempCounter;
                }
                ret += flag * calculateHelper(s, i + 1, tempIdx - 1);
                i = tempIdx;
            }
        }

        return ret;
    }
};

int main() {
    Solution solution;
    int result = solution.calculate("(1+(4+5+2)-3)+(6+8)");
    cout << result;
    return 0;
}
