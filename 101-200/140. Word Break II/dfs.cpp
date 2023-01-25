#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<string> ret;
    unordered_map<string, int> wordMap;
    vector<string> *pWordDict;
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        vector<int> settledIdx(20);
        pWordDict = &wordDict;
        for (int i{0}; i < wordDict.size(); ++i) {
            wordMap.emplace(wordDict[i], i);
        }
        wordBreakHelper(s, 0, settledIdx, 0);
        return ret;
    }

    void wordBreakHelper(string &s, int sIdx, vector<int> &stl, int vIdx) {

        if (sIdx == s.size()) {
            pushAnswer(stl, vIdx);
            return;
        }

        int restLen = s.size() - sIdx;

        for (int i{1}; i <= restLen; ++i) {
            auto iter = wordMap.find(s.substr(sIdx, i));
            if (iter != wordMap.end()) {
                stl[vIdx] = iter->second;
                wordBreakHelper(s, sIdx + i, stl, vIdx + 1);
            }
        }
    }

    void pushAnswer(vector<int> &stl, int vIdx) {
        int chIdx{0};
        char str[40];
        vector<string> &wordDict{*pWordDict};
        for (int i{0}; i < vIdx; ++i) {
            string &temp{wordDict[stl[i]]};
            for (char &ch: temp) str[chIdx++] = ch;
            str[chIdx++] = ' ';
        }
        ret.emplace_back(string(&str[0], &str[chIdx - 1]));
    }
};

int main() {
    Solution solution;
    vector<string> wordDict{"apple","pen","applepen","pine","pineapple"};
    vector<string> result = solution.wordBreak("pineapplepenapple", wordDict);
    return 0;
}
