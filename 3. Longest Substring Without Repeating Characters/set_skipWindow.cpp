#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int totalNum = s.length();
        int max = 0;
        int tail = -1;
        unordered_set<char> set1;

        for (int i = 0; i < totalNum; ++i) {

            if (i != 0) {
                set1.erase(s[i - 1]);
            }

            while (tail + 1 < totalNum && !set1.count(s[tail + 1])) {
                set1.insert(s[tail + 1]);
                ++tail;
            }

            max = (max >= set1.size()) ? max : set1.size();
        }
        return max;
    }
};

int main() {
    string s = "abcd";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
