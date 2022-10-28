#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.size();
        if (sLen < t.size()) return "";

        int i = 0, j = -1;
        int headIdx, minLen = INT32_MAX;
        unordered_map<char, int> map;
        for (char &c : t) ++map[c];
        int uncheckedNum = map.size();

        while (uncheckedNum) {
            while (uncheckedNum && j + 1 < sLen) {
                if (map.find(s[++j]) != map.end() && !--map[s[j]]) --uncheckedNum;
            }
            while (i <= j) {
                if (map.find(s[i]) != map.end())
                    if (map[s[i]]) ++map[s[i]];
                    else break;
                ++i;
            }
            if (!uncheckedNum) {if (minLen > j - i + 1) {headIdx = i; minLen = j - i + 1;}}
            else if (minLen == INT32_MAX) return "";
            else break;

            if (++i <= j) {++map[s[i - 1]]; ++uncheckedNum;}
        }

        return s.substr(headIdx, minLen);
    }
};

int main() {
    Solution solution;
    string s = "a";
    string t = "aa";
    string result = solution.minWindow(s, t);
    cout << result;
    return 0;
}