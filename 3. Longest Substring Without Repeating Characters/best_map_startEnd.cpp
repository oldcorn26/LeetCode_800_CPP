#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int start = 0;
        int end = -1;
        int charNum = s.length();
        unordered_map<char, int> set1;

        while (end + 1 < charNum) {
            if (set1.find(s[end + 1]) != set1.end() && set1[s[end + 1]] >= start) {
                start = set1[s[end + 1]] + 1;
            }

            set1[s[end + 1]] = end + 1;
            ++end;

            max = (max >= end - start + 1) ? max : end - start + 1;
        }

        return max;
    }
};

int main() {
    string s = "abcabcbb";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
