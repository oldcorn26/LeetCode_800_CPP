#include <iostream>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int size = s.size();
        int maxLen{1}, retIdx{0};
        for (int i{size - 1}; i > 0; --i) {
            if (s[0] == s[i] && checkPalindrome(s, 0, i)) {
                maxLen = i + 1;
                break;
            }
        }
        char *ret{static_cast<char*>(malloc(sizeof(char) * (2 * size - maxLen + 1)))};
        for (int i{size - 1}; i >= maxLen; --i) {
            ret[retIdx++] = s[i];
        }
        for (int i{0}; i < size; ++i) {
            ret[retIdx++] = s[i];
        }
        return string(&ret[0], &ret[retIdx]);
    }

    bool checkPalindrome(string &s, int left, int right) {
        if (left > right || s[left] != s[right]) return false;
        else if (right - left <= 1) return true;
        else return checkPalindrome(s, left + 1, right - 1);
    }
};

int main() {
    Solution solution;
    string result = solution.shortestPalindrome("aacecaaa");
    cout << result;
    return 0;
}
