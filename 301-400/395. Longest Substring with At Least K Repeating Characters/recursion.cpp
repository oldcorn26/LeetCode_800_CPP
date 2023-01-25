#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {

        if (s.size() < k) return 0;

        int size = s.size();
        int left{-1}, right{-1}, ret{0};
        vector<int> counter(26);
        unordered_set<char> invalid;

        for (char &ch: s) ++counter[ch - 'a'];
        for (int i{0}; i < 26; ++i) {
            if (counter[i] && counter[i] < k) invalid.emplace('a' + i);
        }
        if (invalid.empty()) return s.size();
        while (right < size) {
            while (left + 1 < size && invalid.find(s[++left]) != invalid.end());
            right = left;
            while (++right < size && invalid.find(s[right]) == invalid.end());
            int temp{longestSubstring(string(&s[left], &s[right]), k)};
            ret = temp > ret ? temp : ret;
            left = right;
        }

        return ret;
    }
};

int main() {
    Solution solution;
    int result = solution.longestSubstring("ababbc", 2);
    cout << result;
    return 0;
}
