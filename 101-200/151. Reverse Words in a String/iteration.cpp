#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        int crtIdx{size - 1};
        string ret{""};
        while (crtIdx >= 0) {
            while (crtIdx >= 0 && s[crtIdx] == ' ') --crtIdx;
            if (crtIdx == -1) break;
            if (ret.size()) ret += " ";
            int next{crtIdx - 1};
            while (next >= 0 && s[next] != ' ') --next;
            ret += s.substr(next + 1, crtIdx - next);
            crtIdx = next;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    string result = solution.reverseWords("a good   example");
    cout << result;
    return 0;
}
