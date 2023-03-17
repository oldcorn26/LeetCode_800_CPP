#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int idx{}, maxNum{};
        unordered_set<char> um;
        while (idx < size) {
            while (idx < size && um.find(s[idx]) == um.end()) {
                um.emplace(s[idx]);
                idx++;
            }
            maxNum = max(maxNum, static_cast<int>(um.size()));
            if (idx == size) break;
            for (int i = idx - um.size(); s[i] != s[idx]; ++i) {
                um.erase(s[i]);
            }
            idx++;
        }
        return maxNum;
    }
};

int main() {
    Solution solution;
    return 0;
}
