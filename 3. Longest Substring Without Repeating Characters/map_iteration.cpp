#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        map<char, int> set1;

        for (int i = 0; i < s.length(); i++) {
            if (!set1.count(s[i])) {
                set1.insert(pair<char, int>(s[i], i));
            } else {
                max = (max >= set1.size()) ? max : set1.size();
                i = set1[s[i]];
                set1.clear();
            }
        }
        max = (max >= set1.size()) ? max : set1.size();
        return max;
    }
};

int main() {
    string s = "abcabcbb";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
