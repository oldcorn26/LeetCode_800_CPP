#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') left++;
            else right++;

            if (left < right) left = right = 0;
            else if (left == right) maxLen = left + right > maxLen ? left + right : maxLen;
        }

        left = right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;

            if (right < left) left = right = 0;
            else if (left == right) maxLen = left + right > maxLen ? left + right : maxLen;
        }
        return maxLen;
    }
};

int main(){
    Solution solution;
    string s = "(()))())(";
    cout << solution.longestValidParentheses(s);
    return 0;
}
