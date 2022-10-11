#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        set<char> set1;

        for (int i = 0; i < s.length(); i++) {
            if (!set1.count(s[i])) {
                set1.insert(s[i]);
            } else {
                int j = i - 1;
                max = (max >= set1.size()) ? max : set1.size();
                set1.clear();
                while (s[j] != s[i]) {
                    j--;
                }
                i = j;
            }
        }
        max = (max >= set1.size()) ? max : set1.size();
        return max;
    }
};

int main() {
    string s = "abcd";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
