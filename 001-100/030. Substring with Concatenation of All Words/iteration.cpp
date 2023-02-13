#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int len;
    vector<int> ret;
    unordered_map<int, int> strMatch;
public:
    vector<int> findSubstring(string s, vector<string> &words) {

        int sSize = s.size(), codeIdx{0};
        int totalNum = words.size() * words[0].size();
        unordered_map<string, int> wordEncode;
        vector<int> state;

        len = words[0].size();
        for (int i{0}; i < words.size(); ++i) {
            auto iter = wordEncode.find(words[i]);
            if (iter == wordEncode.end()) {
                state.emplace_back(1);
                wordEncode[words[i]] = codeIdx++;
            } else ++state[iter->second];
        }
        for (int i{0}; i + len <= sSize; ++i) {
            string &&temp{s.substr(i, len)};
            auto iter = wordEncode.find(temp);
            if (iter != wordEncode.end()) strMatch[i] = iter->second;
        }
        for (int i{0}; i < sSize && i + totalNum <= sSize; ++i) {
            if (dfs(i, state, 0)) ret.emplace_back(i);
        }
        
        return ret;
    }

    bool dfs(int crtIdx, vector<int> &state, int stlNum) {
        if (stlNum == state.size()) return true;
        auto iter = strMatch.find(crtIdx);
        if (iter == strMatch.end() || state[iter->second] == 0) return false;
        if (--state[iter->second] == 0) ++stlNum;
        bool retBool{dfs(crtIdx + len, state, stlNum)};
        ++state[iter->second];
        return retBool;
    }
};

int main() {
    Solution solution;
    vector<string> words{"foo", "bar"};
    vector<int> result = solution.findSubstring("barfoothefoobarman", words);
    return 0;
}
