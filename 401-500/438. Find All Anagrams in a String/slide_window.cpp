#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        char elementNum{0};
        int i{0}, j{-1};
        vector<int> res;
        vector<int> countMap(26);
        for (char &ch: p) {
            if (++countMap[ch - 'a'] == 1) {
                ++elementNum;
                countMap[ch - 'a'] = 2;
            }
        }
        char flag{elementNum};
        vector<int> sw{countMap};

        while (j + 1 < s.size()) {
            while (j + 1 < s.size() && j + 1 != i + p.size()) {
                int &iter = sw[s[++j] - 'a'];
                if (iter != 0) {
                    if (iter == 1) {
                        while (s[i++] != s[j]) if (++sw[s[i - 1] - 'a'] == 2) ++flag;
                        continue;
                    } else if (--iter == 1) --flag;
                } else {
                    flag = elementNum;
                    for (int idx = 0; idx < 26; ++idx) sw[idx] = countMap[idx];
                    i = j + 1;
                }
            }
            if (!flag) res.emplace_back(i);
            if (i + 1 < s.size() && ++sw[s[i++] - 'a'] == 2) ++flag;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> result = solution.findAnagrams("cbaebabacd", "abc");
    return 0;
}