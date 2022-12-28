#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int next[needle.size()];
        next[0] = 0;
        for (int i{1}, prefixLen{0}; i < needle.size(); ++i) {
            while (prefixLen > 0 && needle[i] != needle[prefixLen]) {
                prefixLen = next[prefixLen - 1];
            }
            if (needle[i] == needle[prefixLen]) {
                ++prefixLen;
            }
            next[i] = prefixLen;
        }
        for (int i{0}, j{0}; i < haystack.size(); ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                ++j;
            }
            if (j == needle.size()) {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    int result = solution.strStr("leetcode", "leeto");
    cout << result;
    return 0;
}