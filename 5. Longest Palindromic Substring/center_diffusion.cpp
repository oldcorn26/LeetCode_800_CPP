#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = 1;
        int start = 0;
        int flag;

        for (int i = 1; i < s.length(); ++i) {
            flag = 0;
            while (checkIfSame(s, i - flag - 1, i + flag + 1)) {
                ++flag;
            }

            if (length < flag * 2 + 1) {
                start = i - flag;
                length = flag * 2 + 1;
            }

            flag = 0;
            while (checkIfSame(s, i - flag - 1, i + flag)){
                ++flag;
            }

            if (length < flag * 2) {
                start = i - flag;
                length = flag * 2;
            }
        }

        string result = s.substr(start, length);
        return result;
    }

    static bool checkIfSame(string &s, int &&flag1, int &&flag2) {
        if (flag1 < 0 || flag2 >= s.length()) {
            return false;
        } else {
            return s[flag1] == s[flag2];
        }
    }
};

int main() {
    string s = "length";
    Solution solution;
    cout << solution.longestPalindrome(s);
    return 0;
}
