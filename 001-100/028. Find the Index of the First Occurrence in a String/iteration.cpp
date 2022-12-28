#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i{0}; i < haystack.size(); ++i) {
            if (haystack[i] == needle[0]) {
                string &&temp = haystack.substr(i, needle.size());
                if (temp == needle) return i;
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