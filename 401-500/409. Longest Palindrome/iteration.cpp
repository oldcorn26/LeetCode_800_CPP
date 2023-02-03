#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {

        int oddFlag{0}, oddSum{0}, evenSum{0};
        vector<int> letter(52);

        for (char &ch: s) {
            if (ch >= 'a') ++letter[ch - 'a'];
            else ++letter[ch - 'A' + 26];
        }
        for (int &i: letter) {
            if (i % 2) {
                oddSum += i / 2 * 2;
                oddFlag = 1;
            } else evenSum += i;
        }

        return oddSum + evenSum + oddFlag;
    }
};

int main() {
    Solution solution;
    int result = solution.longestPalindrome("abccccdd");
    cout << result;
    return 0;
}
