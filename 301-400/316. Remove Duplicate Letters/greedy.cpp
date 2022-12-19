#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> letter(26), exist(26);
        stack<char> res;
        for (char &ch: s) {
            ++letter[ch - 'a'];
        }
        for (char &ch: s) {
            if (exist[ch - 'a']) {
                --letter[ch - 'a'];
                continue;
            }
            while (!res.empty() && (res.top() >= ch && letter[res.top() - 'a'])) {
                --exist[res.top() - 'a'];
                res.pop();
            }
            --letter[ch - 'a'];
            ++exist[ch - 'a'];
            res.emplace(ch);
        }
        char resStr[res.size() + 1];
        char *end{&resStr[res.size()]};
        for (int i = res.size() - 1; i >= 0; --i) {
            resStr[i] = res.top();
            res.pop();
        }
        return string(&resStr[0], end);
    }
};

int main() {
    Solution solution;
    string result = solution.removeDuplicateLetters("bbcaac");
    cout << result;
    return 0;
}