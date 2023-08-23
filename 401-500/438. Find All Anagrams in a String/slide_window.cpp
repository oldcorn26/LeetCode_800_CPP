#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }
        int validNum{}, pNum{};
        vector<int> pMap(26), sMap(26);
        vector<int> ret;
        for (char ch: p) {
            if (++pMap[ch - 'a'] == 1) {
                pNum++;
            }
        }
        for (int i{}; i < p.size(); ++i) {
            int sIdx = s[i] - 'a';
            if (++sMap[sIdx] == pMap[sIdx]) {
                validNum++;
            }
        }
        if (validNum == pNum) {
            ret.emplace_back(0);
        }
        for (int i = p.size(); i < s.size(); ++i) {
            int rIdx = s[i] - 'a';
            int lIdx = s[i-p.size()] - 'a';
            if (++sMap[rIdx] == pMap[rIdx]) {
                validNum++;
            }
            if (sMap[lIdx]-- == pMap[lIdx]) {
                validNum--;
            }
            if (validNum == pNum) {
                ret.emplace_back(i - p.size() + 1);
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> result = solution.findAnagrams("cbaebabacd", "abc");
    return 0;
}